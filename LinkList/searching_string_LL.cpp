#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node* next;
};

void search(Node* head, string target) {
    Node* ptr = head;
    int cnt = 0;
    bool found = false;

    while (ptr != NULL) {
        cnt++;
        if (ptr->data == target) {
            found = true;
            cout << target << " is in the list at position " << cnt << endl;
            break;
        }
        ptr = ptr->next;
    }

    if (!found) {
        cout << target << " is not in the list at any position." << endl;
    }
}

void Traverse(Node* head) {
    Node* ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string value;
        cin >> value;

        newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    cout << "Traverse List :" << endl;
    Traverse(head);

    cout << "Which element do you want to search:" << endl;
    string x;
    cin >> x;

    search(head, x);

    return 0;
}