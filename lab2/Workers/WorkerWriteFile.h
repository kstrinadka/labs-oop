//
// Created by Kirill on 07.12.2021.
//

#ifndef LAB2_WORKERWRITEFILE_H
#define LAB2_WORKERWRITEFILE_H

#include "Worker.h"
#include <fstream>



namespace lab2 {




    class WorkerWriteFile : public Worker {
    public:

        explicit WorkerWriteFile(std::vector<std::string> &arguments) :
        lab2::Worker(arguments) {

        }


        //запись текста в нужный файл
        void main_action(std::vector<std::string> &text, bool &text_is_exist) override;

    };





}




#endif //LAB2_WORKERWRITEFILE_H
