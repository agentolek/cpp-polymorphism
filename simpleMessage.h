#pragma once
#include "IMessage.h"
#include <string>

class SimpleMessage : public IMessage
{
    std::string severity;
public:
    // Virtual destructor for polymorphism
    virtual ~SimpleMessage() {}

    SimpleMessage() = default;

    // Call base class constructor
    SimpleMessage(std::string message, std::string sev) : IMessage(message) , severity(sev) {};

    // Copy constructor
    SimpleMessage(const SimpleMessage& other) 
    {
        *this = other;
    }

    // assign operator
    SimpleMessage& operator=(const SimpleMessage& other) 
    {
        if (&other != this)
        {
            messageContent = other.messageContent;
        }
        return *this;
    }

    virtual std::ostream& write(std::ostream& os) const
    {
        return (os << "Content: '" << messageContent << "' Severity: " << Severity());
    }

    std::string Severity() const
    {
        return severity;
    }
};