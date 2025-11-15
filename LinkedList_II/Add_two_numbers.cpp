/*You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/
#include <iostream>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};
void insertTail(ListNode *&head, int val)
{
    ListNode *newnode = new ListNode(val);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return;
}
void print(ListNode* head){
    if(head == NULL) return;
    ListNode* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}
ListNode* addTwoNumbers(ListNode *&l1, ListNode *&l2)
{

    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    ListNode *AnsNode = new ListNode(-1);
    ListNode *ans = AnsNode;
    int carry = 0;
    int sum, digit;
    while (l1 != NULL && l2 != NULL)
    {
        sum = carry + l1->val + l2->val;
        digit = sum % 10;
        carry = sum / 10;
        ListNode *newnode = new ListNode(digit);
        ans->next = newnode;
        ans = newnode;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL)
    {
        sum = carry + l1->val;
        digit = sum % 10;
        carry = sum / 10;
        ListNode *newnode = new ListNode(digit);
        ans->next = newnode;
        ans = newnode;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        sum = carry + l2->val;
        digit = sum % 10;
        carry = sum / 10;
        ListNode *newnode = new ListNode(digit);
        ans->next = newnode;
        ans = newnode;
        l2 = l2->next;
    }
    while (carry != 0)
    {
        sum = carry;
        digit = sum % 10;
        carry = sum / 10;
        ListNode *newnode = new ListNode(digit);
        ans->next = newnode;
        ans = newnode;
    }
    ListNode *temp = AnsNode;
    AnsNode = AnsNode->next;
    temp->next = NULL;
    delete temp;

    return AnsNode;
}
int main()
{
    int size1;
    cin >> size1;
    ListNode *head1 = NULL;
    for (int i = 0; i < size1; i++)
    {
        int x;
        cin >> x;
        insertTail(head1, x);
    }
    int size2;
    cin >> size2;
    ListNode *head2 = NULL;
    for (int i = 0; i < size2; i++)
    {
        int x;
        cin >> x;
        insertTail(head2, x);
    }
    ListNode* ans = addTwoNumbers(head1, head2);
    print(ans);
    return 0;
}
