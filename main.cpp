



// Mohamed Azouz
// 900225230
// main.cpp

#include <iostream>
#include "point.hpp"
#include <ctime>
using namespace std;


point Center(point *C, int n) // Center function calculates the center of a cluster of points *C of size n
{
    point A; // point A is used to return a point at the end
    float totalX=0,totalY=0; // Total variables for x and y coordinates to calculate the average coordinates at the end.
    for(int i=0;i<n;i++) //for loop loops from 0 to n so that all points in the cluster are considered.
    {
        A = *(C+i); // point A is set to equal each point in the dynamic array to avoid indirection errors while using pointers.
        totalX += A.getX(); // The x coordinate of the current point is added to the total of all x coordinates.
        totalY += A.getY(); // The y coordinate of the current point is added to the total of all y coordinates.
    }
    A.setX(totalX/n); // point A is given the average x coordinate to calculate the center.
    A.setY(totalY/n); // point A is given the average y coordinate to calculate the center.
    return A; // point A, the center, is returned.
}

void Closest(point *A, point *B, int n, point p) // Function Closest accepts two clusters, the number of points in each cluster, and a point p for the distance to be calculated from.
{
    point a = Center(A,n); // point a stores the center of cluster A
    point b = Center(B,n); // point b stores the center of cluster B
    
    float dA = a.distance(p); // a float variable, dA, stores the distance between the center of cluster A and the point p
    float dB = b.distance(p); // a float variable, dB, stores the distance between the center of cluster B and the point p
    
    if(dA<dB) // if statement outputs which cluster point p is closer to.
        cout<<"Cluster A is closer to point P than cluster B"<<endl<<endl;
    else if(dB<dA)
        cout<<"Cluster B is closeer to point P than cluster A"<<endl<<endl;
    else
        cout<<"Both clusters are equidistant from point P"<<endl<<endl;
}

int main()
{
    int n=20; // integer variable n is the size of the clusters A and B. It can be changed or made so the user may input it.
    point *A,*B; // Two clusters, A and B, are created as pointers.
    A = new point[n]; // The pointers are turned into dynamic arrays of size n.
    B = new point[n];
    srand((unsigned)time(0)); // The srand function is used to refresh the random number generated by the rand() function everytime.
    point x; // a point, x, is createed. This point will be used in the for loop to make the code more readable and understandable. It could be replaced by another form.
    for(int i=0;i<n;i++) // The for loop iterated from i = 0 to i = n, which allows it to access every element of the dynamic arrays A and B.
    {
        x.setX(rand()%20+70); // the point x is given a random x-coordinate between 70 and 90
        x.setY(rand()%20+70); // the point x is given a random y-cooredinate between 70 and 90
        *(A+i) = x; // the element in the dynamic array at location [i] is given the values of point x.
        x.setX(rand()%20+70); // the point x is given a random x-coordinate between 70 and 90
        x.setY(rand()%20+70); // the point x is given a random y-cooredinate between 70 and 90
        *(B+i) = x; // the element in the dynamic array at location [i] is given the values of point x.
    }
    
    point *p; // A new dynamic array, p, is created to store all the points which will be checked through the code to see which cluster they are closest to.
    int m=20; // integer m is the size of the array p.
    p = new point[m]; // pointer p is turned into a dynamic array of size m.
    
    for(int i=0;i<m;i++) // the for loop iterates from the beginning to the end of dynamic array p.
    {
        x.setX(rand()%20+70); // point x is given a random x-coordinate.
        x.setY(rand()%20+70); // point y is given a random y-coordinate
        *(p+i) = x; // the point in the array p at location i is given the random x and y coordinates of point x between 70 and 90.
    }
    
    for(int i=0;i<m;i++)// the for loop iterates from the beginning to the end of dynamic array p.
    {
        cout<<"The point: ";
        (*(p+i)).display(); // the point is displayed to allow the user to check the calculations
        Closest(A,B,n,x); // the function is used to calculate which cluster the point at location i in dynamic array p is closest to.
    }
}