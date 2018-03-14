#ifndef BASEFEATURE_H
#define BASEFEATURE_H

#include <string>
#include "errortype.h"
#include "sharedpointerdefines.h"
#include <boost/property_tree/ptree.hpp>
#include <vector>



typedef std::vector<int> IntVec;
typedef std::vector<std::string> StringVec;

class BaseFeature
{
public:
    BaseFeature(FeatureInfoPtr _info);
    virtual ~BaseFeature();

    friend boost::property_tree::ptree & operator << (boost::property_tree::ptree &tree, const BaseFeature& base);
    friend const boost::property_tree::ptree & operator >> (const boost::property_tree::ptree &tree, BaseFeature &base);

    virtual ErrorType getInfo(FeatureInfoPtr &ptr);

    virtual ErrorType getValue(std::string& pom  );
    virtual ErrorType getValue(int& pom);
    virtual ErrorType getValue(double& pom);
    virtual ErrorType getValue(uint& pom);
    virtual ErrorType getValue(bool& pom);

    virtual ErrorType getValues(IntVec& pom);
    virtual ErrorType getValues(StringVec& pom);

    virtual ErrorType setValue(const std::string pom  );
    virtual ErrorType setValue(const int pom);
    virtual ErrorType setValue(const double pom);
    virtual ErrorType setValue(const uint pom);
    virtual ErrorType setValue(const bool pom);

    virtual ErrorType setValues(const IntVec pom);
    virtual ErrorType setValues(const StringVec pom);

    virtual ErrorType getRange(int64_t& minimum, int64_t& maximum);
    virtual ErrorType setRange(const int64_t minimum, const int64_t maximum);

    virtual ErrorType getChildren(FeatureContainerPtr& children);

protected:
    FeatureInfoPtr _info;

private:
    virtual void print(boost::property_tree::ptree &tree)const;
    virtual void read(const boost::property_tree::ptree &tree);

};


#endif // BASEFEATURE_H
