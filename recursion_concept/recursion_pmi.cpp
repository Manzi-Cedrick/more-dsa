#include<iostream>
using namespace std;

int factorial(int n){
    // Base Case
    if(n==0) return 1;
    // Recursive assumption
    int smallFact = factorial(n-1);
    // Induction Step
    return n * smallFact;
}
int main(){
    cout<<factorial(5);
    return 0;
}