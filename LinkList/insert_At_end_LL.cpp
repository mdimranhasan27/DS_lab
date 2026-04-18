#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
void insertEnd(Node*& head,int value){
    Node *ptr=head,*prv=NULL;
    while(ptr!=NULL){
        prv=ptr;
        ptr=ptr->next;
    }
    Node *newNode=new Node();
    newNode->data=value;
    newNode->next=NULL;
    prv->next=newNode;
}
void Traverse(Node *head){
    Node *ptr=head;
    cout<<"LL elements: ";
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<"\n";
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
    Traverse(head);
    insertEnd(head,6);
    Traverse(head);

    return 0;
}