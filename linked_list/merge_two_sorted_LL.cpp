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

//Function to find the length of a linked list
int lengthLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

Node* mergeLL(Node* head1, Node* head2){
    Node* dummynode=new Node(-1);
    Node* temp=dummynode;

    Node* t1=head1;
    Node* t2=head2;

    while(t1!=nullptr && t2!=nullptr){
        if(t1->data<t2->data){
            temp->next=t1;
            temp=t1;
            t1=t1->next;
        }
        else{
            temp->next=t2;
            temp=t2;
            t2=t2->next;
        }
    }

    if(t1!=nullptr){
        temp->next=t1;
    }
    else if(t2!=nullptr){
        temp->next=t2;
    }
    return dummynode->next;
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

int main(){
    vector<int> arr1={1,2,3,4,5};
    vector<int> arr2={2,5,7,10,15,18};

    Node* head1=convertarraytoll(arr1);
    Node* head2=convertarraytoll(arr2);

    Node* head=mergeLL(head1,head2);
    printLL(head);

    return 0;
}