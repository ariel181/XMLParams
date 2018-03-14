#include "gropefeature.h"
#include "featurecontainer.h"

GropeFeature::GropeFeature(FeatureInfoPtr info): BaseFeature(info)
     ,_children(new FeatureContainer)
{

//    _children = new FeatureContainer();

}

ErrorType GropeFeature::getChildren(FeatureContainerPtr &children)
{
    children.reset();
    children = _children;
    return ErrorType::Success;
}

void GropeFeature::print(boost::property_tree::ptree &tree) const
{
    boost::property_tree::ptree& feature_tree = tree;
//    feature_tree<<*_info;
    feature_tree << * _children;
}

void GropeFeature::read(const boost::property_tree::ptree &tree)
{
//    const  boost::property_tree::ptree& info_pt =  tree.get_child("Info");
    tree >> *_children;
//    _info.reset(new );
}
