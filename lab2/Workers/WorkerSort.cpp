//
// Created by Kirill on 08.12.2021.
//

#include "WorkerSort.h"
#include <algorithm>

void lab2::WorkerSort::main_action(std::vector<std::string> &text, bool &text_is_exist) {

    const int right_number_of_arguments = 1;

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

    std::sort(text.begin(), text.end());

}
