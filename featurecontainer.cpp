#include "featurecontainer.h"
#include "featureinfo.h"
#include <iostream>
#include <map>

FeatureContainer::FeatureContainer()
{

}

const boost::property_tree::ptree &operator>>(const boost::property_tree::ptree &tree, FeatureContainer &base)
{

    std::string sub = "Feature";

    for(const boost::property_tree::ptree::value_type& child : tree)
    {
        if(child.first == sub){

            FeaturePtr feature(new Feature());

          auto tree = child.second ;
            tree >> *feature;
//            ModulesIOParams item(stock);
//            read_tree(child.second, item);
            base.add(feature);
//            stock.addItem(item);
        }
    }


    return tree;
}

boost::property_tree::ptree &operator<<(boost::property_tree::ptree &tree, const FeatureContainer &base)
{

//    boost::property_tree::ptree& feature_tree = tree.add_child("Features",boost::property_tree::ptree{});

    for (const auto& ip: base._itemMap) {
        std::cout << ip.first << std::endl;
        boost::property_tree::ptree feature_tree ;

//        feature_tree << *ip.second;
        feature_tree << *ip.second;
        tree.add_child("Feature",feature_tree);

    }
    return tree;

}

ErrorType FeatureContainer::add(FeaturePtr feature)
{

    FeatureInfoPtr ptr;
    feature->getInfo(ptr);

    if(ptr->name.empty())
        return ErrorType::InvalidValue;

    _itemMap[ptr->name] = feature;
    std::cout<<__FUNCTION__<<std::endl;
    return ErrorType::Success;

}

FeaturePtrMap FeatureContainer::items()
{

    return _itemMap;

}

ErrorType FeatureContainer::getByName(const std::string name, FeaturePtr& feature)
{

    if(name.empty()) return ErrorType::InvalidValue;
    auto ip =  _itemMap.find(name);
    if(ip == _itemMap.end()) return ErrorType::InvalidValue;
    feature = ip->second;
    return ErrorType::Success;

}
