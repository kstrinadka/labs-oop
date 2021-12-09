//
// Created by Kirill on 08.12.2021.
//

#ifndef LAB2_PARSEEXCEPTIONS_H
#define LAB2_PARSEEXCEPTIONS_H

#include <exception>
#include <string>

namespace lab2 {


    class ParsingError : public std::exception
    {
    public:
        explicit ParsingError(std::string name):
                fileName(std::move(name)){}
    private:
        std::string fileName;
    };



    class InvalidDescriptionBlock final : public ParsingError
    {
    public:
        explicit InvalidDescriptionBlock(const std::string& name):
                ParsingError(name){}
    };



    class InvalidNumber final : public ParsingError
    {
    public:
        InvalidNumber(const std::string& fileName, std::string notInteger):
                ParsingError(fileName),
                notInteger(std::move(notInteger)){}
    private:
        std::string notInteger;
    };



    class InvalidOperationName final : public ParsingError
    {
    public:
        InvalidOperationName(const std::string& fileName, std::string name):
                ParsingError(fileName),
                operationName(std::move(name)) {}
    private:
        std::string operationName;
    };



    class InvalidArrow final : public ParsingError
    {
    public:
        InvalidArrow(const std::string& fileName, std::string word):
                ParsingError(fileName),
                notArrow(std::move(word)){}
    private:
        std::string notArrow;
    };



}

#endif //LAB2_PARSEEXCEPTIONS_H
