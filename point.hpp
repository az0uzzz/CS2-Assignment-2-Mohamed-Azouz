



// Mohamed Azouz
// 900225230
// point.hpp

#ifndef point_hpp
#define point_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>

#endif /* point_hpp */
using namespace std;

class point {

private:
// Data members x and y
float x;
float y;
public:
    point();
    point(float x1, float y1);
    void setX(float n);
    void setY(float n);
    float getX();
    float getY();
    void display();
    float distance(point p);
    // All functions are defined in the public section.
};
