//
// Created by Kirill on 08.12.2021.
//

#include "GrepFactory.h"

lab2::Worker *lab2::GrepFactory::FactoryMethod(std::vector<std::string> &arguments) const {
    return new lab2::WorkerGrep(arguments);
}
