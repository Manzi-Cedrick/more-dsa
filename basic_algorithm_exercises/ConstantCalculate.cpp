#include<iostream>
using namespace std;
#define PI 3.14159265
int main()
{
    float radius;
    cout << "Enter the radius rate: ";
    cin>>radius;
    double Area = PI * (radius * radius);
    /* Calculating the area of a circle. */
    cout<<"The Area is: "<<Area<<endl;
    double diameter = radius * 2;
    double Circ = PI * diameter;
    cout<<"The Circumference is: "<<Circ;
    return 0;
}