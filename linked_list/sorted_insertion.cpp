#include <bits/stdc++.h>
using namespace std;

// Node class definition
class Node{
    public:
    int data;
    Node* next;

    //Constructor to initialize a node with data and next pointer
    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    // Constructor to initialize a node with data and set next to nullptr by default
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
    
};

// Function to convert an array to a linked list
Node* convertarraytoll(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;

    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
};

// Function to calculate the length of the linked list
int lengthLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp){
        temp=temp->next;
        cnt++;
    }
    return cnt;

}

// Function to print the linked list
void printLL(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* sortedInsertion(Node* head, int val){
    if(head==nullptr){
        return new Node(val);
    }
    if(val<head->data){
        Node* temp= new Node(val,head);
        return temp;
    }

    Node* temp=head;
    while(temp->next!=nullptr && temp->next->data<val){
        temp=temp->next;
    }
    Node* newNode=new Node(val,temp->next);
    temp->next=newNode;
    return head;
}

int main(){
    vector<int> arr={1,2,4,5,6};
    Node* head=convertarraytoll(arr);

    head=sortedInsertion(head, 7);
    printLL(head);

    return 0;
}