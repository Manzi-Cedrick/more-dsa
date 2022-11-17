#include <iostream>
using namespace std;

void SwapInputs(double inp1, double inp2){
    double temp1;
    temp1 = inp1;
    inp1 = inp2;
    inp2 = temp1;
    cout<<"After swapping the first input : "<<inp1<<endl;
    cout<<"After swapping the second input : "<<inp2<<endl;
}
int main(int argc, char** argv)
{
    cout << "======================================== Welcome to the Swapping Program ====================================" << endl;
    double input1,input2;
    cout << "Input 1st number: ";
    cin >> input1;
    cout << "Input 2nd number: ";
    cin >> input2;
    SwapInputs(input1,input2);
    return 0;
}