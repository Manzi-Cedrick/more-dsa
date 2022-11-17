#include<iostream>
using namespace std;

int main(){
    int array[]{14,3,4,6,7,41,56,11,25,9},max,min;
    max=array[0];
    min=array[0];
    for(int i=0;i<12;i++){
        if(array[i]>max){
            max=array[i];
        }
        if(array[i]<min){
            min=array[i];
        }
    }
    cout<<"The maximum number: "<<max<<endl;
    cout<<"The minimum number: "<<min<<endl;
}