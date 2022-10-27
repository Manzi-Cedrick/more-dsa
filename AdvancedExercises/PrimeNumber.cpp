#include <iostream>
using namespace std;

int ProductPrimeCalc(int limit)
{
    int product = 1;
    int j, i = 1,count;
    for (i = 1; i <= 100; i++)
    {
        count = 0;
        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                count++;
            cout << i << " is  number" << endl;
                break;
            }
        }
        if (count == 0 && i != 1)
        {
            // cout << i << " Prime Number" << endl;
            cout << "count"<<count;
        }
    }
    return product;
}
int main()
{
    cout << "======================================== Welcome to the Prime Numbers Program ====================================" << endl;
    cout << "The Product of prime numbers between 1 and 20 is: " << ProductPrimeCalc(20);
}