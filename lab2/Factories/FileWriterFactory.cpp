//
// Created by Kirill on 07.12.2021.
//

#include "FileWriterFactory.h"



lab2::Worker *lab2::FileWriterFactory::FactoryMethod(std::vector<std::string> &arguments) const {

    return new lab2::WorkerWriteFile(arguments);
}
