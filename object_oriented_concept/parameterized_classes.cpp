#include <iostream>
using namespace std;

class Rectangle
{
    int width, height;

public:
    Rectangle(int x, int y)
    {
        width = x;
        height = y;
    };
    int area();
};

// void Rectangle::set_values(int x, int y)
// {
//     width = x;
//     height = y;
// }

int Rectangle::area()
{
    return width * height;
}

int main()
{
    // Rectangle *rect = new Rectangle();
    // rect->set_values(5, 6);
    // cout << "area: " << rect->area() << endl;

    Rectangle r = Rectangle(5, 6);

    cout << "area: " << r.area() << endl;
    return 0;
}