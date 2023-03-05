


// Mohamed Azouz
// 900225230
// point.cpp

#include "point.hpp"


point:: point()
{// Default Constructor, sets X = Y = 0
    x=0;
    y=0;
}
point:: point(float x1, float y1)
{// Overloaded Constructor. Initializes both X and Y.
    x=x1;y=y1;
}
void point::setX(float n)
{// Setter which takes a float to set the value of the X
    x = n;
}
void point::setY(float n)
{// Setter which takes a float to set the value of the Y
    y = n;
}
float point::getX()
{//Getter gets value of x-coordinate
    return x;
}
float point::getY()
{//Getter gets value of y-coordinate
    return y;
}
void point::display()
{// Display point as (x , y)
    cout<<"("<<x<<", "<<y<<")"<<endl;
}
float point::distance(point p)
{// Calculates and returns the distance between the current point and another point p
    return sqrt(pow(x-p.getX(),2)+pow(y-p.getY(),2));
}
