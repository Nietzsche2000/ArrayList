//
// Created by Monishwaran Maheswaran on 10/24/20.
//

#ifndef ARRAYLIST_HASHTABLE_H
#define ARRAYLIST_HASHTABLE_H

#endif //ARRAYLIST_HASHTABLE_H

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList/ArrayList.h"

#define startBucketNo 8

typedef struct container {
    int32_t id;
    char *string;
} container;


typedef struct HashTable {
    uint32_t size;
    ArrayList **buckets;
    uint32_t bucketNo;
    double loadFactor;
} HashTable;

HashTable *constructorHashTable();

void addMap(int32_t key, char *string, HashTable *hashTable);

uint32_t hashFunction(int32_t key, HashTable *hashTable);

uint8_t contains(int32_t key, HashTable *hashTable);
