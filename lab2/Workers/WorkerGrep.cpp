//
// Created by Kirill on 08.12.2021.
//

#include "WorkerGrep.h"



////argument[0] - название блока
////argument[1], argument[2], ... - аргументы
void lab2::WorkerGrep::main_action(std::vector<std::string> &text, bool &text_is_exist) {

    if(!text_is_exist)
    {
        throw InvalidDataCondition(false);
    }

    //проверка на нужное кол-во аргументов
    if (arguments.size() != 2)
    {
        const int line = 1;
        throw InvalidArgumentAmmount(line, arguments.size(), 1);
    }

    std::vector<std::string>newData;
    for(const auto& line : text)
    {
        std::stringstream words(line);
        std::string currentWord;

        while(words >> currentWord)
        {
            if(currentWord == arguments[1])
            {
                newData.push_back(line);
                break;
            }
        }
    }

    text = newData;

}
