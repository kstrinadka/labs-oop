//
// Created by Kirill on 04.12.2021.
//

#ifndef LAB2_WORKERREADFILE_H
#define LAB2_WORKERREADFILE_H

#include "Worker.h"
#include <fstream>



namespace lab2 {





    class WorkerReadFile: public lab2::Worker {


    public:
        explicit WorkerReadFile(std::vector<std::string> &arguments):
        lab2::Worker(arguments)
        {

        }

        void main_action(std::vector<std::string> &text, bool &text_is_exist) override;
    };





}


#endif //LAB2_WORKERREADFILE_H
