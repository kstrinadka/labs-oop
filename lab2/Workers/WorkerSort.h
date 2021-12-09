//
// Created by Kirill on 08.12.2021.
//

#ifndef LAB2_WORKERSORT_H
#define LAB2_WORKERSORT_H

#include "Worker.h"




namespace lab2 {




    class WorkerSort : public Worker {

    public:

        explicit WorkerSort(std::vector<std::string> &arguments) :
        lab2::Worker(arguments) {

        }


        //запись текста в нужный файл
        void main_action(std::vector<std::string> &text, bool &text_is_exist) override;

    };




}




#endif //LAB2_WORKERSORT_H
