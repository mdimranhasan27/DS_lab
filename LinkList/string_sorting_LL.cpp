#include <bits/stdc++.h>
using namespace std;


struct Node {
    string data;
    struct Node *next;
};

void Traverse(struct Node *head) {
    struct Node *ptr = head;
    while (ptr != NULL) {
         cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    printf("\n");
}

void sortList(struct Node *head) {
    struct Node *i, *j;
    

    for (i = head; i != NULL; i=i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                swap(i->data,j->data);
            }
        }
    }
}

int main() {
    struct Node *head=NULL,*temp=NULL,*newNode=NULL;
    int i,n;
    string value;
   cin>>n;
    for(int i=0;i<n;i++){
        cin>>value;
        newNode=new Node();
        newNode->data=value;
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
            temp=head;
        }
        else
        {
            temp->next=newNode;
            temp=temp->next;
        }

    }
    printf("Before sorting:\n");
    Traverse(head);

    sortList(head);
    
    printf("After sorting:\n");
    Traverse(head);

    return 0;
}
