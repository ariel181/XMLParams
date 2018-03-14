#include "basefeature.h"
#include "featureinfo.h"
#include <iostream>

BaseFeature::BaseFeature(FeatureInfoPtr info):_info(info)
{
    std::cout<<"creat feature Name:"<<info->name<<std::endl;

}

BaseFeature::~BaseFeature()
{
    std::cout<<"BaseFeature::~BaseFeature()<-"<<_info->name<<std::endl;

}

const boost::property_tree::ptree & operator >>(const boost::property_tree::ptree &tree, BaseFeature &base)
{
    base.read(tree);
    return tree;
}

boost::property_tree::ptree &operator<<(boost::property_tree::ptree &tree, const BaseFeature &base)
{
    base.print(tree);
    return tree;
}

ErrorType BaseFeature::getInfo(FeatureInfoPtr& ptr)
{

    if(_info != nullptr)
    {
        ptr = _info;
        return ErrorType::Success;
    }

    return ErrorType::WrongType;

}

ErrorType BaseFeature::getValue(std::string &pom)
{
    pom = "";
    return ErrorType::WrongType;
}

ErrorType BaseFeature::getValue(int &pom )
{
    pom = 0;
    return ErrorType::WrongType;
}

ErrorType BaseFeature::getValue(double &pom)
{
    pom = 0;
    return ErrorType::WrongType;
}

ErrorType BaseFeature::getValue(uint &pom)
{
    pom = 0;
    return ErrorType::WrongType;
}

ErrorType BaseFeature::getValue(bool& pom)
{
    pom = 0;
    return ErrorType::WrongType;
}

ErrorType BaseFeature::getValues(IntVec &pom)
{
    return ErrorType::WrongType;
}

ErrorType BaseFeature::getValues(StringVec &pom)
{
    return ErrorType::WrongType;
}

ErrorType BaseFeature::setValue(const std::string pom)
{
    return ErrorType::WrongType;
}

ErrorType BaseFeature::setValue(const int pom)
{
    return ErrorType::WrongType;
}

ErrorType BaseFeature::setValue(const double pom)
{
    return ErrorType::WrongType;
}

ErrorType BaseFeature::setValue(const uint pom)
{
    return ErrorType::WrongType;
}

ErrorType BaseFeature::setValue(const bool pom)
{
    return ErrorType::WrongType;
}

ErrorType BaseFeature::setValues(const IntVec pom)
{
    return ErrorType::WrongType;
}

ErrorType BaseFeature::setValues(const StringVec pom)
{
    return ErrorType::WrongType;
}

ErrorType BaseFeature::getRange(int64_t &minimum, int64_t &maximum)
{
    minimum = 0;
    maximum = 0;
    return ErrorType::WrongType;
}

ErrorType BaseFeature::setRange(const int64_t minimum, const int64_t maximum)
{
    return ErrorType::WrongType;
}

ErrorType BaseFeature::getChildren(FeatureContainerPtr &children)
{
    return ErrorType::WrongType;
}

void BaseFeature::print(boost::property_tree::ptree &tree) const
{
    //FIXME zaimplementowac cialo na jakies domyslne;
}

void BaseFeature::read(const boost::property_tree::ptree &tree)
{
    //FIXME zaimplementowac cialo na jakies domyslne;
}
