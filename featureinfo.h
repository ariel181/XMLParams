#ifndef FEATUREINFO_H
#define FEATUREINFO_H

#include <string>
#include <memory>
#include <boost/property_tree/ptree.hpp>

enum class FeatureType
{
    Unknown     = 0,          // Unknown feature type
    Int         = 1,          // 64 bit integer feature
    Float       = 2,          // 64 bit floating point feature
    Enum        = 3,          // Enumeration feature
    String      = 4,          // String feature
    Bool        = 5,          // Boolean feature
    Command     = 6,          // Command feature
    Raw         = 7,          // Raw (direct register access) feature
    None        = 8,          // Feature with no data
    Grope		= 9,		  // oznacza grupe danych
};

class FeatureInfo
{

public:


    friend boost::property_tree::ptree & operator<<(boost::property_tree::ptree &tree, const FeatureInfo& info);
    friend boost::property_tree::ptree & operator >> (boost::property_tree::ptree &tree, FeatureInfo& info);

    FeatureInfo();
    std::string name; // nazwa parametru
    std::string displayName; // nazwa widoczna w GUI
    FeatureType dataType; // typ danych parametru
    std::string category; // nazwa kategori w jakiej występuje parametr
    bool isVisible ; // widoczność po stronie GUI

};


#endif // FEATUREINFO_H
