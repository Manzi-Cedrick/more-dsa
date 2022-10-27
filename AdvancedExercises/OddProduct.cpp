#include <iostream>
using namespace std;

int OddCalculate(int limit){
    int product = 1;
    for(int i=1;i<=limit;i++){
        if(i%2 != 0){
            product *= i;
        }
    }

    return product;
}
int main(){
    cout << "======================================== Welcome to the Odd Numbers Product Program ====================================" << endl;
    cout<<"The product of the odd numbers between 1 and 20 is: "<< OddCalculate(20);
    return 0;
}