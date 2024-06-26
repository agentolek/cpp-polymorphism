#include "singleDirList.h"
#include "IMessage.h"
#include <iostream>


class Logger
{
    SDList<std::shared_ptr<IMessage>> myList;
public:
    ~Logger(){ myList.clear(); };
    Logger() = default;

    void addMessage(IMessage* mess)
    {
        myList.pushFront(mess->clone());
    }

    void removeMessage()
    {
        myList.popFront();
    }

    void clear()
    {
        myList.clear();
    }

    friend std::ostream& operator<<(std::ostream& os, const Logger& log)
    {
        return (os << log.myList);
    }
};