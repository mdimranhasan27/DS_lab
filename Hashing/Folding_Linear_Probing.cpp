#include <bits/stdc++.h>
using namespace std;

#define SIZE 11

int hashTable[SIZE];

// Folding hash function (2-digit folding)
int foldingHash(int key) {
    int sum = 0;

    while (key > 0) {
        sum += key % 100;  // take 2-digit parts
        key /= 100;
    }

    return sum % SIZE;
}

// Insert using Linear Probing
void insert(int key) {
    int index = foldingHash(key);

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

// Search
int searchKey(int key) {
    int index = foldingHash(key);
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

// Display table
void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            cout << i << " -> EMPTY\n";
        else
            cout << i << " -> " << hashTable[i] << "\n";
    }
}

int main() {
    // Initialize
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    // Useful large input
    int data[] = {
        12345, 67890, 13579, 24680, 11223,
        44556, 77889, 99001, 54321
    };

    int n = sizeof(data) / sizeof(data[0]);

    // Insert
    for (int i = 0; i < n; i++)
        insert(data[i]);

    cout << "Hash Table (Folding + Linear Probing):\n";
    display();

    // Search
    int key;
    cout << "\nEnter key to search: ";
    cin >> key;

    int pos = searchKey(key);

    if (pos != -1)
        cout << "Found at index " << pos << endl;
    else
        cout << "Not found\n";

    return 0;
}