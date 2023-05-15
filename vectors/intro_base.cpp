#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> arr)
{
    int s = arr.size();
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    vector<int> vector1 = {1, 2, 3, 4};
    vector<int> vector2{1, 2, 5, 7, 9};
    // display(vector1);
    // display(vector2);
    cout << vector2.capacity() << endl;
    cout << vector2.size();
}