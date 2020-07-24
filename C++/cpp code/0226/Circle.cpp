#include "Circle.h"

Circle::Circle() : Shape(), radius(1)
{
}

Circle::Circle(double x1, double y1) : Shape(x1, y1), radius(1)
{
}

Circle::Circle(double x1, double y1, double t_radius) : Shape(x1, y1), radius(t_radius)
{
}

double Circle::getCircleArea()
{
    return radius * radius * 3.14;
}