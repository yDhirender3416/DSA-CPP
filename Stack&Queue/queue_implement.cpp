#include <iostream>
using namespace std;

class Queue{
    int arr[100];
    int front;
    int rear;
    int size;

    public:
    Queue(int n){
        front=-1;
        rear=-1;
        size=n;
    }

    void enqueue(int val){
        //Check overflow condition
        if(rear==size-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }

        if(front==-1){
            front=0;
        }

        rear++;
        arr[rear]=val;
    }

    void dequeue(){
        //Check underflow condition
        if(front==-1 || front>rear){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        front++;
    }

    int peek(){
        //Check underflow condition
        if(front==-1 || front>rear){
            cout<<"Queue empty"<<endl;
            return -1;
        }
        return arr[front];
    }
};

int main(){
    Queue q1(5);

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);

    cout<<"Peek: "<<q1.peek()<<endl;

    q1.dequeue();
    
    cout<<"Peek: "<<q1.peek()<<endl;

    return 0;
}