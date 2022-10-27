#include <iostream>
using namespace std;
int main(){
    int scores[] = {52,78,75,68,88,63,75,90,78};
    int item =10,k=3,len=9,j=len-1;
    for(int z=len-1;z>k;z--){
        scores[z] = scores[z-1];
    }
    scores[k-1] = item;
    len++;
    for(int i=0;i<len;i++){
        cout<<scores[i]<<endl;
    }
    return 0;
}