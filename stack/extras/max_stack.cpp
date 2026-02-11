#include<iostream>
#include <optional>
#include<stack>
#include<climits>
using namespace std;

class MaxStack{
    private:
        stack<int>stk;
        stack<int>stkM;
    public:
        void push(int x){
            if(stkM.empty()){
                stkM.push(x);
            }
            else{
                stkM.push(max(x,stkM.top()));
            }
            stk.push(x);
        }
        void pop(){
            if(stk.empty()){
                cout<<"stack is empty";
                return;
            }
            stkM.pop();
            stk.pop();
        }
        optional<int> top(){
            if(stk.empty()){
                cout<<"stack is empty";
                return nullopt;
            }
            return stk.top();
        }
        optional<int> topM(){
            if(stkM.empty()){
                cout<<"stack is empty";
                return nullopt;
            }
            return stkM.top();
        }
        void popM(){
            if(stkM.empty()){
                cout<<"stack is empty";
                return;
            }
            int max = topM();
            stack<int>buffer;
            while(!stk.empty() && top() != max){
                buffer.push(top());
                stk.pop();
                stkM.pop();
            }
            pop();
            while(!buffer.empty()){
                push(buffer.top());
                buffer.pop();
            }
        }
};

