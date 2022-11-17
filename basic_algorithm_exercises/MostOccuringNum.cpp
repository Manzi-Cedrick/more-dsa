#include<iostream>
using namespace std;

int CheckMostOcuringNumber(int *number,int length){
    int occuringNumber ,count,maxCount=0;
    for(int i=0;i<length;i++){
        count =1 ;
        for(int j=i+1;j<length;j++){
            count++;
            if(count>maxCount){
                occuringNumber = number[j];
            }
        }
    }
    return occuringNumber;
}
int main (){

    int number[] = {4,2,3,4,2,3,4,2,3,4,3,4,2,4};
    int length = sizeof(number) / sizeof(number[0]);
    int result  = CheckMostOcuringNumber(number,length);
    cout<<"The Most Occuring Number: "<<result;
    return 0;
}