#pragma once
#include "simpleMessage.h"
#include <string>

class UserMessage : public SimpleMessage
{
    int id;
public:
    // Virtual destructor for polymorphism
    virtual ~UserMessage() {}

    UserMessage(std::string message, std::string sev, int userId) : SimpleMessage(message, sev), id(userId) {};

    // Copy constructor
    UserMessage(const UserMessage& other) 
    {
        *this = other;
    }

    // assign operator
    UserMessage& operator=(const UserMessage& other) 
    {
        if (&other != this)
        {
            messageContent = other.messageContent;
        }
        return *this;
    }

    virtual std::ostream& write(std::ostream& os) const
    {
        return (os << "From id: " << id << ", '" << messageContent << "' Tag: " << Severity());
    }
};