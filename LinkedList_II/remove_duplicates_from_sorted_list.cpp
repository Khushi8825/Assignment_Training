// Given the head of a sorted linked list, delete all duplicates such that each 
// element appears only once.
//  Return the linked list sorted as well.
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
ListNode* deleteDuplicates(ListNode* head) {
        // If the list is empty or has only one node, return it
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Pointer to traverse the list
        ListNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                // Skip the duplicate node
                current->next = current->next->next;
            } else {
                // Move to the next node
                current = current->next;
            }
        }

        return head;
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
    ListNode* ans = deleteDuplicates(head1);
    print(ans);
    return 0;
}