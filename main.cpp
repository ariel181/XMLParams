#include "mainwindow.h"
#include <QApplication>

#include <iostream>
#include <ostream>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "sharedpointerdefines.h"
#include "featureinfo.h"
#include "feature.h"
#include "iomanip"
#include "featurecontainer.h"
#include "featurebuilder.h"
#include "paramerers.h"
#include "mainwindow.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Paramerers cerad;

    FeatureContainerPtr  container = cerad.container();


    w.setFeatures(container);
    w.show();
    const std::string filename("config.xml");

    auto settings =  boost::property_tree::xml_writer_make_settings<std::string>('\t',1);
    boost::property_tree::ptree _pt;

    _pt << *container;

    FeatureContainerPtr readContainer(new FeatureContainer);

    _pt >> *readContainer;
    w.setFeatures(readContainer);

    boost::property_tree::ptree ptRead;

    ptRead << *readContainer;

    boost::property_tree::ptree root;
    root.add_child("config",ptRead);
    //    root.add_child("config",_pt);
    root.put("config.<xmlattr>.version",static_cast<float>(1.00));

    boost::property_tree::write_xml(filename,root,std::locale(),settings);

    return a.exec();
}
