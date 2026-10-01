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

// Function to delete the head node of the linked list
Node* deleteHead(Node* head){
    if(head==nullptr){
        return nullptr;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

// Function to delete the tail node of the linked list
Node* deleteTail(Node* head){
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }
    Node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}

// Function to delete the k-th node of the linked list
Node* deleteK(Node* head, int k){
    //Edge case if LL is empty
    if(head==nullptr){
        return head;
    }
    //Edge case if we have to remove the head of the LL
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    
    Node* temp=head;
    Node* prev=nullptr;
    int cnt=0;

    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

// Function to delete the node with the given value in the linked list
Node* deleteByValue(Node* head, int val){
    //Edge case if LL is empty
    if(head==nullptr){
        return head;
    }
    //Edge case if we have to remove the head of the LL
    if(head->data==val){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    
    Node* temp=head;
    Node* prev=nullptr;

    while(temp!=nullptr){
        if(temp->data==val){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
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

    // Delete the head node of the linked list
    head=deleteHead(head);
    printLL(head);

    // Delete the tail node of the linked list
    head=deleteTail(head);
    printLL(head);

    // Delete the k-th node of the linked list
    head=deleteK(head, 3);
    printLL(head);

    // Delete the node with the given value in the linked list
    head=deleteByValue(head, 33);
    printLL(head);

    return 0;
}