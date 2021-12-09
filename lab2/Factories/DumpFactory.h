//
// Created by Kirill on 08.12.2021.
//

#ifndef LAB2_DUMPFACTORY_H
#define LAB2_DUMPFACTORY_H


#include "WorkerFactory.h"
#include "../Workers/WorkerDump.h"


namespace lab2 {



    class DumpFactory : public WorkerFactory {
    public:

        Worker* FactoryMethod(std::vector<std::string> &arguments) const override;


    };


}




#endif //LAB2_DUMPFACTORY_H
