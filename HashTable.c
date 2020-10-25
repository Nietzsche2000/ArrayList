//
// Created by Monishwaran Maheswaran on 10/24/20.
//


#include "HashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

HashTable *constructorHashTable() {
    HashTable *hashTable = (HashTable *) malloc(sizeof(HashTable));
    hashTable->size = 0;
    hashTable->bucketNo = startBucketNo;
    hashTable->loadFactor = 0.0;
    hashTable->buckets = (ArrayList **) malloc(sizeof(ArrayList *) * startBucketNo);
    for (int i = 0; i < startBucketNo; ++i) {
        hashTable->buckets[i] = constructorArrayList();
    }
    return hashTable;
}

uint32_t modulo(int x, int modBy) {
    return (((x % modBy) + modBy) % modBy);
}

void mallocChecker(void *malloced) {
    if (malloced == NULL) {
        printf("MALLOC ERROR");
        exit(1);
    }
}

container *makeAContainer(int32_t key, char *string) {
    char *newString = (char *) malloc(strlen(string) + 1);
    mallocChecker(newString);
    strcpy(newString, string);
    container *newContainer = (container *) malloc(sizeof(container));
    mallocChecker(newContainer);
    newContainer->string = newString;
    newContainer->id = key;
    return newContainer;
}

void resize(HashTable *hashTable) {
    if (hashTable->loadFactor <= 0.75)
        return;

}

void addMap(int32_t key, char *string, HashTable *hashTable) {
    container *containerNew = makeAContainer(key, string);
    resize(hashTable);
}

uint8_t contains(int32_t key, HashTable *hashTable) {
    uint32_t hashed =
}

uint32_t hashFunction(int32_t key, HashTable *hashTable) {
    return modulo(key, hashTable->bucketNo);
}
