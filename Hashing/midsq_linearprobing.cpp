#include <bits/stdc++.h>
using namespace std;

#define SIZE 11

int hashTable[SIZE];

// Simple mid-square hash
int midSquareHash(int key) {
    long long sq = key * key;

    // take middle 2 digits using math (no string)
    sq = sq / 10;      // remove last digit
    int mid = sq % 100; // take last 2 digits

    return mid % SIZE;
}

// Insert using Linear Probing
void insert(int key) {
    int index = midSquareHash(key);

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

// Search
int searchKey(int key) {
    int index = midSquareHash(key);
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

// Display
void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            cout << i << " -> EMPTY\n";
        else
            cout << i << " -> " << hashTable[i] << "\n";
    }
}

int main() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    int data[] = {44, 23, 67, 89, 12, 58, 91, 36, 75};
    int n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++)
        insert(data[i]);

    cout << "Mid-Square Hash Table:\n";
    display();

    int key;
    cout << "\nEnter key: ";
    cin >> key;

    int pos = searchKey(key);

    if (pos != -1)
        cout << "Found at index " << pos << endl;
    else
        cout << "Not found\n";

    return 0;
}