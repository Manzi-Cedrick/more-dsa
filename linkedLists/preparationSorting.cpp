#include <iostream>
using namespace std;

void bubbleSort(int *a, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < i; j++)
        {
            /* code */
            if (a[j + 1] < a[j])
            {
                temp = a[j + 1];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
    return x,y;
}
void insertionSort(int *a, int n)
{
    int i, key, j;
    for (int i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j] = key;
    }
}
void selectionSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int targetIndex = i;
        for (int j = i+1; j < n; j++)
        {
            if(a[j]<a[targetIndex]){
                targetIndex=j;
            }
            swap(a[i],a[targetIndex]);
        }
    }
}
int partition(int *a,int s,int e){
    int pivot = a[e];
    int i =s ;
    for (int j = s; j < e-1; j++)
    {
        if(a[j]<pivot){
            swap(a[i],a[j]);
            i++;
        }
    }
    swap(a[i],a[e]);
    return i;
}
int QuickSort(int *a,int s,int e){
    int p = partition(a,s,e);
    QuickSort(a,s,p-1);
    QuickSort(a,p+1,p);
}
void merge(int *a,int s,int e){
    int mid = (s+e) / 2;
    int i = s;
    int j = mid+1;
    int k = s;
    int temp[100];
    while(i<=mid && j<=e){
        if(a[i]<a[j]){
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=e){
        temp[k++] = a[j++];
    }
    // return temp;
}
void mergeSort(int *a,int s,int e){
    int mid = (s+e) / 2;
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);
    return merge(a,s,e);
}
int main()
{
    int a[100] = {12, 12, 12312, 123};
}