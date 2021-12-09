//
// Created by Kirill on 08.12.2021.
//

#ifndef LAB2_REPLACEFACTORY_H
#define LAB2_REPLACEFACTORY_H

#include "WorkerFactory.h"
#include "../Workers/WorkerReplace.h"


namespace lab2 {


    class ReplaceFactory : public WorkerFactory {

        Worker* FactoryMethod(std::vector<std::string> &arguments) const override;

    };


}





#endif //LAB2_REPLACEFACTORY_H
