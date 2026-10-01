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

int lengthLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

int main(){
    vector<int> arr={12,25,33,40,51};
    
    // Constructing a linked list object from the array
    Node* n1=new Node(arr[0],nullptr);
    cout<<n1->data<<endl;

    //Converting the array to linked list
    Node* head=convertarraytoll(arr);
    cout<<head->data<<endl;

    //Traversing the linked list
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    //Calculating the length of the linked list
    int len=lengthLL(head);
    cout<<endl<<len<<endl;

    return 0;
}
