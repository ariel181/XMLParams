#include "featurebuilder.h"
#include "feature.h"
#include "featurecontainer.h"

FeatureBuilder::FeatureBuilder():
     _contener(nullptr)
    ,_contenerParent(nullptr)
{

}

FeatureBuilder::FeatureBuilder(FeatureContainerPtr& contener)
{
    _contener= contener;
    _contenerParent = contener;

}

FeatureBuilder &FeatureBuilder::featureBuild(std::string name, FeatureType dataType)
{
    _info.reset(new FeatureInfo);
    _info->name = name;
    _info->dataType = dataType;
    _currentType = dataType;

    _item.reset(new Feature(_info));

    return *this;
}

FeatureBuilder &FeatureBuilder::addEnum(std::string name, int val)
{

    _enumIntVec.push_back(val);
    _enumStringVec.push_back(name);

    return *this;
}

FeatureBuilder &FeatureBuilder::setValue(int val)
{
    _item->setValue(val);
    return *this;
}

FeatureBuilder &FeatureBuilder::setValue(bool val)
{
    _item->setValue(val);
    return *this;
}

FeatureBuilder &FeatureBuilder::setRange(const int64_t minimum, const int64_t maximum)
{
    _item->setRange(minimum,maximum);
    return *this;
}

FeaturePtr FeatureBuilder::build()
{

//TODO sprawdzanie poprawności implementacji danych np. czy są ustawione enumy jezeli typ dataEnum;
    if(_info->dataType == FeatureType::Enum)
    {
        _item->setValues(_enumStringVec);
        _item->setValues(_enumIntVec);
    }

    FeaturePtr pom(_item);

    if(_contener!=nullptr)
    {
        _contener->add(_item);
    }

    if(_currentType == FeatureType::Grope)
        _item->getChildren(_contener);

    _item.reset();
    _enumIntVec.clear();
    _enumStringVec.clear();

    return pom;
}

void FeatureBuilder::closeGrope()
{
//    _contener.reset();
    _contener  = _contenerParent;
}
