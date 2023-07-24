#include <iostream>
using namespace std;
#include "circular.h"

int main()
{
    CircularLL c;

    c.insert(1); c.insert(2); c.print();
    c.insert(3); c.remove(1); c.print();
    c.insert(4); c.insert(5); c.insert(6);
    c.insert(7); c.remove(5); c.print();
}