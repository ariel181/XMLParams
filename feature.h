#ifndef FEATURE_H
#define FEATURE_H

#include <map>
#include <string>
#include "sharedpointerdefines.h"
#include "errortype.h"
#include "basefeature.h"
#include "featureinfo.h"


typedef std::map<std::string, FeaturePtr> FeaturePtrMap;

class Feature
{
public:
    Feature(FeatureInfoPtr info);
    Feature();
    friend boost::property_tree::ptree & operator << (boost::property_tree::ptree &tree, const Feature& base);
    friend boost::property_tree::ptree & operator >> (boost::property_tree::ptree &tree, Feature& base);
    ~Feature();

    ErrorType type(FeatureType& pom);
    ErrorType getChildren(FeatureContainerPtr &vec);

    ErrorType getValue(int& pom);
    ErrorType getValue(bool& pom);
    ErrorType getValue(std::string& pom);
    ErrorType getValues(IntVec& pom);
    ErrorType getValues(StringVec& pom);

    ErrorType getInfo(FeatureInfoPtr &info) const;

    ErrorType setValue(const int pom);
    ErrorType setValue(const bool pom);
    ErrorType setValue(const std::string pom);

    ErrorType setValues(const IntVec pom);
    ErrorType setValues(const StringVec pom);

    ErrorType getRange(int64_t& minimum, int64_t& maximum);
    ErrorType setRange(const int64_t minimum, const int64_t maximum);

private:
    BaseFeaturePtr _item;
    void resetItem(FeatureInfoPtr info);


};


#endif // FEATURE_H
