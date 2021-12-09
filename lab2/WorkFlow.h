//
// Created by Kirill on 29.11.2021.
//

#ifndef LAB2_WORKFLOW_H
#define LAB2_WORKFLOW_H

#include <iostream>
#include <vector>
#include <iostream>
#include <map>
#include "Workers/Worker.h"
#include "Factories/WorkerFactory.h"
#include "Factories/FileReaderFactory.h"
#include "Factories/FileWriterFactory.h"
#include "Factories/GrepFactory.h"
#include "Factories/SortFactory.h"
#include "Factories/ReplaceFactory.h"
#include "Factories/DumpFactory.h"


namespace lab2 {



    class WorkFlow {

        //по этой переменной понимаем можно ли считывать или записывать текст
        bool text_is_exist;

        //последовательность блоков, указанных в схемем
        ////эта штука поступила из ConfigurationFileParser
        std::vector<int> chain_of_nodes;

        //словарь из ConfigurationFileParser
        std::map<int, std::vector<std::string>> map_from_parser;

        //тут будет храниться текст, который обрабатывают блоки
        std::vector<std::string> text;

        //выбирает нужную фабрику по имени (создаем блок по его имени)
        lab2::Worker* create_block_from_name(std::vector<std::string> arguments);


    public:

        explicit WorkFlow(std::map<int, std::vector<std::string>>& map_with_blocks, std::vector<int>& chain_of_nodes)
        :map_from_parser(map_with_blocks), chain_of_nodes(chain_of_nodes) {
            text_is_exist = false;
        }

        void print_parsed_chain ();

        void print_parsed_map();

        //основная функция программы
        void computing_pipeline();

        void print_created_text();

    };


}





#endif //LAB2_WORKFLOW_H
