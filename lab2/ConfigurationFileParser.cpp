//
// Created by Kirill on 27.11.2021.
//

#include "ConfigurationFileParser.h"

namespace lab2 {

    int is_int(std::string word) {
        const char zero = '0';
        const char nine = '9';


        for (int i=0, n = word.size(); i<n; i++)
        {
            if (word[i] < zero || word[i] > nine) return false;
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
            throw InvalidFileName(file_name);
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



    void ConfigurationFileParser::create_chain_of_nodes() {
        int number_of_string_with_chain_of_nodes = find_csed_index_line() + 1;

        std::string stroka = lines_of_opened_file[number_of_string_with_chain_of_nodes];

        std::stringstream stringstream;        //Создание потоковой переменной
        stringstream << stroka;                //Перенос строки в поток
        std::string word;

        bool afterNumber = false;
        const std::string arrow = "->";

        //проверка цепи узлов на правильность и создание цепи
        while (stringstream >> word) {
            if (word != arrow)
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
        const std::string csed = "csed";
        int n = 0;
        for (int i = 0; i < this->lines_of_opened_file.size(); ++i) {
            if (this->lines_of_opened_file[i].find(csed) != std::string::npos) {
                n = i;
                break;
            }
        }
        this->csed_index_line = n;

        return n;
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
            const std::string equal_sign = "=";
            const std::string space = " ";

            int key = 0;
            std::string stroka = "";
            while (stringstream >> word) {
                if (is_int(word)) {
                    key = stoi(word);
                } else if (word == equal_sign) {
                    ;
                }
                else {
                    stroka += word;
                    stroka += space;
                }
            }

            map_prepared.insert(std::pair<int,std::string>(key, stroka));
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


    bool ConfigurationFileParser::HasCorrectDescription() {

        bool foundStart = false;
        bool foundEnd = false;
        const std::string desc = "desc";
        const std::string csed = "csed";

        //проверяем desc и csed
        for (auto& currentLine : lines_of_opened_file) {
            if(currentLine == desc && foundStart == false)
            {
                foundStart = true;
            }
            else
            {
                if (currentLine == desc)
                {
                    return false;
                }
            }
            if(currentLine == csed && foundStart == true && foundEnd == false)
            {
                foundEnd = true;
            }
            else
            {
                if(currentLine == csed)
                {
                    return false;
                }
            }
        }



        return foundStart && foundEnd;
    }

    void ConfigurationFileParser::CheckBlocks() {
        //Проверка блоков на правильность (вынести в отдельную функцию)
        int descLine = 1;   //номер блока
        const std::string equal_sign = "=";

        for (auto& s : vector_of_blocks) {

            std::stringstream stringstream;
            stringstream << s;
            std::string word;
            stringstream >> word;


            check_number_of_block(word);

            std::string assignment;
            stringstream >> assignment;




            if(assignment != equal_sign)
            {
                throw InvalidAssignmentSign(descLine, assignment);
            }


            std::string operationName;
            stringstream >> operationName;

            check_name_of_block(operationName);

            descLine++;
        }
    }

    void ConfigurationFileParser::check_name_of_block(std::string operationName) {
        try
        {
            getOperation.at(operationName);
        }
        catch(std::out_of_range&)
        {
            throw InvalidOperationName(file_name, operationName);
        }
    }

    void ConfigurationFileParser::check_number_of_block(std::string word) {
        int key = -1;
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
    }


}





