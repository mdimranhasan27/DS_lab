#include <bits/stdc++.h>
using namespace std;

const int SIZE = 11;

int hashTable[SIZE];

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert using Linear Probing
void insert(int key) {
    int index = hashFunction(key);

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

// Search
int search(int key) {
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return index;

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    return -1;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            cout << i << " -> EMPTY\n";
        else
            cout << i << " -> " << hashTable[i] << "\n";
    }
}

int main() {
    // Initialize table
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    int data[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};

    for (int x : data)
        insert(x);

    cout << "Hash Table:\n";
    display();

    int key;
    cout << "\nEnter element to search: ";
    cin >> key;

    int pos = search(key);

    if (pos != -1)
        cout << "Found at index " << pos << endl;
    else
        cout << "Not found\n";

    return 0;
}