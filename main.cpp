#include "singleDirList.h"
#include "Logger.h"
#include "simpleMessage.h"
#include "userMessage.h"
#include <iostream>
using namespace std;

int main()
{
    SDList<float> lst;
    if (!lst.empty())
        cout << "Error in empty() for empty list.\n";
    if (lst.size() != 0)
        cout << "Error in size() for empty list.\n";
    lst.pushFront(7.2f);
    if (lst.size() != 1)
        cout << "Error in size() for one-element list.\n";
    lst.pushFront(2.4f);
    if (lst.size() != 2)
        cout << "Error in size() for two-element list.\n";

    cout << lst << "\n";

    for (auto &v : lst)
        v *= 2;
    cout << lst << '\n';

    SDList<float>::iterator it = lst.begin();
    cout << "Pierwszy: " << *it << "\n";
    ++it;
    cout << "Drugi: " << *it << "\n";
    ++it;

    // Why no tests for Logger?
    // Logger is basically just an overlay for SDList, and whether the classes themselves work is
    // seen by what they print out, which is best tested via this method.

    // Logger accepts members of any class which derives from IMessage.
    Logger myLog;

    SimpleMessage mess1("OK1", "Info");
    UserMessage mess2("OK2", "Info", 12);
    SimpleMessage mess3("OK3", "Info");
    UserMessage mess4(mess2);

    UserMessage mess5("Test", "Error", 0);
    SimpleMessage mess6("Test", "Error");

    // Expected message order (from top) - 2, 2, 1, 3
    
    // check assignment operator
    myLog.addMessage(&mess3);
    mess3 = mess6;
    myLog.addMessage(&mess1);
    myLog.addMessage(&mess1);
    myLog.removeMessage();
    myLog.addMessage(&mess2);
    mess2 = mess5;
    myLog.addMessage(&mess4);
    mess4 = mess5;
    cout << myLog;

    // See if clear works
    myLog.clear();
    cout << myLog;
    return 0;
}