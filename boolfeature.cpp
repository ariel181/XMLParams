#include "boolfeature.h"
#include "featureinfo.h"

BoolFeature::BoolFeature(FeatureInfoPtr info) : BaseFeature(info)
{

}

ErrorType BoolFeature::getValue(bool &pom)
{
    pom = _value;
    return ErrorType::Success;
}

ErrorType BoolFeature::setValue(const bool pom)
{
    _value = pom;
    return ErrorType::Success;
}

void BoolFeature::print(boost::property_tree::ptree &tree) const
{
    boost::property_tree::ptree& feature_tree = tree;
//    feature_tree<<*_info;
    feature_tree.put("value", _value);
}

void BoolFeature::read(const boost::property_tree::ptree &tree)
{
    _value = tree.get<bool>("value", false);

}
