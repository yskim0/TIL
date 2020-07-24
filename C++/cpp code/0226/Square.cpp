#include "Square.h"

Square::Square() : Shape(), size(1)
{
}

Square::Square(double x1, double y1) : Shape(x1, y1), size(1)
{
}

Square::Square(double x1, double y1, double t_size) : Shape(x1, y1), size(t_size)
{
}

double Square::getSquareArea()
{
    return size * size;
}