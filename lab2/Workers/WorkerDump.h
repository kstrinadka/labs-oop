//
// Created by Kirill on 08.12.2021.
//

#ifndef LAB2_WORKERDUMP_H
#define LAB2_WORKERDUMP_H

#include "Worker.h"
#include <fstream>


namespace lab2 {



    class WorkerDump : public Worker {

    public:
        explicit WorkerDump(std::vector<std::string> &arguments):
        lab2::Worker(arguments)
                {

                }

        void main_action(std::vector<std::string> &text, bool &text_is_exist) override;

    };


}



#endif //LAB2_WORKERDUMP_H
