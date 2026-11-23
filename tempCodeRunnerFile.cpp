
#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void InsertHead(Node* &head, int d)
{
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

int mid(Node* head)
{
    int cnt=0;
    Node* fast=head->next;
    Node* slow=head;
    while(fast!=NULL)
    {
        cnt++;
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
    }
    return cnt;
}

void deletemid(Node* &head)
{
    if(head == NULL)
    {
        return;
    }
    if(head->next == NULL)
    {
        delete head;
        head=NULL; 
        return;
    }
    int index=mid(head);
    Node* tmp = head;
    for(int i=0;i<index-1;i++)
    {
        tmp=tmp->next;
    }
    struct Node* temp = tmp->next;
    tmp->next=temp->next;
    delete(temp);
}

void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node* node1 = new Node(60);
    Node* head = node1;
    InsertHead(head,20);
    InsertHead(head,10);
    cout << "Original List: ";
    print(head);
    deletemid(head);
    cout << "new List: ";
    print(head);
    return 0;
}



// class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         if (head == NULL || head->next == NULL) {
//             delete head;
//             return NULL;
//         }
//         ListNode* slow = head;
//         ListNode* fast = head->next->next;
//         while (fast != NULL && fast->next != NULL) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         ListNode* temp = slow->next;
//         slow->next = temp->next;
//         delete temp;
//         return head;
//     }
// };
