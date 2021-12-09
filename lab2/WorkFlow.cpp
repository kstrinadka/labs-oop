//
// Created by Kirill on 29.11.2021.
//

#include "WorkFlow.h"

namespace lab2 {


    void WorkFlow::print_parsed_chain() {

        std::cout << std::endl << "Parsed chain:" << std::endl;
        for (auto it = this->chain_of_nodes.begin(); it != chain_of_nodes.end(); ++it)
        {
            std::cout << *it << "\t";
        }
        std::cout <<std::endl;
    }

    void WorkFlow::print_parsed_map() {

        std::cout << std::endl << "Parsed map_for_blocks:" << std::endl;
        for (auto it = map_from_parser.begin(); it != map_from_parser.end(); ++it)
        {
            std::cout << it->first << " : ";
            for (auto v = it->second.begin(); v != it->second.end(); ++v)
            {
                std::cout << *v << "\t";
            }
            std::cout << std::endl;
        }
        std::cout <<std::endl;
    }

    void WorkFlow::computing_pipeline() {


        for (auto it = this->chain_of_nodes.begin(); it != chain_of_nodes.end(); ++it)
        {

            if (map_from_parser.count(*it) != 1) {
                std::cout << "sadfasfdsa" << std::endl;
                throw InvalidBlockNumber(*it, "name");
            }
            //тут создается блок в зависимости от его имени
            Worker *worker = create_block_from_name(map_from_parser[*it]);

            if (worker != nullptr) {
                //worker->print_data();

                //тут вызывается нужный метод из Worker
                worker->main_action(text, text_is_exist);      //можно сюда и аргументы передавать, а не только текст, чтобы Worker не хранил данных
                //this->print_created_text();
            }
        }
    }

    lab2::Worker *WorkFlow::create_block_from_name(std::vector<std::string> arguments) {

        std::string name_of_block = arguments[0];

        if (name_of_block == "readfile") {
            WorkerFactory* factory = new FileReaderFactory;
            Worker* worker = factory->FactoryMethod(arguments);
            return worker;
        }

        if (name_of_block == "writefile") {
            WorkerFactory* factory = new FileWriterFactory;
            Worker* worker = factory->FactoryMethod(arguments);
            return worker;
        }

        if (name_of_block == "grep") {
            WorkerFactory* factory = new GrepFactory;
            Worker* worker = factory->FactoryMethod(arguments);
            return worker;
        }

        if (name_of_block == "sort") {
            WorkerFactory* factory = new SortFactory;
            Worker* worker = factory->FactoryMethod(arguments);
            return worker;
        }

        if (name_of_block == "replace") {
            WorkerFactory* factory = new ReplaceFactory;
            Worker* worker = factory->FactoryMethod(arguments);
            return worker;
        }

        if (name_of_block == "dump") {
            WorkerFactory* factory = new DumpFactory;
            Worker* worker = factory->FactoryMethod(arguments);
            return worker;
        }

        return nullptr;
    }

    //Выводит текст, который сейчас в схеме
    void WorkFlow::print_created_text() {
        std::cout << std::endl << "created text:" << std::endl;
        for (auto it = this->text.begin(); it != text.end(); ++it)
        {
            std::cout << *it << "\n";
        }
        std::cout <<std::endl;
    }


}