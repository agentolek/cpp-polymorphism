#include "IMessage.h"

class SimpleMessage : public IMessage
{
public:
    // Virtual destructor for polymorphism
    virtual ~SimpleMessage() {}

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
    }
    std::string Severity() 
    {
        return "Info";
    }

    std::ostream& write(std::ostream& os)
    {
        return (os << messageContent << ' ');
    }
};