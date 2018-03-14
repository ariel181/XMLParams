#ifndef ENUMFEATURE_H
#define ENUMFEATURE_H

#include "sharedpointerdefines.h"
#include "basefeature.h"


class EnumFeature : public BaseFeature
{
public:
    EnumFeature(FeatureInfoPtr ptr);
    ~EnumFeature();


    ErrorType getValue(int &pom);
    ErrorType getValues(IntVec &pom);
    ErrorType getValues(StringVec &pom);

    ErrorType setValue(const int pom);
    ErrorType setValue(const std::string pom);

    ErrorType setValues(const IntVec pom);
    ErrorType setValues(const StringVec pom);

private:
    void print(boost::property_tree::ptree& tree) const;
    int _value;
    IntVec _enumIntVec;
    StringVec _enumStringVec;


    // BaseFeature interface
private:
    void read(const boost::property_tree::ptree &tree);
};

#endif // ENUMFEATURE_H
