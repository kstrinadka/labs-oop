//
// Created by Kirill on 27.11.2021.
//

#ifndef LAB2_CONFIGURATIONFILEPARSER_H
#define LAB2_CONFIGURATIONFILEPARSER_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <unordered_map>

#include "Workers/Worker.h"
#include "WorkFlow.h"
#include "Exceptions/ParseExceptions.h"
#include "Exceptions/CompileTimeException.h"



namespace lab2 {




// здесь читается входящий файл и разбирается на блоки
    class ConfigurationFileParser {
    private:
        enum class operations{read, write, grep, replace, dump, sort};

        std::unordered_map<std::string, operations>getOperation =
                {
                        {"writefile", operations::write},
                        {"readfile", operations::read},
                        {"grep", operations::grep},
                        {"sort", operations::sort},
                        {"dump", operations::dump},
                        {"replace", operations::replace}
                };


        // name of input file
        const std::string file_name;

        //просто список поступивших строк
        std::vector<std::string> lines_of_opened_file;

        //fin - поток для чтения из файла
        std::ifstream fin;

        //номер строки, в которой написано csed
        int csed_index_line = 0;

        //тут лежит последовательность узлов для обработки в workflow
        ////эта штука поступает в WorkFlow и там дальше обрабатывается
        std::vector<int> chain_of_nodes;

        //массив строк, в котором блоки
        std::vector<std::string> vector_of_blocks;

        ////эта переделывается в map_for_blocks
        std::map<int, std::string> map_prepared;

        ////эта штука поступает в WorkFlow и там дальше обрабатывается
        std::map<int, std::vector<std::string>> map_for_blocks;

        //создать массив с последовательностью выполняемых узлов
        void create_chain_of_nodes();

        void create_map_for_blocks();

        void open_file();

        void CheckBlocks();

        bool HasCorrectDescription();

        void create_blocks();

        //найти номер строки, в которой csed
        int find_csed_index_line ();

        //ищем строки с блоками схемы
        void find_strings_with_blocks();

        void read_file();

        void check_name_of_block(std::string operationName);

        void check_number_of_block(std::string word);





    public:

        //получаем имя workflow.txt
        explicit ConfigurationFileParser(std::string file_name):
        file_name(std::move(file_name)){
        }

        //ненужная функция
        void write_file();

        //распечатать, что считалосьь
        void print_input_lines ();

        //основная функция чтения файла
        void parse();

        void print_strings_with_blocks();

        void print_vector_of_blocks();

        void print_chain_of_nodes();

        void print_map();

        std::vector<int>& Getchain_of_nodes();

        std::map<int, std::vector<std::string>>& Getmap_for_blocks();

        void print_map_for_blocks ();

    };




}




#endif //LAB2_CONFIGURATIONFILEPARSER_H
