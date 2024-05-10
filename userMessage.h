#pragma once
#include "simpleMessage.h"

class UserMessage : public SimpleMessage
{
    int id;
public:
    // Virtual destructor for polymorphism
    virtual ~UserMessage() {}

    UserMessage(const std::string& message, const std::string& sev, int userId) : SimpleMessage(message, sev), id(userId) {};

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
            setSeverity(other.severity());
            id = other.id;
        }
        return *this;
    }

    virtual std::ostream& write(std::ostream& os) const override
    {
        return (os << "From id: " << id << ", '" << messageContent << "' Tag: " << severity());
    }

    virtual std::shared_ptr<IMessage> clone() const override
    {
        return std::make_shared<UserMessage>(*this);
    }
};