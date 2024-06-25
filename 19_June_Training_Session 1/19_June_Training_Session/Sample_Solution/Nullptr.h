#ifndef NULLPTR_H
#define NULLPTR_H

#include <stdexcept>

class NullPtr : public std::exception
{
private:
    std::string _msg;
public:
    NullPtr(std::string msg) : _msg{msg} {}
    ~NullPtr() {}
     virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _msg.c_str();
    }
};

#endif // NULLPTR_H
