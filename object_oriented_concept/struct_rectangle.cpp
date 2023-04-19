#include<iostream>
using namespace std;

struct Rectangle
{
    /* data */
    int width;
    int heigth;
    int area ( ) {
        return width * heigth;
    }
};

int main(){
    Rectangle rect;
    rect.heigth = 50;
    rect.width = 20;
    cout<< "AREA:"<<rect.area();
}