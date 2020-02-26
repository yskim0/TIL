#include "Shape.h"

class Square : public Shape
{
private:
    double size;

public:
    Square();
    Square(double x1, double y1);
    Square(double x1, double y1, double t_size);
    double getSquareArea();
};