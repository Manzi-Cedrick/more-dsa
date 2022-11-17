#include <iostream>
using namespace std;

int main()
{
    int arr[]{12, 55, 5, 18};

    int length = 1;

    for (int i = 0; i < length; i++)
    {
        for(int j = i + 1; j < length; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int k = 0; k < sizeof(arr)/sizeof(arr[0]); k++)
    {
        cout << arr[k] << " ";
    }
}