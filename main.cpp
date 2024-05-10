#include "singleDirList.h"
#include "Logger.h"
#include "simpleMessage.h"
#include "userMessage.h"
#include <iostream>
using namespace std;

int main()
{
    // Logger accepts members of any class which derives from IMessage.
    Logger myLog;

    SimpleMessage mess1("message1", "Error");
    UserMessage mess2("message2", "Update", 12);
    myLog.addMessage(&mess1);
    myLog.addMessage(&mess2);
    cout << myLog;
    myLog.clear();
    cout << myLog;
    return 0;
}