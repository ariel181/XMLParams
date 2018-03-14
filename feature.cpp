#include "feature.h"
#include "featureinfo.h"
#include "intfeature.h"
#include "boolfeature.h"
#include "enumfeature.h"
#include "gropefeature.h"
#include "iostream"


Feature::Feature(FeatureInfoPtr info)
//    _item(new BaseFeature(info))

{

    resetItem(info);

}

Feature::Feature()
//    _item(new BaseFeature())
{

}

boost::property_tree::ptree &operator >> (boost::property_tree::ptree &tree, Feature &base)
{

    FeatureInfoPtr info(new FeatureInfo);

    std::cout<<"read Feature"<<std::endl;
    tree >> *info;
    base.resetItem(info);
    tree >> *base._item;
    return tree;
}

boost::property_tree::ptree &operator<<(boost::property_tree::ptree &tree, const Feature &base)
{
    FeatureInfoPtr info;
    base.getInfo(info);

    tree << *info;
    tree << *base._item;

    return tree;

}

Feature::~Feature()
{
    std::cout<<"Feature::~Feature"<<std::endl;
}

ErrorType Feature::type(FeatureType &pom)
{
    FeatureInfoPtr info;
    ErrorType error = _item->getInfo(info);
    if(error== ErrorType::Success)
        pom = info->dataType;
    return error;
}

ErrorType Feature::getChildren(FeatureContainerPtr &vec)
{
    return _item->getChildren(vec);
}

ErrorType Feature::getValue(int &pom)
{
    return _item->getValue(pom);
}

ErrorType Feature::getValue(bool &pom)
{
    return _item->getValue(pom);
}

ErrorType Feature::getValue(std::string &pom)
{
    return _item->getValue(pom);
}

ErrorType Feature::getValues(IntVec &pom)
{
    return _item->getValues(pom);
}

ErrorType Feature::getValues(StringVec &pom)
{
    return _item->getValues(pom);
}

ErrorType Feature::getInfo(FeatureInfoPtr& info) const
{
    return _item->getInfo(info);
}

ErrorType Feature::setValue(const bool pom)
{
    return _item->setValue(pom);
}

ErrorType Feature::setValue(const std::string pom)
{
    return _item->setValue(pom);
}

ErrorType Feature::setValue(const int pom)
{
    return _item->setValue(pom);
}

ErrorType Feature::setValues(const IntVec pom)
{
    return _item->setValues(pom);
}

ErrorType Feature::setValues(const StringVec pom)
{
    return _item->setValues(pom);
}

ErrorType Feature::getRange(int64_t &minimum, int64_t &maximum)
{

    return _item->getRange(minimum,maximum);
}

ErrorType Feature::setRange(const int64_t minimum, const int64_t maximum)
{
    return _item->setRange(minimum,maximum);
}

void Feature::resetItem(FeatureInfoPtr info)
{
    if(info != nullptr)
    {
        switch (info->dataType)
        {
        case FeatureType::Int:
            _item.reset(new IntFeature(info));
            break;

        case FeatureType::Enum:
            _item.reset(new EnumFeature(info));
            break;

        case FeatureType::Bool:
            _item.reset(new BoolFeature(info));
            break;

        case FeatureType::Grope:
            _item.reset(new GropeFeature(info));
            break;

        default:
            _item.reset(new BaseFeature(info));
            break;
        }
    }

}
