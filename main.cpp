#include "singleDirList.h"
#include "Logger.h"
#include "simpleMessage.h"
#include "userMessage.h"
#include <iostream>
using namespace std;

int main()
{
    // Why no tests for Logger?
    // Logger is basically just an overlay for SDList, and whether the classes themselves work is
    // seen by what they print out, which is best tested via this method.

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