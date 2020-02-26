#include "Shape.h"

Shape::Shape() : x(0), y(0)
{
}

Shape::Shape(double x1, double y1) : x(x1), y(y1)
{
}

void Shape::setX(double x1)
{
    x = x1;
}

void Shape::setY(double y1)
{
    y = y1;
}

double Shape::getX()
{
    return x;
}

double Shape::getY()
{
    return y;
}