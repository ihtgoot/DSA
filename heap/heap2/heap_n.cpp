#include<iostream>
using namespace std;

void Heapify(int arr[],int idx,int n){
    int L = idx;
    int l = 2*idx+1;
    int r = 2*idx+2;
    if(l<n && arr[l]>arr[L]){
        L = l;
    }
    if(r<n && arr[r]>arr[L]){
        L = r;
    }
    if(L!=idx){
        swap(arr[idx],arr[L]);
        Heapify(arr,L,n);
    }
}

void BuildMaxHeap(int arr[], int n){
    for(int i=(n/2)-1;i>=0;i--){
        Heapify(arr,i,n);
    }
}

int main(){
    int arr[] = {10,3,8,9,5,13,18,14,11,70};
    BuildMaxHeap(arr,10);

    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}