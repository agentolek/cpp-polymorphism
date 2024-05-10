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

    SimpleMessage mess1("message1", "Error");
    UserMessage mess2("message2", "Info", 12);
    SimpleMessage mess3("message3", "Warning");

    // check copy constructor
    UserMessage mess4(mess2);
    
    // check assignment operator
    myLog.addMessage(&mess3);
    mess3 = mess1;
    myLog.addMessage(&mess3);
    myLog.addMessage(&mess1);
    myLog.addMessage(&mess2);
    myLog.addMessage(&mess4);
    cout << myLog;
    myLog.clear();
    cout << myLog;
    return 0;
}