//
// Created by Kirill on 04.12.2021.
//

#include "FileReaderFactory.h"



lab2::Worker *lab2::FileReaderFactory::FactoryMethod(std::vector<std::string> &arguments) const {

    return new lab2::WorkerReadFile(arguments);
}
