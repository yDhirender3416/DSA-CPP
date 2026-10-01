#include <iostream>
using namespace std;

class Stack{
    int arr[100];
    int top;
    int size;

    public:
    Stack(int n){
        top=-1;
        size=n;
    }

    void push(int val){
        if(top==size-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top]=val;
    }

    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        cout<<"Element Popped: "<<arr[top]<<endl;
        top--;
    }

    int peek(){
        if(top==-1){
            cout<<"Stack empty"<<endl;
            return -1;
        }
        return arr[top];
    }
};

int main(){
    Stack s1(5);

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout<<"Peek: "<<s1.peek()<<endl;

    s1.pop();
    
    cout<<"Peek: "<<s1.peek()<<endl;
}
