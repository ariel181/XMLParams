#ifndef FEATURECONTAINER_H
#define FEATURECONTAINER_H

#include "feature.h"
#include "errortype.h"



class FeatureContainer
{
public:
    FeatureContainer();
    friend boost::property_tree::ptree& operator<<(boost::property_tree::ptree &tree, const FeatureContainer& base);
    friend const boost::property_tree::ptree& operator>>(const boost::property_tree::ptree &tree, FeatureContainer& base);
    ErrorType getByName(const std::string name, FeaturePtr &feature);
    ErrorType add(FeaturePtr feature);
    FeaturePtrMap items();

private:
    FeaturePtrMap _itemMap;

};



#endif // FEATURECONTAINER_H
