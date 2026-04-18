#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
void Search(Node *Root, int Item, Node *&Loc, Node *&Par)
{
    if (Root == nullptr)
    {
        Loc = nullptr;
        Par = nullptr;
        return;
    }
    if (Root->data == Item)
    {
        Loc = Root;
        Par = nullptr;
        return;
    }

    Node *Ptr, *Save;
    if (Item < Root->data)
    {
        Ptr = Root->left;
        Save = Root;
    }
    else
    {
        Ptr = Root->right;
        Save = Root;
    }
    while (Ptr != nullptr)
    {
        if (Ptr->data == Item)
        {
            Loc = Ptr;
            Par = Save;
            return;
        }
        Save = Ptr;
        if (Item < Ptr->data)
        {
            Ptr = Ptr->left;
        }
        else
        {
            Ptr = Ptr->right;
        }
    }
    Loc = nullptr;
    Par = Save; // not found but can inserted this position
}
void InBst(Node *&Root,int Item){
    Node *Loc,*Par;
    Search(Root,Item,Loc,Par);
    if(Loc!=nullptr){
        cout<<"Item is already exists in the tree.\n";
        return;
    }
    Node *newNode=new Node{Item,nullptr,nullptr};

    if(Par==nullptr){
        Root=newNode;
    }
    else if(Item<Par->data){
        Par->left=newNode;
    }
    else{
        Par->right=newNode;
    }

    if(Par) cout<<"Inserted "<<Item<<" under parent "<<Par->data<<endl;
    else cout<<"Inserted "<<Item<<" as root node \n";

}
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    // implementing bst
    Node *root = new Node{50, nullptr, nullptr};
    root->left = new Node{45, nullptr, nullptr};
    root->left->left = new Node{40, nullptr, nullptr};
    root->left->right = new Node{48, nullptr, nullptr};
    root->right = new Node{55, nullptr, nullptr};
    root->right->left = new Node{52, nullptr, nullptr};
    root->right->right = new Node{60, nullptr, nullptr};
    root->left->left->left = new Node{35, nullptr, nullptr};
    root->right->right->right = new Node{65, nullptr, nullptr};
    root->right->right->left = new Node{58, nullptr, nullptr};

    // Search
    Node *Loc, *Par;
    Search(root, 1400, Loc, Par);
    if (Loc == nullptr && Par == nullptr)
        cout << "Tree is empty;\n";
    else if (Loc == nullptr)
        cout << "Element is missing.\n It can be inserted under par :" << Par->data << "\n";
    else cout<<"The element is found in loc : "<<Loc<<" "<<"under par : " << Par->data <<endl;
    inorder(root);
    cout<<"\n";
    InBst(root,100);
    InBst(root,400);
    InBst(root,300);
    InBst(root,48);
    InBst(root,700);
    InBst(root,800);
    return 0;
}