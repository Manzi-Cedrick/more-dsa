#include<iostream>
using namespace std;

int* varArray(int n){
    int i,j,count;
    int *array;
    while(n!=0){
        i=n%10;
        n=n/10;
        varArray(n);
        count++;
        // cout<<i;
        array[count] = i;
        // while(j>=0){
        //     array[j] = i;
        // }
    }
    return array;
}
int main(){

    int num =233345;
    int i,j,count=0;
    int *array;
    while(num!=0){
        i=num%10;
        num=num/10;
        // varArray(n);
        count++;
        // cout<<i;
        array[count] = i;
        // while(j>=0){
        //     array[j] = i;
        // }
    }
    int length = sizeof(array)/ sizeof(array[0]);
    for(int i;i<length;i++){
        cout<<array[i];
    }
}