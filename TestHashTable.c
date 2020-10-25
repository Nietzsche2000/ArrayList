//
// Created by Monishwaran Maheswaran on 10/24/20.
//

#include "HashTable.h"
#include "AssertionTests.h"
#include "printers.h"


void testOne() {
    HashTable *hashTable = constructorHashTable();
    addMap(1, "hello World", hashTable);
    addMap(5, "hello World", hashTable);
    assertTrue(contains(1, hashTable), 1);
    assertTrue(contains(5, hashTable), 1);
    assertFalse(contains(2, hashTable), 1);
    assertTrue(hashTable->size == 2, 1);
    deleteTable(hashTable);

}

void testTwo() {
    HashTable *hashTable = constructorHashTable();
    int max = 2000;
    for (int i = 0; i < max; ++i) {
        addMap(i, "hello World", hashTable);
    }

    for (int i = 0; i < max; ++i) {
        assertTrue(contains(i, hashTable), 1);
        assertFalse(contains(max + i, hashTable), 1);
    }

    assertTrue(hashTable->size == max, 1);

    deleteTable(hashTable);
}

void testThree() {
    HashTable *hashTable = constructorHashTable();
    int max = 4000000;

    for (int i = 0; i < max; ++i) {
        addMap(i, "hello World", hashTable);
        assertTrue(contains(i, hashTable), 0);
//        printlnI("rando %d", r);
        assertFalse(contains(max + i, hashTable), 0);
    }
    assertTrue(hashTable->size == max, 0);

    deleteTable(hashTable);
}

int main() {
//    printFunctionWithFlag(testOne, "TEST 1", false);
//    printFunctionWithFlag(testTwo, "TEST 2", false);
    printFunctionWithFlag(testThree, "TEST 3", true);
    return 0;
}