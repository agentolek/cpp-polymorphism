#pragma once
#include "IMessage.h"

class SimpleMessage : public IMessage
{
    std::string sevText;
public:
    // Virtual destructor for polymorphism
    virtual ~SimpleMessage() {}

    SimpleMessage() = default;

    // Call base class constructor
    SimpleMessage(const std::string& message, const std::string& sev) : IMessage(message) , sevText(sev) {};

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
            setSeverity(other.severity());
        }
        return *this;
    }

    virtual std::ostream& write(std::ostream& os) const override
    {
        return (os << "Content: '" << messageContent << "' Severity: " << severity());
    }

    void setSeverity(const std::string& newSev)
    {
        sevText = newSev;
    }

    std::string severity() const
    {
        return sevText;
    }

    virtual std::shared_ptr<IMessage> clone() const override
    {
        return std::make_shared<SimpleMessage>(*this);
    }
};