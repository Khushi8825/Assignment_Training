// Given the head of a linked list, rotate the list to the right by k places.
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
void print(ListNode *head)
{
    if (head == NULL)
        return;
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}
int length(ListNode *head)
{
    int count = 0;
    if (head == NULL)
        return count;
    ListNode *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL)
        return head;
    int len = length(head);
    k = k % len;
    if (k == 0)
        return head;
    int pos = len - k - 1;
    ListNode *temp = head;
    while (pos > 0)
    {
        temp = temp->next;
        pos--;
    }
    ListNode *newlast = temp;
    ListNode *newhead = temp->next;
    newlast->next = NULL;
    temp = newhead;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    return newhead;
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
    int k;
    cin >> k;
    ListNode *ans = rotateRight(head1, k);
    print(ans);
    return 0;
}