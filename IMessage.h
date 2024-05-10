#pragma once
#include <string>
#include <iostream>

class IMessage
{
protected:
    std::string messageContent = "";
public:
    // Default constructor
    IMessage() = default;

    IMessage(std::string message) : messageContent(message) {};

    // Virtual destructor for polymorphism
    virtual ~IMessage() {}

    // Copy constructor
    IMessage(const IMessage& other) 
    {
        *this = other;
    }

    // assign operator
    IMessage& operator=(const IMessage& other) 
    {
        if (this != &other)
        {
            messageContent = other.messageContent;
        }
        return *this;
    };

    // severity as a pure virtual function to create abstract interface 
    virtual std::string Severity() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const IMessage* mess)
    {
        return mess->write(os);
    }

    virtual std::ostream& write(std::ostream& os) const = 0;
};