/*Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
*/
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
Node* middleNode(Node* head){
    if(head == NULL) return head;
    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
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
    Node* middle = middleNode(head);
    cout<<middle->val<<endl;
    print(middle);
    return 0;
}