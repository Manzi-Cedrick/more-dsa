#include <iostream>
using namespace std;
#define PI 3.14159
double volumeCalculate(double r){
    double volume = (4.0/3.0)*PI*r*r*r;
    return volume;
}
int main(int argc, char** argv)
{
    double radius;
    cout << "======================================== Welcome to the Volume of Sphere Program ====================================" << endl;
    cout << "Enter the radius of the sphere: ";
    cin>>radius;
    cout<<"The volume of the sphere is: "<<volumeCalculate(radius);
    return 0;
}