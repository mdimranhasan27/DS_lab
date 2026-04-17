#include <bits/stdc++.h>
using namespace std;

#define SIZE 11

struct Item {
    string key;
    bool isFilled;
};

Item hashTable[SIZE];

// Hash function (character-based)
int charHash(string key) {
    int sum = 0;

    for (char c : key) {
        sum += c;
    }

    return sum % SIZE;
}

// Insert
void insert(string key) {
    int index = charHash(key);

    while (hashTable[index].isFilled) {
        index = (index + 1) % SIZE;
    }

    hashTable[index].key = key;
    hashTable[index].isFilled = true;
}

// Search
int searchKey(string key) {
    int index = charHash(key);
    int start = index;

    while (hashTable[index].isFilled) {
        if (hashTable[index].key == key)
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
        if (!hashTable[i].isFilled)
            cout << i << " -> EMPTY\n";
        else
            cout << i << " -> " << hashTable[i].key << "\n";
    }
}

int main() {
    // initialize
    for (int i = 0; i < SIZE; i++)
        hashTable[i].isFilled = false;

    string arr[] = {
        "CAT", "DOG", "BIRD", "APPLE",
        "FISH", "MOON", "SUN", "BOOK", "PEN"
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        insert(arr[i]);

    cout << "Character Hash Table:\n";
    display();

    string key;
    cout << "\nEnter key to search: ";
    cin >> key;

    int pos = searchKey(key);

    if (pos != -1)
        cout << "Found at index " << pos << endl;
    else
        cout << "Not found\n";

    return 0;
}