//
// Created by Kirill on 29.11.2021.
//

#ifndef LAB2_WORKER_H
#define LAB2_WORKER_H


#include <iostream>
#include <vector>
#include "../Exceptions/CompileTimeException.h"
#include "../Exceptions/RuntimeExceptions.h"



namespace lab2 {




//отсюда унаследуем другие блоки
    class Worker {


    public:

        //поступают аргументы
        explicit Worker(std::vector<std::string> &arguments) :
        arguments(arguments)
        {

            this->arguments = arguments;

        }

        virtual ~Worker() = default;

        void print_data();

        //поступает текст для преобразования
        virtual void main_action(std::vector<std::string> &text, bool &text_is_exist) = 0;


    protected:

        std::vector<std::string> arguments;

    };


}




#endif //LAB2_WORKER_H
