#include<iostream>
using namespace std;

class Stack{
    private:
        int *arr;
        int capacity;
        int top;
        bool flag;

    public:
    
    Stack(int capacity): top(-1), capacity(capacity){
        arr = new int[capacity];
        flag=0;
    }

    ~Stack(){
        delete []arr;
    }

    void push(int value){
        if(top==capacity-1){
            throw overflow_error("Stack Overflow");
        }
        else{
            top++;
            arr[top]=value;
            cout<<arr[top]<<" is pushed into stack"<<endl;
            flag=1;
        }
    }

    void pop(){
        if(top==-1){
            throw underflow_error("Stack Underflow");
        }
        else{
            int o = arr[top];
            top--;
            cout<<o<<" is poped out of stack"<<endl;
        }
    }

    int size(){
        return top+1;
    }

    int peek(){
        if(top==-1){
            throw underflow_error("Stack is empty");
        }
        return arr[top];
    }

    bool isEmpty(){
        return top==-1;
    }

    void resize() {
        capacity *=2;
        int * newArr = new int[capacity];
        for(int i=0;i<=top;i++){
            newArr[i]=arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
};

int main() {

    try {
        int n;
        cin >> n;

        Stack stk(n);

        // Test 1: Empty stack
        if (!stk.isEmpty() || stk.size() != 0) {
            cout << "FAIL: stack should be empty initially\n";
            return 0;
        }

        // Test 2: Push + Peek
        stk.push(10);
        if (stk.peek() != 10 || stk.size() != 1) {
            cout << "FAIL: push/peek broken\n";
            return 0;
        }

        // Test 3: Multiple pushes
        stk.resize();
        stk.push(20);
        stk.resize();
        stk.push(30);
        if (stk.peek() != 30 || stk.size() != 3) {
            cout << "FAIL: LIFO broken\n";
            return 0;
        }

        // Test 4: Pop
        stk.pop(); // removes 30
        if (stk.peek() != 20 || stk.size() != 2) {
            cout << "FAIL: pop broken\n";
            return 0;
        }

        // Test 5: Pop until empty
        stk.pop(); // removes 20
        stk.pop(); // removes 10
        if (!stk.isEmpty() || stk.size() != 0) {
            cout << "FAIL: empty state broken\n";
            return 0;
        }

        // Test 6: Underflow
        try {
            stk.pop();
            cout << "FAIL: underflow not detected\n";
            return 0;
        } catch (const underflow_error&) {
            // expected
        }

        // Test 7: Overflow
        Stack small(2);
        small.push(1);
        small.push(2);
        try {
            small.push(3);
            cout << "FAIL: overflow not detected\n";
            return 0;
        } catch (const overflow_error&) {
            // expected
        }

        cout << "ALL TESTS PASSED\n";
    }
    catch (const exception& e) {
        cout << "UNEXPECTED ERROR: " << e.what() << endl;
    }

    return 0;
}
/*
cd "/media/ihtgoot/toshiba_ext/DataStructureAndAlgorithm/DSA/stack/L1/" && g++ stack_array.cpp -o stack_array && "/media/ihtgoot/toshiba_ext/DataStructureAndAlgorithm/DSA/stack/L1/"stack_array
1

10 is pushed into stack
20 is pushed into stack
30 is pushed into stack
30 is poped out of stack
20 is poped out of stack
10 is poped out of stack
1 is pushed into stack
2 is pushed into stack
ALL TESTS PASSED
*/