#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> reminder_arr;
void countOnes(int x)
{
    int a,y,i=0;
    int reminder_arr[]{};
    for(int j=0;x>0;j++){
        reminder_arr[j] = x%2;
        x /= 2;
    }
    int length = sizeof(reminder_arr) / sizeof(reminder_arr[0]);
    for(int i=0;i<length;i++){
        cout<<reminder_arr[i]<<endl;
    }
}
int main()
{
    cout<<"Enter the number: ";
    int num;
    cin>>num;
    countOnes(num);
}