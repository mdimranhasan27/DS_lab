#include <bits/stdc++.h>
using namespace std;

const int SIZE = 11;
int hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int i = 1;

    while (hashTable[index] != -1) {
        index = (hashFunction(key) + i * i) % SIZE;
        i++;
    }

    hashTable[index] = key;
}

int search(int key) {
    int index = hashFunction(key);
    int i = 1;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return index;

        index = (hashFunction(key) + i * i) % SIZE;
        i++;

        if (i == SIZE)
            break;
    }

    return -1;
}

int main() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    int data[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};

    for (int x : data)
        insert(x);

    int key;
    cin >> key;

    int pos = search(key);

    if (pos != -1)
        cout << "Found at " << pos;
    else
        cout << "Not found";

    return 0;
}