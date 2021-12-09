//
// Created by Kirill on 08.12.2021.
//

#ifndef LAB2_GREPFACTORY_H
#define LAB2_GREPFACTORY_H

#include "WorkerFactory.h"
#include "../Workers/WorkerGrep.h"



namespace lab2 {



    class GrepFactory: public WorkerFactory {


        Worker* FactoryMethod(std::vector<std::string> &arguments) const override;

    };



}








#endif //LAB2_GREPFACTORY_H
