#ifndef ACCOUNTNOTFOUND_H
#define ACCOUNTNOTFOUND_H

#include <iostream>

class AccountNotFound:public std::exception
{
private:
    std::string _msg;
public:
    AccountNotFound(std::string msg) {
        _msg=msg;
    }
    ~AccountNotFound() {}
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _msg.c_str();
    }
};

#endif // ACCOUNTNOTFOUND_H
