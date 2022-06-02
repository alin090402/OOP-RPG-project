//
// Created by ALIN on 06.05.2022.
//

#ifndef RPG_EXCEPTION_H
#define RPG_EXCEPTION_H


#include <stdexcept>

class DataException: public std::runtime_error {
public:
    explicit DataException(const std::string &arg) : runtime_error(arg) {}
};
class FileException: public std::runtime_error {
public:
    explicit FileException(const std::string &arg) : runtime_error(arg) {}
};

class BugException: public std::runtime_error{
public:
    explicit BugException(const std::string &arg) : runtime_error(arg){}
};

class BuilderException: public std::runtime_error{
public:
    explicit BuilderException(const std::string &arg): std::runtime_error(arg){}
};


#endif //RPG_EXCEPTION_H
