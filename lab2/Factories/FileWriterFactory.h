//
// Created by Kirill on 07.12.2021.
//

#ifndef LAB2_FILEWRITERFACTORY_H
#define LAB2_FILEWRITERFACTORY_H


#include "WorkerFactory.h"
#include "../Workers/WorkerWriteFile.h"

namespace lab2 {





    class FileWriterFactory : public WorkerFactory{
    public:

        Worker* FactoryMethod(std::vector<std::string> &arguments) const override;



    };






}






#endif //LAB2_FILEWRITERFACTORY_H
