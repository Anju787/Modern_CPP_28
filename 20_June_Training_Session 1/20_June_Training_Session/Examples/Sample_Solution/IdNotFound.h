#ifndef IdNotFound_H
#define IdNotFound_H


#include <stdexcept>

class IdNotFound : public std::exception
{
private:
    std::string _msg;
public:
    IdNotFound(std::string msg) : _msg{msg} {}
    IdNotFound()=delete;
    IdNotFound(const IdNotFound&)=default;
    IdNotFound& operator=(const IdNotFound&)=delete;
    IdNotFound& operator=(IdNotFound&&)=delete; 
    IdNotFound(IdNotFound&&)=default; //enable move otherwise we can't the
    ~IdNotFound()=default;
     virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _msg.c_str();
    }
};

#endif // IdNotFound_H
