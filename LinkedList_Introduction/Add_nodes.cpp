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
    Node* newHead = new Node(val);
    if(head == NULL){
        head = newHead;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newHead;
    return;
}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    return;
}

//Function to get count of nodes in a linked list
//TC = O(n);
//SC = O(1)
int count(Node* head){
    int c = 0;
    Node* temp = head;
    while(temp != NULL){
        c++;
        temp = temp->next;
    }
    return c;
}
int main(){
    Node* head = NULL;

    int size;
    cin >> size;

    for(int i = 0; i < size; i++){
        int x;
        cin>>x;
        InsertAtTail(head, x);
    }

    print(head);
    cout<<endl;
    int cnt = count(head);
    cout<<"Size of List: "<<cnt<<endl;
    return 0;
}