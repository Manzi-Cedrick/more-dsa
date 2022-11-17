#include <iostream>
using namespace std;
int main(){
    int scores[] = {52,40,75,44,88,63,75,90,78};
    int item =10,len=9,j=len-1,k=1;
    while(k<=j){
        scores[j] = scores[j-1];
        j--;
    }
    for(int i=0;i<len;i++){
        cout<<scores[i]<<endl;
    }
    
    return 0;
}