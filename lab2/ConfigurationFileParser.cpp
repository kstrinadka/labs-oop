//
// Created by Kirill on 27.11.2021.
//

#include "ConfigurationFileParser.h"

namespace lab2 {

    int is_int(std::string word) {
        for (int i=0, n = word.size(); i<n; i++)
        {
            if (word[i] < '0' || word[i] > '9') return false;
        }
        return true;
    }

    void ConfigurationFileParser::read_file() {
        open_file();

        std::string str; // буфер промежуточного хранения считываемого из файла текста

        while (getline(fin, str))    {
            lines_of_opened_file.push_back(std::string(str));
        }

        //проверяем desc и csed
        if(!HasCorrectDescription())
        {
            throw InvalidDescriptionBlock(lines_of_opened_file[0]);
        }

        fin.close();
    }

    void ConfigurationFileParser::open_file() {
        fin.open(this->file_name);

        if(!fin.is_open()) {
            std::cout<<"wrong arguments \n";
            throw InvalidFileName(file_name);
            //throw std::exception();         // исключение обрабатывается в main.cpp
        }
    }

    void ConfigurationFileParser::write_file() {

        std::ofstream fout;

        fout.open("out.txt");

        for (int i = 0; i<lines_of_opened_file.size(); ++i){
            fout << lines_of_opened_file[i] << "\n";
        }

        fout.close();
    }

    void ConfigurationFileParser::print_input_lines() {
        for (int i=0; i<lines_of_opened_file.size(); ++i) {
            std::cout << lines_of_opened_file[i] << std::endl;
        }
    }

    void ConfigurationFileParser::parse() {
        read_file();
        create_blocks();
        create_map_for_blocks();
    }

    void ConfigurationFileParser::find_strings_with_blocks() {

        find_csed_index_line();

        for (int i = 1; i < this->csed_index_line; ++i) {
            vector_of_blocks.push_back(this->lines_of_opened_file[i]);
        }
    }

    void ConfigurationFileParser::print_strings_with_blocks() {
        this->find_strings_with_blocks();
        for (int i = 0; i < this->vector_of_blocks.size(); ++i) {
            std::cout << this->vector_of_blocks[i] << std::endl;
        }
    }

    void ConfigurationFileParser::create_chain_of_nodes() {
        std::string stroka = lines_of_opened_file[find_csed_index_line() + 1];

        std::stringstream stringstream;        //Создание потоковой переменной
        stringstream << stroka;                //Перенос строки в поток
        std::string word;

        int index = 0;
        bool afterNumber = false;

        //проверка цепи узлов на правильность и создание цепи
        while (stringstream >> word) {
            if (word != "->")
            {
                if(afterNumber)
                {
                    throw InvalidArrow(file_name, word);
                }
                afterNumber = true;

                int number;
                try
                {
                    number = std::stoi(word);
                }
                catch (std::exception&)
                {
                    throw InvalidNumber(file_name, word);
                }
                if (number <= 0)
                {
                    throw InvalidNodeNumber(number);
                }
                if (is_int(word)) {
                    this->chain_of_nodes.push_back(stoi(word));
                }
            }
            else
            {
                if(!afterNumber)
                {
                    throw InvalidNumber(file_name, word);
                }
                afterNumber = false;
            }
        }


    }

    int ConfigurationFileParser::find_csed_index_line() {
        int n = 0;
        for (int i = 0; i < this->lines_of_opened_file.size(); ++i) {
            if (this->lines_of_opened_file[i].find("csed") != std::string::npos) {
                n = i;
                break;
            }
        }
        this->csed_index_line = n;

        return n;
    }

    void ConfigurationFileParser::print_chain_of_nodes() {
        create_chain_of_nodes();

        std::cout << std::endl << "Created chain:" << std::endl;
        for (int i=0; i<chain_of_nodes.size(); i++) {
            std::cout << chain_of_nodes[i] << std::endl;
        }
    }

    void ConfigurationFileParser::create_blocks() {

        //создаем цепь блоков
        create_chain_of_nodes();

        //выделяем строки с блоками
        find_strings_with_blocks();
        //vector_of_blocks; // тут строки блоков

        //проверка блоков схемы
        CheckBlocks();


        for (auto& s : vector_of_blocks) {
            std::stringstream stringstream;        //Создание потоковой переменной
            stringstream << s;                //Перенос строки в поток
            std::string word;

            int key = 0;
            std::string stroka = "";
            while (stringstream >> word) {
                if (is_int(word)) {
                    key = stoi(word);
                } else if (word == "=") {
                    ;
                }
                else {
                    stroka += word;
                    stroka += " ";
                }
            }

            map_prepared.insert(std::pair<int,std::string>(key, stroka));
        }


    }

    void ConfigurationFileParser::print_vector_of_blocks() {
        for (auto& s : vector_of_blocks) {
            std::cout << s << std::endl;
        }
    }

    void ConfigurationFileParser::print_map() {

        for (auto it = map_prepared.begin(); it != map_prepared.end(); ++it)
        {
            std::cout << it->first << " : " << it->second << std::endl;
        }

    }

    std::vector<int> &ConfigurationFileParser::Getchain_of_nodes() {
        return this->chain_of_nodes;
    }

    std::map<int, std::vector<std::string>> &ConfigurationFileParser::Getmap_for_blocks() {
        return this->map_for_blocks;
    }

    void ConfigurationFileParser::create_map_for_blocks() {

        //перенос одной мапы в другую с разбитием аргументов на отдельные элементы вектора
        for (auto it_prepared = map_prepared.begin(); it_prepared != map_prepared.end(); ++it_prepared)
        {

            int index = it_prepared->first;

            std::string arguments = it_prepared->second;

            std::stringstream stringstream;        //Создание потоковой переменной

            stringstream << arguments;                //Перенос строки в поток
            std::string word;

            while (stringstream >> word) {
                map_for_blocks[index].push_back(word);
            }

        }
    }

    void ConfigurationFileParser::print_map_for_blocks() {
        std::cout << std::endl << "Parsed map_for_blocks:" << std::endl;
        for (auto it = map_for_blocks.begin(); it != map_for_blocks.end(); ++it)
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

    bool ConfigurationFileParser::HasCorrectDescription() {

        bool foundStart = false;
        bool foundEnd = false;

        //проверяем desc и csed
        for (auto& currentLine : lines_of_opened_file) {
            if(currentLine == "desc" && foundStart == false)
            {
                foundStart = true;
            }
            else
            {
                if (currentLine == "desc")
                {
                    return false;
                }
            }
            if(currentLine == "csed" && foundStart == true && foundEnd == false)
            {
                foundEnd = true;
            }
            else
            {
                if(currentLine == "csed")
                {
                    return false;
                }
            }
        }



        return foundStart && foundEnd;
    }

    void ConfigurationFileParser::CheckBlocks() {
        //Проверка блоков на правильность (вынести в отдельную функцию)
        for (auto& s : vector_of_blocks) {
            std::stringstream stringstream;
            stringstream << s;
            std::string word;
            stringstream >> word;
            int key = -1;
            int descLine = 1;   //номер блока

            try
            {
                key = std::stoi(word);
            }
            catch(std::exception&)
            {
                std::stringstream ss;
                ss << key;
                std::string str = ss.str();
                throw InvalidNumber(file_name, str);
            }
            if(key <= 0)
            {
                std::stringstream ss;
                ss << key;
                std::string str = ss.str();
                throw InvalidNumber(file_name, str);
            }

            std::string assignment;
            stringstream >> assignment;
            if(assignment != "=")
            {
                throw InvalidAssignmentSign(descLine, assignment);
            }

            std::unordered_map<std::string, operations>getOperation
                    {
                            {"writefile", operations::write},
                            {"readfile", operations::read},
                            {"grep", operations::grep},
                            {"sort", operations::sort},
                            {"dump", operations::dump},
                            {"replace", operations::replace}
                    };
            std::string operationName;
            stringstream >> operationName;
            try
            {
                operation = getOperation.at(operationName);
            }
            catch(std::out_of_range&)
            {
                throw InvalidOperationName(file_name, operationName);
            }

            descLine++;
        }
    }

}





