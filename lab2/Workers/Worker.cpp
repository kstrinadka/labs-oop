//
// Created by Kirill on 29.11.2021.
//

#include "Worker.h"




namespace lab2 {

    void Worker::print_data() {
        std::cout << std::endl << "arguments of Worker:" << std::endl;
        for (auto it = this->arguments.begin(); it != arguments.end(); ++it)
        {
            std::cout << *it << "\n";
        }
        std::cout <<std::endl;
    }


}