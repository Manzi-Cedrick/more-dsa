#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int s, int e)
{
    int i = s;
    int pivot = a[e];
    for (int j = s; j <= e - 1; j++)
    {
        if (a[j] < pivot)
        {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[e]);
    return i;
}

void quickSort(int a[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(a, s, e);
    quickSort(a, s, p - 1);
    quickSort(a, p + 1, e);
}

int main()
{

    int a[] = {2, 1, 3, 4, 5, 7, -2};
    quickSort(a, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
