//
// Created by Kirill on 08.12.2021.
//

#ifndef LAB2_RUNTIMEEXCEPTIONS_H
#define LAB2_RUNTIMEEXCEPTIONS_H

#include <exception>
#include <string>


namespace lab2 {


    class RuntimeError : public std::exception
    {
    public:
        RuntimeError() = default;
    };



    class InvalidFileName final : public RuntimeError
    {
    public:
        explicit InvalidFileName(std::string name):
                fileName(std::move(name)){}
    private:
        std::string fileName;
    };



    class InvalidDataCondition final : public RuntimeError
    {
    public:
        explicit InvalidDataCondition(const bool isFilled):
                isFilled(isFilled){}
    private:
        bool isFilled;
    };



    class InvalidNodeNumber final : public RuntimeError
    {
    public:
        explicit InvalidNodeNumber(const int wrongNumber):
                wrong(wrongNumber){}
    private:
        int wrong;
    };



}


#endif //LAB2_RUNTIMEEXCEPTIONS_H
