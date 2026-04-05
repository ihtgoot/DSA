#include<iostream>
#include<vector>
using namespace std;

class max_Heap {
    int *arr;
    int total_capacity;
    int size;

    void heapify(int idx){
    }

    public:
    
    max_Heap(int n): total_capacity(n), size(0){
        arr = int[n];
    }

    void insert(int val){
        if(size==total_capacity){
            throw std::overflow_error("heap overflow")
        }
        arr[size]=val;
        int idx = size;
        size++;
        while(idx >0 && arr[idx])

    }

    int pop(){
    }

    void print(){
        
    }
};

int main(){
    int n;
    cin>>n;
    max_Heap Mheap(n);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        Mheap.insert(k);
    }
    Mheap.print();
    cout<<Mheap.pop()<<endl;
    Mheap.print();
}