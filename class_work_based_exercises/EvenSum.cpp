#include <iostream>
using namespace std;

int main(){
    int sum=0;
    cout << "======================================== Welcome to the Even Numbers Sum Program ====================================" << endl;
    for(int i=0;i<100;i++){
        if(i%2 == 0){
            sum += i;
        }
    }
    cout<<"The sum of the even numbers from 0 to 100 is: "<<sum;
    return 0;
}