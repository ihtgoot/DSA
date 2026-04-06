#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&arr,int idx, int size){
    int L = idx;
    int l = idx*2+1;
    int r = idx*2+2;
    if(l<arr.size() && arr[l]<arr[L]){
        L=l;
    }
    if(r<arr.size() && arr[r]<arr[L]){
        L=r;
    }
    if(L!=idx){
        swap(arr[L],arr[idx]);
        heapify(arr,L,size);
    }
}

void sortHeapSort(vector<int>&arr){
    int n = arr.size();
    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,0,i);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sortHeapSort(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}