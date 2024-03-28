#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10


struct HashTable {
    int *array;
    int capacity;
};


struct HashTable* createHashTable(int capacity);
int hash(int key, int capacity);
void insert(struct HashTable* ht, int key);
bool search(struct HashTable* ht, int key);
void display(struct HashTable* ht);

int main() {
    
    struct HashTable* ht = createHashTable(SIZE);

    
    insert(ht, 10);
    insert(ht, 20);
    insert(ht, 30);
    insert(ht, 25);

    
    display(ht);

    
    int keyToSearch = 25;
    if (search(ht, keyToSearch))
        printf("Key %d found in the hash table.\n", keyToSearch);
    else
        printf("Key %d not found in the hash table.\n", keyToSearch);

    return 0;
}


struct HashTable* createHashTable(int capacity) {
    struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
    ht->capacity = capacity;
    ht->array = (int*)calloc(capacity, sizeof(int));
    return ht;
}


int hash(int key, int capacity) {
    return key % capacity;
}


void insert(struct HashTable* ht, int key) {
    int index = hash(key, ht->capacity);

    
    while (ht->array[index] != 0) {
        index = (index + 1) % ht->capacity;
    }

    ht->array[index] = key;
}


bool search(struct HashTable* ht, int key) {
    int index = hash(key, ht->capacity);

   
    while (ht->array[index] != 0) {
        if (ht->array[index] == key)
            return true;
        index = (index + 1) % ht->capacity;
    }

    return false;
}


void display(struct HashTable* ht) {
    printf("Hash Table:\n");
    for (int i = 0; i < ht->capacity; i++) {
        printf("[%d] -> %d\n", i, ht->array[i]);
    }
}
