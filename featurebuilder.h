#ifndef FEATUREBUILDER_H
#define FEATUREBUILDER_H


#include "sharedpointerdefines.h"
#include "basefeature.h"
#include "featureinfo.h"



class FeatureBuilder
{

public:
    FeatureBuilder();
    FeatureBuilder(FeatureContainerPtr &contener);

    FeatureBuilder& featureBuild(std::string name, FeatureType dataType);
    FeatureBuilder& addEnum(std::string name, int val);
    FeatureBuilder& setValue(int val);
    FeatureBuilder& setValue(bool val);
    FeatureBuilder& setRange(const int64_t minimum, const int64_t maximum);
    FeaturePtr build();
    void closeGrope();

private:

    FeatureContainerPtr _contener;
    FeatureContainerPtr _contenerParent;
    FeatureType _currentType;

    FeatureInfoPtr _info;
    FeaturePtr _item;

    IntVec _enumIntVec;
    StringVec _enumStringVec;

};

#endif // FEATUREBUILDER_H
