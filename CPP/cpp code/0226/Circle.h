#include "Shape.h"

class Circle : public Shape
{
private:
    double radius;

public:
    Circle();
    Circle(double x1, double y1);
    Circle(double x1, double y1, double t_radius);
    double getCircleArea();
};