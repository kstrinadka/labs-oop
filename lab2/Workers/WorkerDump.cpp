//
// Created by Kirill on 08.12.2021.
//

#include "WorkerDump.h"

void lab2::WorkerDump::main_action(std::vector<std::string> &text, bool &text_is_exist) {

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

    std::ofstream targetFile(arguments[1]);
    for(const auto& line : text) {
        targetFile << line << std::endl;
    }

}
