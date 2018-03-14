#ifndef INTFEATURE_H
#define INTFEATURE_H

#include "sharedpointerdefines.h"
#include "basefeature.h"

class IntFeature : public BaseFeature
{
public:
    IntFeature(FeatureInfoPtr _info);
    virtual ~IntFeature();
    ErrorType getValue(int &pom);
    ErrorType setValue(const int pom);

    ErrorType getRange(int64_t &minimum, int64_t &maximum);
    ErrorType setRange(const int64_t minimum, const int64_t maximum);

private:
    void print(boost::property_tree::ptree& tree) const;

    int _value;
    int64_t _min;
    int64_t _max;


    // BaseFeature interface
private:
    void read(const boost::property_tree::ptree &tree);
};

#endif // INTFEATURE_H
