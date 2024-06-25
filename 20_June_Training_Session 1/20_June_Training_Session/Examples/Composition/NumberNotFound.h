#ifndef NUMBERNOTFOUND_H
#define NUMBERNOTFOUND_H

#include <stdexcept>

class NumberNotFound : public std::exception
{
private:
    std::string _msg;
public:
    NumberNotFound(std::string msg) : _msg{msg} {}
    NumberNotFound()=delete;
    NumberNotFound(const NumberNotFound&)=default;
    NumberNotFound& operator=(const NumberNotFound&)=delete;
    NumberNotFound& operator=(NumberNotFound&&)=delete; 
    NumberNotFound(NumberNotFound&&)=default; //enable move otherwise we can't the
    ~NumberNotFound()=default;
     virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _msg.c_str();
    }
};

#endif // NUMBERNOTFOUND_H
