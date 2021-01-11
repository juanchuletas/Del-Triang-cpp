#include <iostream>
#include "LinkedList.hpp"

int main()
{
    double myData[] = {2.0,3.0,4.0};
    double mySecond = 3.0;
    LinkedList<double> list(myData[0]);
    list.append(myData[1]);
    list.insertNextItem(myData[2]);
    list.insertFirstItem(mySecond);

    printL(list);
    list.dropFirstItem();
    std::cout<<"New list\n";
    printL(list);
    return 0;
}