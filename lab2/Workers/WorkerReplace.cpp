//
// Created by Kirill on 08.12.2021.
//

#include "WorkerReplace.h"

void lab2::WorkerReplace::main_action(std::vector<std::string> &text, bool &text_is_exist) {

    if(!text_is_exist)
    {
        throw InvalidDataCondition(false);
    }

    //проверка на нужное кол-во аргументов
    if (arguments.size() != 3)
    {
        const int line = 1;
        throw InvalidArgumentAmmount(line, arguments.size(), 1);
    }

    for (auto& line : text)
    {
        std::stringstream words(line);
        std::string word;
        std::string newLine;
        while(words >> word)
        {
            if (!newLine.empty())
            {
                newLine += " ";
            }
            if(word == arguments[1])
            {
                newLine += arguments[2];
            }
            else
            {
                newLine += word;
            }
        }
        line = newLine;
    }

}
