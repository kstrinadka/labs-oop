//
// Created by Kirill on 08.12.2021.
//

#include "WorkerDump.h"

void lab2::WorkerDump::main_action(std::vector<std::string> &text, bool &text_is_exist) {

    const int right_number_of_arguments = 2;

    if(!text_is_exist)
    {
        throw InvalidDataCondition(false);
    }

    //проверка на нужное кол-во аргументов
    if (arguments.size() != right_number_of_arguments)
    {
        const int line = 1;
        throw InvalidArgumentAmmount(line, arguments.size(), line);
    }

    std::ofstream targetFile(arguments[1]);
    for(const auto& line : text) {
        targetFile << line << std::endl;
    }

}
