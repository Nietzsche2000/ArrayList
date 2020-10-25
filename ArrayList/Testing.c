//
// Created by Monishwaran Maheswaran on 10/24/20.
//

#include "../AssertionTests.h"
#include "ArrayList.h"
#include "../printers.h"

void testOne() {
    ArrayList *list = constructorArrayList();
    addLast(1, list);
    addLast(2, list);
    addLast(3, list);
    addLast(4, list);
    assertTrue(list->arr[0] == 1);
    assertTrue(list->arr[1] == 2);
    assertTrue(list->arr[2] == 3);
    assertTrue(list->arr[3] == 4);
    delete(list);
}


void testTwo() {
    ArrayList *list = constructorArrayList();
    uint32_t max = 100;
    for (int i = 0; i < max; i++) {
        addLast(i, list);
    }
    for (int i = 0; i < max; i++) {
        assertTrue(list->arr[i] == i);
    }
    delete(list);
}

void testThree() {
    ArrayList *list = constructorArrayList();
    uint32_t max = 100;
    for (int i = 0; i < max; i++) {
        addLast(i, list);
    }
    assertTrue(list->size == max);
    delete(list);
}

void testFour() {
    ArrayList *list = constructorArrayList();
    uint32_t max = 100;
    for (int i = 0; i < max; i++) {
        addLast(i, list);
    }
    delete(list);
}

void testFive() {
    ArrayList *list = constructorArrayList();
    uint32_t max = 100;
    for (int i = 0; i < max; i++) {
        addLast(i, list);
    }
    for (int i = 0; i < max; i++) {
        assertTrue(getItem(i, list) == i);
    }
    delete(list);
}


int main() {
    printFunctionWithFlag(testOne, "TEST 1", false);
    printFunctionWithFlag(testTwo, "TEST 2", false);
    printFunctionWithFlag(testThree, "TEST 3", false);
    printFunctionWithFlag(testFour, "TEST 4", false);
    printFunctionWithFlag(testFive, "TEST 5", true);
}
