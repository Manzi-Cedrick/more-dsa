#include <iostream>
using namespace std;

int main()
{
    int iteration, i, j, temp, n = 6;
    int num[n] = {5, 9, 27, 55, 11, 0};
    cout << "Unsorted array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << num[i] << "\t";
    }
    for (iteration = 1; iteration < n; iteration++)
    {
        cout << "\nIteration: " << iteration << endl;
        for (int j = 0; j < n - 1; j++)
        {
            if (num[j + 1] < num[j])
            {
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
            cout << endl;
            cout << "J = " << j << endl;
            for (int k = 0; k < n; k++)
            {
                cout << num[k] << "\t";
            }
            cout << endl;
        }
    }
    cout << "\nThe sorted array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << num[i] << "\t";
    }
}