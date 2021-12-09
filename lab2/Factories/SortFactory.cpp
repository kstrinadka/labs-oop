//
// Created by Kirill on 08.12.2021.
//

#include "SortFactory.h"

lab2::Worker *lab2::SortFactory::FactoryMethod(std::vector<std::string> &arguments) const {
    return new lab2::WorkerSort(arguments);
}
