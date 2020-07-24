#include <iostream>
#include "Square.h"
#include "Circle.h"
using namespace std;

int main()
{

    Square s1(2, 1, 5);
    Circle c1(3, 4, 2);
    cout << s1.getSquareArea() << endl;
    cout << c1.getCircleArea() << endl;

    return 0;
}