//
// Created by Kirill on 04.12.2021.
//

#ifndef LAB2_FILEREADERFACTORY_H
#define LAB2_FILEREADERFACTORY_H


#include "WorkerFactory.h"
#include "../Workers/WorkerReadFile.h"


namespace lab2 {





    class FileReaderFactory: public WorkerFactory {
    public:

        Worker* FactoryMethod(std::vector<std::string> &arguments) const override;



    };



}


#endif //LAB2_FILEREADERFACTORY_H
