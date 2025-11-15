#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void insertAtTail(Node* &head, int val){
    Node* newnode = new Node(val);
    if(head == NULL){
        head = newnode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    return;
}
Node* getNodeAtPosition(Node* &head, int pos) {
    Node* curr = head;
    for(int i=1; curr != NULL && i < pos; i++){
        curr = curr->next;
    }
    return curr;
}
void deletingNode(Node* &head,Node* node){
    
    if(node == NULL) return;
    if(node->next == NULL){
        if (node == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while(temp->next != node){
            temp = temp->next;
        }
        temp->next = NULL;
        delete node;
        return;
    }
    Node* temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    delete temp;
}
bool searchNode(Node* &head, int val){
    if(head == NULL) return false;
    Node* temp = head;
    while(temp != NULL){
        if(temp->val == val){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void print(Node* &head){
    if(head == NULL) return;
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    return;
}
int main(){
    Node* head = NULL;
    int s;
    cin>>s;
    for(int i = 0; i<s; i++){
        int x;
        cin>>x;
        insertAtTail(head, x);
    }  
    int pos;
    cin>>pos;
    Node* deleteNode = NULL;
    deleteNode = getNodeAtPosition(head, pos);
    deletingNode(head,deleteNode);
    print(head);
    int val;
    cout<<"enter value to be found:";
    cin>>val;
    bool ans = searchNode(head, val);
    cout<<endl<<ans<<endl;
    return 0;
}