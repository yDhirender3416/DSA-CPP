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

Node* convertArrayToCLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    mover->next=head;
    return head;
}

int lengthLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

void printCLL(Node* head){
    Node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}

Node* insertHead(Node* head, int val){
    Node* newnode=new Node(val);

    if(head==nullptr){
        newnode->next=newnode;
        return newnode;
    }

    Node* temp=head;
    //Find the last node
    while(temp->next!=head){
        temp=temp->next;
    }
    newnode->next=head;
    temp->next=newnode;
    return newnode;
}

Node* insertTail(Node* head, int val){
    Node* newnode=new Node(val);
    if(head==nullptr){
        newnode->next=newnode;
        return newnode;
    }

    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    return head;
}

Node* insertPosition(Node* head, int val, int k){
    //Edge case if CLL is empty
    if(head==nullptr){
        if(k==1){
            Node* newnode=new Node(val);
            newnode->next=newnode;
            return newnode;
        }
        else return nullptr;
    }

    //Invalid position
    if(k<1 || k>lengthLL(head)+1){
        return head;
    }

    Node* newnode=new Node(val);
    Node* temp=head;

    //Edge case if the head is to be inserted
    if(k==1){
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
        return newnode;
    }

    for(int i=0;i<k-1;i++){
        temp=temp->next;
    }

    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}

int main(){
    vector<int> arr={1,2,4,5,6};

    Node* head=convertArrayToCLL(arr);
    printCLL(head);

    // head=insertHead(head, 1);
    // printCLL(head);

    // head=insertTail(head, 12);
    // printCLL(head);

    head=insertPosition(head,3,3);
    printCLL(head);

    return 0;
}