//
// Created by Kirill on 04.12.2021.
//

#include "WorkerReadFile.h"




namespace lab2 {


    //будем тут обрабатывать поступивший текст
    ////argument[0] - название блока
    ////argument[1], argument[2], ... - аргументы
    void WorkerReadFile::main_action(std::vector<std::string> &text, bool &text_is_exist) {

        if(text_is_exist)
        {
            //std::cout << "here" << std::endl;
            throw InvalidDataCondition(false);
        }
        text_is_exist = true;

        //проверка на нужное кол-во аргументов
        if (arguments.size() != 2)
        {
            const int line = 1;
            throw InvalidArgumentAmmount(line, arguments.size(), 1);
        }

        std::ifstream targetFile(arguments[1]);
        if(!targetFile)
        {
            throw InvalidFileName(arguments[1]);
        }

        std::string str;
        while(std::getline(targetFile, str))
        {
            text.push_back(str);
        }

    }
}