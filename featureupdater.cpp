#include "featureupdater.h"
#include "feature.h"
#include <QDebug>

FeatureUpdater::FeatureUpdater(FeaturePtr feature, QObject *parent) : QObject(parent)
  ,_feature(feature)
{

}

FeatureUpdater::~FeatureUpdater()
{

}

void FeatureUpdater::valueChange(int val)
{
    FeatureInfoPtr info;
    _feature->getInfo(info);
    qDebug()<<"Name:"<<QString::fromStdString(info->name)<<" val:"<<val;

    _feature->setValue(val);
}

void FeatureUpdater::valueChange(bool val)
{
    FeatureInfoPtr info;
    _feature->getInfo(info);
    qDebug()<<"Name:"<<QString::fromStdString(info->name)<<" val:"<<val;
    _feature->setValue(val);

}

void FeatureUpdater::valueChange(QString val)
{
    FeatureInfoPtr info;
    _feature->getInfo(info);
    qDebug()<<"Name:"<<QString::fromStdString(info->name)<<" val:"<<val;
    _feature->setValue(val.toStdString());

}
