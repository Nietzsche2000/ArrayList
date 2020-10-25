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
    uint32_t id;
    char *string;
} container;


typedef struct HashTable {
    uint32_t size;
    ArrayList **buckets;
    uint32_t bucketNo;
    double loadFactor;
} HashTable;

HashTable *constructorHashTable();

void addMap(uint32_t key, char *string);



