#ifndef FEATURETREEMODEL_H
#define FEATURETREEMODEL_H

#include <QObject>
#include <QAbstractItemModel>
#include "sharedpointerdefines.h"

class FeatureTreeModel : public QAbstractItemModel
{
public:
    FeatureTreeModel(FeaturePtr root);

    // QAbstractItemModel interface
public:
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
private:
    FeaturePtr nodeFromIndex(const QModelIndex &index) const;

    FeaturePtr _root;
};

#endif // FEATURETREEMODEL_H
