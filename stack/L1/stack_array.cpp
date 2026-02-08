#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int value): data(value), next(NULL){
    }
    ~Node(){
    }
};

class Stack{
    private:
        Node *top;
        int Size;  
    public:
        Stack(){
            top=NULL;
            Size=0;
        }
        ~Stack(){
            delete top;
        }
        void push(int val){
            Node *temp = new Node(val);
            if(temp==NULL){
                throw overflow_error("stack overflow");
            }
            temp->next=top;
            top=temp;
            Size++;
        }
        void pop(){
            if(top==NULL){
                throw underflow_error("stack underflow");
            }
            else{
                Node *temp=top;
                top=top->next;
                delete temp;
            }
        }
        int peek(){
            return top->data;
        }
        int size(){
            return Size;
        }
        int isEmpty(){
            return top==NULL;
        }
};

int main() {

    try {
        Stack stk;
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
        stk.push(20);
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
