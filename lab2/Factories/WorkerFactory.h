//
// Created by Kirill on 04.12.2021.
//

#ifndef LAB2_WORKERFACTORY_H
#define LAB2_WORKERFACTORY_H


#include "../Workers/Worker.h"


namespace lab2 {





    //Тут будет создаваться объект класса Worker
    //в наследника будут создаваться конкретные блоки (возвращать их)
    class WorkerFactory {
    public:



        //создает нужный блок-наследник
        virtual Worker* FactoryMethod(std::vector<std::string> &arguments) const = 0;
    };





}


#endif //LAB2_WORKERFACTORY_H
