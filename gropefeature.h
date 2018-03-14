#ifndef GROPEFEATURE_H
#define GROPEFEATURE_H

#include "basefeature.h"
#include "sharedpointerdefines.h"

class GropeFeature : public BaseFeature
{
public:
    GropeFeature(FeatureInfoPtr info);

    // BaseFeature interface
public:
    ErrorType getChildren(FeatureContainerPtr &children);

private:

    void print(boost::property_tree::ptree &tree) const;
    void read(const boost::property_tree::ptree &tree);

    FeatureContainerPtr _children;


};

#endif // GROPEFEATURE_H1,
