#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int info;
    Node *left, *right;
};

// FIND procedure
void FIND(Node *ROOT, int ITEM, Node *&LOC, Node *&PAR)
{
    if (ROOT == nullptr)
    {
        LOC = nullptr;
        PAR = nullptr;
        return;
    }

    if (ITEM == ROOT->info)
    {
        LOC = ROOT;
        PAR = nullptr;
        return;
    }

    Node *PTR; //current node
    Node *SAVE; //previous node

    if (ITEM < ROOT->info)
    {
        PTR = ROOT->left;
        SAVE = ROOT;
    }
    else
    {
        PTR = ROOT->right;
        SAVE = ROOT;
    }

    while (PTR != nullptr)
    {
        if (ITEM == PTR->info)
        {
            LOC = PTR;
            PAR = SAVE;
            return;
        }

        SAVE = PTR;
        if (ITEM < PTR->info)
            PTR = PTR->left;
        else
            PTR = PTR->right;
    }

    LOC = nullptr;
    PAR = SAVE;
}

// INSBST procedure
void INSBST(Node *&ROOT, int ITEM)
{
    Node *LOC, *PAR;

    // Step 1: Find where to insert
    FIND(ROOT, ITEM, LOC, PAR);

    // Step 2: Already exists
    if (LOC != nullptr)
    {
        cout << "Item " << ITEM << " already exists in the tree!\n";
        return;
    }

    // Step 3: Create a new node
    Node *NEWNODE = new Node{ITEM, nullptr, nullptr};

    // Step 4: Attach it
    if (PAR == nullptr)
    {
        ROOT = NEWNODE; // Tree was empty
    }
    else if (ITEM < PAR->info)
    {
        PAR->left = NEWNODE;
    }
    else
    {
        PAR->right = NEWNODE;
    }

    if (PAR)
        cout << "Inserted " << ITEM << " under parent " << PAR->info << endl;
    else
        cout << "Inserted " << ITEM << " as root node" << endl;
}

// Inorder traversal for checking tree structure
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->info << " ";
    inorder(root->right);
}

int main()
{
    // Initial sample BST
    Node *root = new Node{10, nullptr, nullptr};
    root->left = new Node{5, nullptr, nullptr};
    root->right = new Node{15, nullptr, nullptr};
    root->left->left = new Node{3, nullptr, nullptr};
    root->left->right = new Node{7, nullptr, nullptr};

    cout << "Initial tree (inorder): ";
    inorder(root);
    cout << "\n";

    // Test FIND
    Node *loc, *par;
    FIND(root, 7, loc, par);
    if (loc != nullptr)
    {
        cout << "7 found. Parent = ";
        if (par)
            cout << par->info << endl;
        else
            cout << "None (root)" << endl;
    }

    // Test insertion
    cout << "\nInserting 6...\n";
    INSBST(root, 6);

    cout << "\nInserting 12...\n";
    INSBST(root, 12);

    cout << "\nTree after insertions (inorder): ";
    inorder(root);
    cout << "\n";

    return 0;
}
