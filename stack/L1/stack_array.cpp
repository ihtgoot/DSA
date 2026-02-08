#include<iostream>
using namespace std;

class Stack{
    private:
        int *arr;
        int capacity;
        int top;

        void grow() {
            capacity *=2;
            int * newArr = new int[capacity];
            for(int i=0;i<top;i++){
                newArr[i]=arr[i];
            }
            delete[] arr;
            arr = newArr;
        }

    public:
    
    Stack(int capacity): top(-1), capacity(capacity){
        arr = new int[capacity];
    }

    ~Stack(){
        delete []arr;
    }

    void push(int value){
        if(top==capacity){
            throw overflow_error("Stack Overflow");
        }
        else{
            top++;
        }
    }

    void pop(){
        if(top==-1){
            throw underflow_error("Stack Underflow");
        }
        else{
            top--;
        }
    }

    int size(){
        return top;
    }

    int peek(){
        if(top==-1){
            throw underflow_error("Stack Underflow");
        }
        return arr[top];
    }

    bool isEmpty(){
        return top==-1;
    }

}

int main(){
    
}