#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in the array: " << endl;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<":->";
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<"The data :->"<<arr[i];
    }
}
