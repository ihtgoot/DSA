#include<iostream>
#include<vector>
using namespace std;

class max_Heap {
    int *arr;
    int size;
    int total_size;
    
    void heapify(int idx){
        int largest = idx;
        int leftChild = 2*idx+1;
        int rightChild= 2*idx+2;
        if(leftChild < size && arr[leftChild]>arr[largest])
            largest = leftChild;
        if(rightChild < size && arr[rightChild]>arr[largest])
            largest = rightChild;
        if(largest != idx){
            swap(arr[largest],arr[idx]);
            heapify(largest);
        }
    }

    public:
    
    max_Heap(int n): size(0), total_size(n){
        arr = new int[n];
    }

    void insert(int n){
        if(size==total_size){
            throw std::overflow_error("heap is full");
        }
        arr[size] = n;
        cout<<"insert_works"<<endl;
        int idx = size;
        int parent = (idx-1)/2;
        while(idx>0 && arr[parent]<arr[idx]){
            swap(arr[parent],arr[idx]);
            idx=parent;
            parent=(idx-1)/2;
        }
        size++;
    }

    int pop(){
        if(size==0){
            throw underflow_error("heap underflow");
        }
        int top = arr[0];
        arr[0]=arr[size-1];
        size--;
        heapify(0);
        return top;
    }

    void print(){
        int a = 0;
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
            if(a%2==0)
                cout<<endl;
            a++;
        }
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