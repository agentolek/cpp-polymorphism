#include "single_dir_list.h"
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

    // for (sdlist<float>::iterator it = lst.begin(); it != lst.end(); ++it )
    //     *it *= 2;

    for (auto &v : lst)
        v *= 2;
    cout << lst << '\n';

    SDList<float>::iterator it = lst.begin();
    cout << "Pierwszy: " << *it << "\n";
    ++it;
    cout << "Drugi: " << *it << "\n";
    ++it;
    return 0;
}