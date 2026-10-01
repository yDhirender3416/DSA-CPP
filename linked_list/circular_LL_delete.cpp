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

void printCLL(Node* head){
    Node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}

int lengthLL(Node* head){
    int cnt=0;
    Node* temp=head;
    do{
        temp=temp->next;
        cnt++;
    }while(temp!=head);
    return cnt;
}

Node* deleteHead(Node* head){
    if(head==nullptr){
        return head;
    }
    
    if(head->next==head){
        delete head;
        return nullptr;
    }
    
    Node* temp=head;
    Node* last=head;

    //Find the last node
    while(last->next!=head){
        last=last->next;
    }
    last->next=head->next;
    Node* newhead=head->next;
    delete temp;
    return newhead;
}

Node* deleteTail(Node* head){
    if(head==nullptr){
        return head;
    }

    if(head->next==head){
        delete head;
        return nullptr;
    }

    Node* temp=head;
    Node* last=head;
    while(last->next->next!=head){
        last=last->next;
    }
    delete last->next;
    last->next=head;
    return head;
}

Node* deletePosition(Node* head, int k){
    //Edge case if CLL is empty
    if(head==nullptr){
        return head;
    }

    //Invalid position
    if(k<1 || k>lengthLL(head)){
        return head;
    }

    //Edge case if it is a single node CLL
    if(head->next==head){
        delete head;
        return nullptr;
    }
    
    //Edge case if the head is to be removed
    if(k==1){
        Node* last=head;

        while(last->next!=head){
            last=last->next;
        }

        Node* newhead=head->next;
        last->next=newhead;
        delete head;
        return newhead;
    }

    Node* last=head;
    int cnt=1;

    while(cnt!=k-1){
        last=last->next;
        cnt++;
    }
    Node* todelete=last->next;
    last->next=todelete->next;
    delete todelete;
    return head;
}

int main(){
    vector<int> arr={1,2,3,4,5};

    Node* head=convertArrayToCLL(arr);
    printCLL(head);

    // head=deleteHead(head);
    // printCLL(head);

    // head=deleteTail(head);
    // printCLL(head);

    head=deletePosition(head, 3);
    printCLL(head);

    return 0;
}