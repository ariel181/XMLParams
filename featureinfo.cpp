#include "featureinfo.h"

boost::property_tree::ptree &operator<<(boost::property_tree::ptree &tree, const FeatureInfo &info)
{
    boost::property_tree::ptree& info_tree = tree.add_child("Info",boost::property_tree::ptree{});

    info_tree.put("name",info.name);
    info_tree.put("displayName",info.displayName);
    info_tree.put("dataType",static_cast<int>(info.dataType));
    info_tree.put("category",info.category);
    info_tree.put("isVisible",info.isVisible);

    return tree;
}

boost::property_tree::ptree & operator >> (boost::property_tree::ptree &tree, FeatureInfo &info)
{
    const boost::property_tree::ptree& info_tree = tree.get_child("Info",boost::property_tree::ptree{});

    info.name = info_tree.get<std::string>("name","");
    info.displayName = info_tree.get<std::string>("displayName","");
    info.dataType = static_cast<FeatureType>(info_tree.get<int>("dataType",0));
    info.category = info_tree.get<std::string>("category","");
    info.isVisible = info_tree.get<bool>("isVisible",false);
    return tree;
}

FeatureInfo::FeatureInfo()
{

}
