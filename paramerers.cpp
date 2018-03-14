#include "paramerers.h"
#include "featurebuilder.h"
#include <iostream>
#include "featurecontainer.h"

Paramerers::Paramerers():_container(new FeatureContainer)
      ,_builder(new FeatureBuilder(_container))
{

    cbq();
    fd();
    csi();


}

FeatureContainerPtr Paramerers::container() const
{
    return _container;
}

void Paramerers::cbq()
{

    //CBQ
    _builder->featureBuild("CheckBaseQuality",FeatureType::Grope).build();
    _builder->featureBuild("_Method_VM",FeatureType::Bool).setValue(true).build();
    _builder->featureBuild("_Method_MM",FeatureType::Bool).setValue(false).build();
    _builder->featureBuild("_Method_LT",FeatureType::Bool).setValue(false).build();

    _builder->featureBuild("_Method_Color_VM",FeatureType::Bool).setValue(true).build();
    _builder->featureBuild("_Method_Color_MM",FeatureType::Bool).setValue(false).build();
    _builder->featureBuild("_Method_Color_LT",FeatureType::Bool).setValue(false).build();
    _builder->closeGrope();
    //    FeatureInfoPtr info;
    //    pom->getInfo(info);

    //    std::cout<<__FUNCTION__<<info->name<<std::endl;



}

void Paramerers::fd()
{
    //FD
    _builder->featureBuild("FusionDefects",FeatureType::Grope).build();
    _builder->featureBuild("_Method",FeatureType::Enum)
                    .addEnum("advanced",1)
                    .addEnum("union",2)
                    .setValue(2)
                    .build();
    _builder->featureBuild("_Method_Color",FeatureType::Enum)
                    .addEnum("advanced",1)
                    .addEnum("union",2)
                    .setValue(1)
                    .build();
    _builder->closeGrope();
}

void Paramerers::csi()
{

    //CSI
    _builder->featureBuild("CutSingleImage",FeatureType::Grope).build();
    _builder->featureBuild("_RegionLowValue",FeatureType::Int)
                    .setValue(100)
                    .setRange(0,255)
                    .build();

    _builder->featureBuild("_RegionHighValue",FeatureType::Int)
                    .setValue(150)
                    .setRange(0,255)
                    .build();

    _builder->featureBuild("_MaxImages",FeatureType::Int)
                    .setValue(100)
                    .setRange(0,100000000)
                    .build();

    _builder->featureBuild("_MinArea",FeatureType::Int)
                    .setValue(100)
                    .setRange(0,100000000)
                    .build();
    _builder->featureBuild("_MaxArea",FeatureType::Int)
                    .setValue(100)
                    .setRange(0,100000000)
                    .build();

    _builder->featureBuild("_CentralRowOffset",FeatureType::Int)
                    .setValue(100)
                    .setRange(0,100000000)
                    .build();

    _builder->featureBuild("_CentralLen1",FeatureType::Int)
                    .setValue(100)
                    .setRange(0,100000000)
                    .build();
    _builder->closeGrope();

    //CSIC

    _builder->featureBuild("CutSingleImageColor",FeatureType::Grope).build();
    _builder->featureBuild("_RegionLowValue_Color",FeatureType::Int)
                    .setValue(100)
                    .setRange(0,255)
                    .build();

    _builder->featureBuild("_RegionHighValue_Color",FeatureType::Int)
                    .setValue(150)
                    .setRange(0,255)
                    .build();

    _builder->featureBuild("_MaxImages_Color",FeatureType::Int)
                    .setValue(100)
                    .setRange(0,100000000)
                    .build();

    _builder->featureBuild("_MinArea_Color",FeatureType::Int)
                    .setValue(100)
                    .setRange(0,100000000)
                    .build();

    _builder->featureBuild("_MaxArea_Color",FeatureType::Int)
                    .setValue(100)
                    .setRange(0,100000000)
                    .build();

    _builder->featureBuild("_MainColorChannel",FeatureType::Int)
                    .setValue(2)
                    .setRange(1,3)
                    .build();
    _builder->closeGrope();
}

void Paramerers::vm()
{
    _builder->featureBuild("VariationModel",FeatureType::Grope).build();














    _builder->closeGrope();
}
