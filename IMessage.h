#include <string>
#include <iostream>

class IMessage
{
protected:
    std::string messageContent = "";
public:
    // Default constructor
    IMessage() = default;

    IMessage(const std::string& message) : messageContent(message) {};

    // Virtual destructor for polymorphism
    virtual ~IMessage() {}

    // Copy constructor
    IMessage(const IMessage& other) {}

    // assign operator
    IMessage& operator=(const IMessage& other) {}
    virtual std::string Severity() = 0;
    virtual std::ostream& write(std::ostream& os) = 0;
};