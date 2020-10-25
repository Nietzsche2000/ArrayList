//
// Created by Monishwaran Maheswaran on 10/24/20.
//


#include "HashTable.h"

HashTable *constructorHashTable() {
    HashTable *hashTable = (HashTable *) malloc(sizeof(HashTable));
    hashTable->size = 0;
    hashTable->bucketNo = startBucketNo;
    hashTable->loadFactor = 0.0;
    hashTable->buckets = (ArrayList **) malloc(sizeof(ArrayList *) * startBucketNo);
    for (int i = 0; i < startBucketNo; ++i) {
        hashTable->buckets[i] = constructorArrayList();
    }
}

void addMap(uint32_t key, char *string);

