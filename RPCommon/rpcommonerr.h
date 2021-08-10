#pragma once
#include <iostream>

class RPInvalidCastException : public std::exception
{
public:
    RPInvalidCastException(int errCode, const std::string& message) noexcept : errCode(errCode), m_errMsg(message)
    {
        
    }
    virtual ~RPInvalidCastException() = default;
    virtual const char* what() const noexcept override
    {
        return this->m_errMsg.c_str();
    }
    int GetCode()
    {
        return errCode;
    }
    int errCode;
private:
    std::string m_errMsg;
};
