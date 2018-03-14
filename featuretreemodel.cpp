#include "featuretreemodel.h"
#include "featurecontainer.h"
#include "features.h"

FeatureTreeModel::FeatureTreeModel(FeaturePtr root): _root(root)
{

}

QModelIndex FeatureTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!_root|| row < 0 || column < 0)
            return QModelIndex();


}

QModelIndex FeatureTreeModel::parent(const QModelIndex &child) const
{

}

int FeatureTreeModel::rowCount(const QModelIndex &parent) const
{




    if(parent.column() > 0 )
        return 0;

//    if (!parent.isValid())
//	    parentItem = rootItem;
//    else
//	    parentItem = static_cast<TreeItem*>(parent.internalPointer());

     FeaturePtr parentNode = nodeFromIndex(parent);

     FeatureType type = FeatureType::None;
     if(parentNode->type(type) != ErrorType::Success) return 0;

     if(type == FeatureType::Grope)
     {
         FeatureContainerPtr container;

         if(parentNode->getChildren(container)!= ErrorType::Success) return 0;

         return container->items().size();

     }
     else
     {
         return 1;
     }


    return 0;


}

int FeatureTreeModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
            return 0;
        else
            return 2;
}

QVariant FeatureTreeModel::data(const QModelIndex &index, int role) const
{


}

FeaturePtr FeatureTreeModel::nodeFromIndex(const QModelIndex &index) const
{

//    if (index.isValid()) {
//        return std::static_pointer_cast<FeaturePtr>(index.internalPointer());
//    } else {
//        return _root;
//    }

}
