//
// Created by Kirill on 08.12.2021.
//

#ifndef LAB2_SORTFACTORY_H
#define LAB2_SORTFACTORY_H

#include "WorkerFactory.h"
#include "../Workers/WorkerSort.h"


namespace lab2 {



    class SortFactory : public WorkerFactory {

        Worker* FactoryMethod(std::vector<std::string> &arguments) const override;

    };


}





#endif //LAB2_SORTFACTORY_H
