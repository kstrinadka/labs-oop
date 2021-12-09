//
// Created by Kirill on 08.12.2021.
//

#ifndef LAB2_COMPILETIMEEXCEPTION_H
#define LAB2_COMPILETIMEEXCEPTION_H


#include <exception>
#include <string>
#include <utility>


namespace lab2 {


    class CompileError : public std::exception
    {
    public:
        explicit CompileError(const int line):lineNumber(line){}
    private:
        int lineNumber;
    };



    class InvalidBlockNumber final : public CompileError
    {
    public:
        InvalidBlockNumber(const int line, std::string name):
                CompileError(line),
                wrongNumber(std::move(name)){}
    private:
        std::string wrongNumber;
    };



    class InvalidAssignmentSign final : public CompileError
    {
    public:
        InvalidAssignmentSign(const int line, std::string sign):
                CompileError(line),
                wrongSign(std::move(sign)){}
    private:
        std::string wrongSign;
    };



    class InvalidArgumentAmmount final : public CompileError
    {
    public:
        InvalidArgumentAmmount(const int line, const size_t ammount, const size_t expected):
                CompileError(line),
                ammount(ammount),
                expected(expected){}
    private:
        size_t ammount;
        size_t expected;
    };




}

#endif //LAB2_COMPILETIMEEXCEPTION_H
