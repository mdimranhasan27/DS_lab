#include <stdio.h>
#include <stdlib.h>

#define SIZE 11

struct Node {
    int data;
    struct Node *next;
};

int hash(int key) {
    return key % SIZE;
}



void insert(struct Node *hashTable[], int key) {
    int index = hash(key);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int search(struct Node *hashTable[], int key) {
    int index = hash(key);
    struct Node *ptr = hashTable[index];
    while (ptr != NULL) {
        if (ptr->data == key)
            return index;
        ptr = ptr->next;
    }
    return -1;
}

void display(struct Node *hashTable[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("[%d] -> ", i);
        struct Node *ptr = hashTable[i];
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct Node *hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) hashTable[i] = NULL;

    int data[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    int n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++)
        insert(hashTable, data[i]);

    printf("Hash Table (Chaining):\n");
    display(hashTable);

    int key = 44;
    int pos = search(hashTable, key);
    if (pos != -1) printf("\n%d found in chain %d\n", key, pos);
    else printf("\n%d not found\n", key);

    return 0;
}
/*#include <stdio.h>
#include <stdlib.h>

#define SIZE 11

// Node structure for linked list
struct Node {
    int data;
    struct Node *next;
};

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert using chaining
void insert(struct Node *hashTable[], int key) {
    int index = hash(key);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = key;
    newNode->next = NULL;

    // Insert at beginning (head insertion)
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search element
int search(struct Node *hashTable[], int key) {
    int index = hash(key);

    struct Node *ptr = hashTable[index];
    while (ptr != NULL) {
        if (ptr->data == key)
            return index;   // found in this chain
        ptr = ptr->next;
    }
    return -1;  // not found
}

// Display hash table
void display(struct Node *hashTable[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("[%d] -> ", i);

        struct Node *ptr = hashTable[i];
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }

        printf("NULL\n");
    }
}

int main() {
    struct Node *hashTable[SIZE];

    // Initialize table
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    int data[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    int n = sizeof(data) / sizeof(data[0]);

    // Insert elements
    for (int i = 0; i < n; i++)
        insert(hashTable, data[i]);

    printf("Hash Table using Chaining:\n");
    display(hashTable);

    // Search element
    int key;
    printf("\nEnter element to search: ");
    scanf("%d", &key);

    int pos = search(hashTable, key);

    if (pos != -1)
        printf("Element %d found in chain %d\n", key, pos);
    else
        printf("Element %d not found\n", key);

    return 0;
}*/