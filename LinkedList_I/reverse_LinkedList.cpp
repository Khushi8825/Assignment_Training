/*Given the head of a singly linked list, reverse the list, and return the reversed list.*/
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};

void InsertAtTail(Node* &head, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp->next;
    }
    temp->next=newNode;
    return;
}
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
void print(Node* &head){
    if(head == NULL) return;
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}
int main(){
    int size;
    cin>>size;
    Node* head = NULL;
    for(int i = 0;i<size; i++)
    {
        int x;
        cin>>x;
        InsertAtTail(head, x);
    }
    print(head);
    head = reverse(head);
    print(head);
    return 0;
}