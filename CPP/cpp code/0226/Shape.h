#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
protected:
    double x, y;

public:
    Shape();
    Shape(double x1, double y1);
    void setX(double x1);
    void setY(double y1);
    double getX();
    double getY();
};

#endif