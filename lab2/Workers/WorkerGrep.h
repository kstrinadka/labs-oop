//
// Created by Kirill on 08.12.2021.
//

#ifndef LAB2_WORKERGREP_H
#define LAB2_WORKERGREP_H

#include "Worker.h"
#include <sstream>


namespace lab2 {




    class WorkerGrep: public Worker {
    public:
        explicit WorkerGrep(std::vector<std::string> &arguments):
        lab2::Worker(arguments)
                {

                }

        void main_action(std::vector<std::string> &text, bool &text_is_exist) override;

    };





}



#endif //LAB2_WORKERGREP_H
