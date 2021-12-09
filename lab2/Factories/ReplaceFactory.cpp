//
// Created by Kirill on 08.12.2021.
//

#include "ReplaceFactory.h"

lab2::Worker *lab2::ReplaceFactory::FactoryMethod(std::vector<std::string> &arguments) const {
    return new lab2::WorkerReplace(arguments);
}
