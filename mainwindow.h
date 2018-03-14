#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <QComboBox>
#include <QSpinBox>
#include <QGroupBox>
#include <QFormLayout>
#include <QLabel>
#include <sharedpointerdefines.h>
#include <vector>
#include "featureupdater.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setFeatures(FeatureContainerPtr container);
    ~MainWindow();

private:
    void makeFeatureWidget(const FeaturePtr &feature, QWidget *layout);
    QString getName(FeatureInfoPtr& info);
    void makeLayout(FeatureContainerPtr container, QWidget *layout);
    Ui::MainWindow *ui;
    std::vector<std::shared_ptr<FeatureUpdater > > _updaterVec;

};

#endif // MAINWINDOW_H
