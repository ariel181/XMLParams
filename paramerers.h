#ifndef PARAMERERS_H
#define PARAMERERS_H

#include "sharedpointerdefines.h"


class Paramerers
{
public:
    Paramerers();

    FeatureContainerPtr container() const;

private:
    void cbq();
    void fd();
    void csi();
    void vm();
    FeatureContainerPtr _container;
    FeatureBuilderPtr _builder;
};

#endif // PARAMERERS_H
