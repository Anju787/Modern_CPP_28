#ifndef IDNOTFOUND_H
#define IDNOTFOUND_H


#include <stdexcept>

class IdNotFound : public std::exception
{
private:
    std::string _msg;
public:
    IdNotFound(std::string msg) : _msg{msg} {}
    ~IdNotFound() {}
     virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _msg.c_str();
    }
};

#endif // IDNOTFOUND_H
