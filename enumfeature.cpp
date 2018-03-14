#include "enumfeature.h"
#include "featureinfo.h"
#include <exception>
#include <iostream>

EnumFeature::EnumFeature(FeatureInfoPtr ptr): BaseFeature(ptr)
{

}

EnumFeature::~EnumFeature()
{

}

ErrorType EnumFeature::getValue(int &pom)
{
    pom = _value;
    return ErrorType::Success;
}

ErrorType EnumFeature::getValues(IntVec &pom)
{
    pom = _enumIntVec;
    return ErrorType::Success;
}

ErrorType EnumFeature::getValues(StringVec &pom)
{
    pom = _enumStringVec;
    return ErrorType::Success;
}

ErrorType EnumFeature::setValue(const int pom)
{
    _value = pom;
    return ErrorType::Success;
}

ErrorType EnumFeature::setValue(const std::string pom)
{
    int index = -1;
    bool finde = false;

    for(size_t i = 0 ; i < _enumStringVec.size(); i++)
    {
        const std::string act = _enumStringVec[i];
        if(pom.compare(act) == 0 )
        {
            index = i;
            finde = true;
            break;
        }
    }

    if(finde)
    {
        _value = _enumIntVec[index];
        std::cout<< "index:"<<_value << " name:" << _enumStringVec[index] << std::endl;
    }
    else
    {
        throw std::runtime_error("can't find enum.");
    }

    return ErrorType::Success;

}

ErrorType EnumFeature::setValues(const IntVec pom)
{
    _enumIntVec = pom;
    return ErrorType::Success;
}

ErrorType EnumFeature::setValues(const StringVec pom)
{
    _enumStringVec = pom;
    return ErrorType::Success;
}

void EnumFeature::print(boost::property_tree::ptree &tree) const
{

    boost::property_tree::ptree& feature_tree = tree;
//    feature_tree<<*_info;

    if (_enumIntVec.size() != _enumStringVec.size()) {
        return;
    }


    size_t max = _enumIntVec.size();
    boost::property_tree::ptree enums;

    for (int i = 0; i < max; ++i)
    {
        boost::property_tree::ptree enum_;
        enum_.put("<xmlattr>.key", _enumIntVec[i]);
        enum_.put("<xmlattr>.name", _enumStringVec[i]);
//        enum_.put("key", _enumIntVec[i]);
//        enum_.put("name", _enumStringVec[i]);
        enums.add_child("enum",enum_);
        //        enums.put(_enumIntVec[i],_enumStringVec[i]);
    }

    feature_tree.add_child("enums",enums);

    feature_tree.put("value", _value);

}

void EnumFeature::read(const boost::property_tree::ptree &tree)
{

    _value = tree.get<int>("value",0);


    const boost::property_tree::ptree& enums_tree = tree.get_child("enums",boost::property_tree::ptree{});


    const std::string sub = "enum";
    for(const boost::property_tree::ptree::value_type& child : enums_tree)
    {
        if(child.first == sub){

          auto tree = child.second ;
          int val_int = tree.get<int>("<xmlattr>.key",0);
          std::string val_str = tree.get<std::string>("<xmlattr>.name","");
          _enumIntVec.push_back(val_int);
          _enumStringVec.push_back(val_str);
        }

    }
}
