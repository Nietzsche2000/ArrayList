//
// Created by Monishwaran Maheswaran on 10/24/20.
//


#include "HashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void mallocChecker(void *malloced) {
    if (malloced == NULL) {
        printf("MALLOC ERROR");
        exit(1);
    }
}

HashTable *constructorHashTable() {
    HashTable *hashTable = (HashTable *) malloc(sizeof(HashTable));
    hashTable->size = 0;
    hashTable->bucketNo = startBucketNo;
    hashTable->loadFactor = 0.0;
    hashTable->buckets = (ArrayList **) malloc(sizeof(ArrayList *) * startBucketNo);
    mallocChecker(hashTable->buckets);
    for (int i = 0; i < startBucketNo; ++i) {
        hashTable->buckets[i] = constructorArrayList();
    }
    return hashTable;
}

HashTable *constructorHashTableSize(uint32_t size) {
    HashTable *hashTable = (HashTable *) malloc(sizeof(HashTable));
    hashTable->size = 0;
    hashTable->bucketNo = size;
    hashTable->loadFactor = 0.0;
    hashTable->buckets = (ArrayList **) malloc(sizeof(ArrayList *) * size);
    for (int i = 0; i < size; ++i) {
        hashTable->buckets[i] = constructorArrayList();
    }
    return hashTable;
}

uint32_t modulo(int x, int modBy) {
    return (((x % modBy) + modBy) % modBy);
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

void freeContainer(container *cont) {
    free(cont->string);
    free(cont);
}

void clearBucket(ArrayList *arrayList) {
    for (int i = 0; i < arrayList->size; ++i) {
        freeContainer(arrayList->arr[i]);
    }
}

void resizeHashTable(HashTable *hashTable) {
    if (hashTable->loadFactor <= 0.75) {
        return;
    }
    uint32_t newSize = hashTable->bucketNo * 2;
    ArrayList **newBuckets = (ArrayList **) malloc(sizeof(ArrayList *) * newSize);
    mallocChecker(newBuckets);
    for (int i = 0; i < newSize; ++i) {
        newBuckets[i] = constructorArrayList();
    }

    for (int i = 0; i < hashTable->bucketNo; ++i) {
        for (int j = 0; j < hashTable->buckets[i]->size; ++j) {
            container *mapp = getItem(j, hashTable->buckets[i]);
            uint32_t hashed = modulo(mapp->id, newSize);
            addLast(mapp, newBuckets[hashed]);
        }
        delete(hashTable->buckets[i]);
    }
    free(hashTable->buckets);
    hashTable->buckets = newBuckets;
    hashTable->bucketNo = newSize;
}

void addMap(int32_t key, char *string, HashTable *hashTable) {
    resizeHashTable(hashTable);
    container *containerNew = makeAContainer(key, string);
    uint32_t hashed = hashFunction(key, hashTable);
    addLast(containerNew, hashTable->buckets[hashed]);
    hashTable->size++;
    hashTable->loadFactor = ((double) hashTable->size) / hashTable->bucketNo;
}

uint8_t contains(int32_t key, HashTable *hashTable) {
    uint32_t hashed = hashFunction(key, hashTable);
    return containsArrayList(key, hashTable->buckets[hashed]);
}

uint32_t hashFunction(int32_t key, HashTable *hashTable) {
    return modulo(key, hashTable->bucketNo);
}

void deleteTable(HashTable *hashTable) {
    for (int i = 0; i < hashTable->bucketNo; ++i) {
        clearBucket(hashTable->buckets[i]);
        delete(hashTable->buckets[i]);
    }

    free(hashTable->buckets);
    free(hashTable);
}