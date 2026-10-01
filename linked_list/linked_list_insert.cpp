#include <bits/stdc++.h>
using namespace std;

//Node class definition
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    // Constructor to initialize a node with data and set next to nullptr
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

// Function to insert a node at the head of the linked list
Node* insertHead(Node* head, int val){
    Node* temp=new Node(val,head);
    return temp;
}

//Function to insert a node at the tail of the linked list
Node* insertTail(Node* head, int val){
    if(head==nullptr){
        return new Node(val);
    }
    
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=new Node(val);
    return head;
}

//Function to insert a node at a given position of the linked list
Node* insertPosition(Node* head, int val, int k){
    //Edge case if the LL is empty
    if(head==nullptr){
        if(k==1){
            return new Node(val);
        }
        else{
            return nullptr;
        }
    }
    //Edge case if the head is to be inserted
    if(k==1){
        Node* temp=new Node(val,head);
        return temp;
    }

    Node* temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k-1){
            Node* newNode = new Node(val,temp->next);
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
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
    vector<int> arr={12,25,33,40,51};
    
    Node* head=convertarraytoll(arr);

    // Inserting a node at the head of the linked list
    head=insertHead(head, 10);
    printLL(head);

    // Inserting a node at the tail of the linked list
    head=insertTail(head, 60);
    printLL(head);

    // Inserting a node at a given position of the linked list
    head=insertPosition(head, 30, 3);
    printLL(head);

    return 0;
}