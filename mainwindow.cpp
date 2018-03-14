#include "mainwindow.h"
#include "featurecontainer.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}

void MainWindow::setFeatures(FeatureContainerPtr container)
{

//    ui->scrollAreaWidgetContents->layout()->

    makeLayout(container,ui->scrollAreaWidgetContents);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makeFeatureWidget(const FeaturePtr &feature, QWidget* widget)
{
    FeatureInfoPtr info;
    feature->getInfo(info);

    if(info->dataType == FeatureType::Grope)
    {
//        qDebug()<<"Make FeatureWidget Grope";

        QGroupBox* box = new QGroupBox(widget);
        box->setTitle(getName(info));
        QFormLayout* formLayout = new QFormLayout(box);
        formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
//        formLayout->set
//        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
//        formLayout->setFormAlignment(Qt::AlignLeft | Qt::AlignTop);
        formLayout->setLabelAlignment(Qt::AlignRight);

        FeatureContainerPtr container;
        feature->getChildren(container);

        makeLayout(container,box);

        widget->layout()->addWidget(box);
        return ;
    }

    if(info->dataType == FeatureType::Int)
    {

//        qDebug()<<"Make FeatureWidget int";

        QFormLayout * layout = static_cast<QFormLayout*>(widget->layout());

        int size = layout->rowCount();
        qDebug()<<"children size"<<size;
        QLabel* label_3 = new QLabel(widget);
//        label_3->setAlignment(Qt::AlignLeft);
        label_3->setText(getName(info));
//        label_3->setMinimumWidth(100);
        layout->setWidget(size, QFormLayout::LabelRole, label_3);

        QSpinBox* spinBox_3 = new QSpinBox(widget);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        spinBox_3->setSizePolicy(sizePolicy);

        int value = 0;
        int64_t  max=0,min=0;

        feature->getValue(value);
        feature->getRange(min,max);
        spinBox_3->setRange(min,max);
        spinBox_3->setValue(value);
        layout->setWidget(size, QFormLayout::FieldRole, spinBox_3);


        std::shared_ptr<FeatureUpdater> updater = std::make_shared<FeatureUpdater>(feature,spinBox_3);
        connect(spinBox_3,SIGNAL(valueChanged(int)), updater.get() ,SLOT(valueChange(int)));
        _updaterVec.push_back(updater);

        return;
    }

    if(info->dataType == FeatureType::Bool)
    {

//        qDebug()<<"Make FeatureWidget booo";

        QFormLayout * layout = static_cast<QFormLayout*>(widget->layout());

        int size = layout->rowCount();
        qDebug()<<"children size"<<size;
        QLabel* label_3 = new QLabel(widget);
        label_3->setText(getName(info));
//        label_3->setMinimumWidth(100);
        layout->setWidget(size, QFormLayout::LabelRole, label_3);

        QCheckBox* cheackBox = new QCheckBox(widget);

        bool val = false;
        feature->getValue(val);
        cheackBox->setChecked(val);
        layout->setWidget(size, QFormLayout::FieldRole, cheackBox);

        std::shared_ptr<FeatureUpdater> updater = std::make_shared<FeatureUpdater>(feature,cheackBox);
        connect(cheackBox,SIGNAL(toggled(bool)), updater.get() ,SLOT(valueChange(bool)));
        _updaterVec.push_back(updater);

        return;
    }

    if(info->dataType == FeatureType::Enum)
    {


        QFormLayout * layout = static_cast<QFormLayout*>(widget->layout());

        int size = layout->rowCount();
        qDebug()<<"children size"<<size;
        QLabel* label_3 = new QLabel(widget);
        label_3->setText(getName(info));
//        label_3->setMinimumWidth(100);
        layout->setWidget(size, QFormLayout::LabelRole, label_3);

        QComboBox* combo = new QComboBox(widget);

        StringVec strVec ;
        IntVec intVec;
        feature->getValues(strVec);
        feature->getValues(intVec);

        size_t strSize = strVec.size();

        for(size_t i = 0;i < strSize ; i++)
        {

            combo->addItem(QString::fromStdString(strVec[i]),intVec[i]);
        }

        int val = 0;
        feature->getValue(val);

        int index = combo->findData(val);
        combo->setCurrentIndex(index);

//        combo->setCurrentText(QString::fromStdString(strVec[val]));

        layout->setWidget(size, QFormLayout::FieldRole, combo);

        std::shared_ptr<FeatureUpdater> updater = std::make_shared<FeatureUpdater>(feature,combo);
        connect(combo,SIGNAL(currentIndexChanged(QString)), updater.get() ,SLOT(valueChange(QString)));
        _updaterVec.push_back(updater);

        return;

    }

}

QString MainWindow::getName(FeatureInfoPtr &info)
{

        if(!info->displayName.empty())
        return (QString::fromStdString(info->displayName));
        else
        return (QString::fromStdString(info->name));

}

void MainWindow::makeLayout(FeatureContainerPtr container, QWidget* widget)
{

    FeaturePtrMap _itemMap = container->items();

    for (const auto& ip: _itemMap) {

        FeaturePtr feature = ip.second;
        makeFeatureWidget(feature,widget);

    }

}
