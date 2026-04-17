#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
void traverse(struct Node *head)
{
    struct Node *ptr = head;
    cout << "Print LL elements :  ";
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}
void search(struct Node *head, int target)
{
    struct Node *ptr = head;
    bool found=false;
    int cnt = 0;

    while (ptr != NULL)
    {
        cnt++;
        if (ptr->data == target)
        {
            found = true;
            break;
        }
        ptr = ptr->next;
    }
    if (found)
        cout << "The element is " << ptr->data << " in pos " << cnt << "\n";
    else
        cout << "The element is missing.\n";
}
// Sort linked list (Bubble Sort)
void sortLL(Node *head)
{
    if (head == NULL) return;

    for (Node *i = head; i != NULL; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                swap(i->data, j->data);
            }
        }
    }
}

int main()
{
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    traverse(head);
   // int target;
   // cin >> target;
    //search(head, target);
    sortLL(head);
    traverse(head);
    return 0;
}