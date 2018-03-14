#ifndef SHAREDPOINTERDEFINES_H
#define SHAREDPOINTERDEFINES_H

#include <memory>

class Feature;
typedef std::shared_ptr<Feature> FeaturePtr;

class FeatureInfo;
typedef std::shared_ptr<FeatureInfo> FeatureInfoPtr;

class BaseFeature;
typedef std::shared_ptr<BaseFeature> BaseFeaturePtr;

class FeatureContainer;
typedef std::shared_ptr<FeatureContainer> FeatureContainerPtr;

class FeatureBuilder;
typedef std::shared_ptr<FeatureBuilder> FeatureBuilderPtr;



#endif // SHAREDPOINTERDEFINES_H
