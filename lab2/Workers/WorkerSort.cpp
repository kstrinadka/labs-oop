//
// Created by Kirill on 08.12.2021.
//

#include "WorkerSort.h"
#include <algorithm>

void lab2::WorkerSort::main_action(std::vector<std::string> &text, bool &text_is_exist) {

    if(!text_is_exist)
    {
        throw InvalidDataCondition(false);
    }

    //проверка на нужное кол-во аргументов
    if (arguments.size() != 1)
    {
        const int line = 1;
        throw InvalidArgumentAmmount(line, arguments.size(), 1);
    }

    std::sort(text.begin(), text.end());

}
