//
// Created by Kirill on 27.12.2021.
//

#ifndef LAB2_MAPFACTORY_H
#define LAB2_MAPFACTORY_H

#include "WorkerFactory.h"
#include "FileReaderFactory.h"
#include "FileWriterFactory.h"
#include "GrepFactory.h"
#include "SortFactory.h"
#include "ReplaceFactory.h"
#include "DumpFactory.h"

#include <map>

using namespace lab2;

class MapFactory {
private:
    std::map<std::string, WorkerFactory *> mapWorkers{};
public:
    MapFactory() {
        mapWorkers.insert(std::make_pair("readfile", new FileReaderFactory));
        mapWorkers.insert(std::make_pair("writefile", new  FileWriterFactory));
        mapWorkers.insert(std::make_pair("grep", new GrepFactory));
        mapWorkers.insert(std::make_pair("sort", new SortFactory));
        mapWorkers.insert(std::make_pair("replace", new ReplaceFactory));
        mapWorkers.insert(std::make_pair("dump", new DumpFactory));

    }

    const std::map<std::string, WorkerFactory *> &getMapWorkers() const {
        return mapWorkers;
    }

public:


};

#endif //LAB2_MAPFACTORY_H
