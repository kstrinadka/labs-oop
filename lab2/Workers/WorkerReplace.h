//
// Created by Kirill on 08.12.2021.
//

#ifndef LAB2_WORKERREPLACE_H
#define LAB2_WORKERREPLACE_H
#include "Worker.h"
#include <sstream>

namespace lab2 {

    class WorkerReplace : public Worker {
    public:
        explicit WorkerReplace(std::vector<std::string> &arguments) :
        lab2::Worker(arguments) {

        }

        //запись текста в нужный файл
        void main_action(std::vector<std::string> &text, bool &text_is_exist) override;

    };

}



#endif //LAB2_WORKERREPLACE_H
