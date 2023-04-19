#include<iostream>
using namespace std;

int main()
{
    int n,sum=0;
    cout << "Enter the number of elements in the array: " ;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<":->";
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[i] >= 0){
            sum += arr[i];
        }
    }
    cout << "The sum of positive numbers: " << sum;
    return 0;
}
