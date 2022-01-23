//
// Created by Kirill on 08.12.2021.
//

#include "WorkerReplace.h"

void lab2::WorkerReplace::main_action(std::vector<std::string> &text, bool &text_is_exist) {

    const int right_number_of_arguments = 3;

    if(!text_is_exist)
    {
        throw InvalidDataCondition(false);
    }

    //проверка на нужное кол-во аргументов
    if (arguments.size() != right_number_of_arguments)
    {
        const int line = 1;
        throw InvalidArgumentAmmount(line, arguments.size(), 1);
    }

    for (auto& line : text)
    {
        std::stringstream words(line);
        std::string word, old_word, new_word;
        std::string newLine;

        old_word = arguments[1];
        new_word = arguments[2];
        const std::string space = " ";

        while(words >> word)
        {
            if (!newLine.empty())
            {
                newLine += space;
            }
            if(word == old_word)
            {
                newLine += new_word;
            }
            else
            {
                newLine += word;
            }
        }
        line = newLine;
    }

}
