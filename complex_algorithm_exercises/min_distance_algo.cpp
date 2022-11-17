#include<iostream>
using namespace std;

void printFactors(int *factor_arr){
    cout<<"Factors are: ";
    int len = sizeof(factor_arr) / sizeof(factor_arr[0]);
    for(int i=0;i<len;i++){
        cout<<factor_arr[i]<<endl;
    }
}
int minDistance(int x)
{
    // Fetch the factors 
    // Generate the difference between the factors 
    // Compare the smallest difference
    // return the smallest difference
    int *factor;
    for(int i=0;i<x;i++){
        if(x%i==0){
            factor[i] = i;
        }
    }
    int len = sizeof(factor) / sizeof(factor[0]);
    for(int i=0;i<len;i++){
        cout<<factor[i]<<endl;
    }
    // printFactors(factor);
}
int main(int argc, char** argv)
{
    cout<<"Register the prefered distance: ";
    int prefered_distance;
    cin >> prefered_distance;
    // Calculation of the minimum distance function
    minDistance(prefered_distance);
}