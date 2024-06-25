#ifndef NOVALIDPOINTER_H
#define NOVALIDPOINTER_H


#include <stdexcept>

class NoValidPointer : public std::exception
{
private:
    std::string _msg;
public:
    NoValidPointer(std::string msg) : _msg{msg} {}
    NoValidPointer()=delete;
    NoValidPointer(const NoValidPointer&)=default;
    NoValidPointer& operator=(const NoValidPointer&)=delete;
    NoValidPointer& operator=(NoValidPointer&&)=delete; 
    NoValidPointer(NoValidPointer&&)=default; //enable move otherwise we can't the
    ~NoValidPointer()=default;
     virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _msg.c_str();
    }
};

#endif // NOVALIDPOINTER_H
