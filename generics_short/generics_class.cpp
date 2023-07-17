#include <iostream>
using namespace std;

template <typename T>
class Pair
{
    T x;
    T y;

public:
    void setX(T x)
    {
        this->x = x;
    }
    void setY(T y)
    {
        this->y = y;
    }
    T getX()
    {
        return x;
    }
    T getY()
    {
        return y;
    }
};
int main()
{
    Pair<int> p1;
    p1.setX(1);
    p1.setY(2);
    Pair<double> p2;
    p2.setX(4.9);
    p2.setY(2.1);
    cout << p1.getX() << " " << p2.getY() << endl;
    return 0;
}