#include "intfeature.h"
#include "featureinfo.h"

IntFeature::IntFeature(FeatureInfoPtr info):BaseFeature(info)
      ,_value(0)
      ,_max(INT64_MAX)
      ,_min(INT64_MIN)
{

}

IntFeature::~IntFeature()
{

}

ErrorType IntFeature::getValue(int& pom)
{
    pom = _value;
    return ErrorType::Success;
}

ErrorType IntFeature::setValue(const int pom)
{
    _value = pom;
}

ErrorType IntFeature::getRange(int64_t& minimum, int64_t& maximum)
{
    minimum = _min;
    maximum = _max;

    return ErrorType::Success;
}

ErrorType IntFeature::setRange(const int64_t minimum, const int64_t maximum)
{
    _min = minimum;
    _max = maximum;

    return ErrorType::Success;
}

void IntFeature::print(boost::property_tree::ptree &tree) const
{
    boost::property_tree::ptree& feature_tree = tree;

//    feature_tree<<*_info;
    feature_tree.put("value", _value);
    feature_tree.put("value.<xmlattr>.min", _min);
    feature_tree.put("value.<xmlattr>.max", _max);

//    feature_tree.put("min", _min);
//    feature_tree.put("max", _max);



}

void IntFeature::read(const boost::property_tree::ptree &tree)
{

    _value = tree.get<int>("value",0);
    _min = tree.get<int>("value.<xmlattr>.min",0);
    _max = tree.get<int>("value.<xmlattr>.max",0);

}

