//
// Created by Kirill on 08.12.2021.
//

#include "DumpFactory.h"

lab2::Worker *lab2::DumpFactory::FactoryMethod(std::vector<std::string> &arguments) const {
    return new lab2::WorkerDump(arguments);
}
