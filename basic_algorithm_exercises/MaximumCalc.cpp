#include<iostream>
using namespace std;
double maximum(double x, double y,double z)
{
    double max =x;
    if(y > max){
        max = y;
    }
    if(z > max){
        max = z;
    }
    return max;
}
int main(int argc, char** argv)
{
    cout<<maximum(1,2,3)<<" number"<<endl;
}