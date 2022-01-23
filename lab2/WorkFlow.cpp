//
// Created by Kirill on 29.11.2021.
//

#include "WorkFlow.h"

namespace lab2 {



    void WorkFlow::computing_pipeline() {
        const std::string name = "name";
        for (auto it = this->chain_of_nodes.begin(); it != chain_of_nodes.end(); ++it)
        {

            if (map_from_parser.count(*it) != 1) {
                throw InvalidBlockNumber(*it, name);
            }
            //тут создается блок в зависимости от его имени
            Worker *worker = create_block_from_name(map_from_parser[*it]);

            if (worker != nullptr) {

                //тут вызывается нужный метод из Worker
                worker->main_action(text, text_is_exist);
            }
        }
    }

    lab2::Worker *WorkFlow::create_block_from_name(std::vector<std::string> arguments) {

        std::string name_of_block = arguments[0];

        std::map<std::string, WorkerFactory *> mapWorkers = factories.getMapWorkers();
        Worker* worker = mapWorkers[name_of_block]->FactoryMethod(arguments);
        return worker;
    }

}