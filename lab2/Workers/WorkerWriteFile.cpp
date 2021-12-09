//
// Created by Kirill on 07.12.2021.
//

#include "WorkerWriteFile.h"


////argument[0] - название блока
////argument[1], argument[2], ... - аргументы
void lab2::WorkerWriteFile::main_action(std::vector<std::string> &text, bool &text_is_exist) {

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
    for(const auto& line : text)
    {
        targetFile << line << std::endl;
    }

    text_is_exist = false;

}
