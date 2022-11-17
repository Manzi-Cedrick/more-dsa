#include<iostream>
using namespace std;

int daphine_array(int daphine_arr[], int size){
    int result[size],result_check;
    for(int i=0; i<size; i++){
       if(daphine_arr[i] % 2 == 0){
            for(int j=0;j<size;j++){
                result[j] = daphine_arr[i];
                cout<<":-"<<result[j]<<endl;
                if(result[j] == daphine_arr[i]){
                    result_check = 1;
                    return result_check;
                }
            }
       }
    }
    return result_check;
}   
int main(int argc, char** argv)
{
    int sizeNum;
    cout<<"Declare the array size: ";
    cin>>sizeNum;
    int exec_array[sizeNum];
    for(int i=0;i<sizeNum;i++){
        cout<<"->";
        cin>>exec_array[i];
    }
    int result = daphine_array(exec_array,sizeNum);
    if(result == 1){
        cout<<"Daphine array"<<endl;
    }
}