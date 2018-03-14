#ifndef BOOLFEATURE_H
#define BOOLFEATURE_H

#include "basefeature.h"

class BoolFeature : public BaseFeature
{
public:
    BoolFeature(FeatureInfoPtr info);

public:
    ErrorType getValue(bool &pom);
    ErrorType setValue(const bool pom);

private:
    void print(boost::property_tree::ptree &tree) const;

    bool _value;

    // BaseFeature interface
private:
    void read(const boost::property_tree::ptree &tree);
};

#endif // BOOLFEATURE_H
