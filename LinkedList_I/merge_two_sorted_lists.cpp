/*You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by
splicing together the nodes of the first two lists.

Return the head of the merged linked list.*/
#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};
void InsertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}
void print(Node *&head)
{
    if (head == NULL)
        return;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}
Node* mergeSortedList(Node* list1, Node* list2){
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    if(list1->val <= list2->val){
        list1->next = mergeSortedList(list1->next, list2);
        return list1;
    }
    else{
        list2->next = mergeSortedList(list1, list2->next);
        return list2;
    }
}
int main()
{
    int size1;
    cin >> size1;
    Node* list1 = NULL;
    for (int i = 0; i < size1; i++)
    {
        int x;
        cin >> x;
        InsertAtTail(list1, x);
    }
    int size2;
    cin >> size2;
    Node* list2 = NULL;
    for (int i = 0; i < size2; i++)
    {
        int x;
        cin >> x;
        InsertAtTail(list2, x);
    }
    Node* merged = mergeSortedList(list1, list2);
    print(merged);
    return 0;
}