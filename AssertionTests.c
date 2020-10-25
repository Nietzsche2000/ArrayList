//
// Created by Monishwaran Maheswaran on 8/31/20.
//

#include <printf.h>
#include <inttypes.h>
#include "printers.h"
#include "AssertionTests.h"

int globalCounter; // NEED not initialize, will be initialized to zero;


//void assertTrue(enum boolean expr) {
//    globalCounter++;
//    printf("%d ", globalCounter);
//    if (!expr) {
//        println("******************************");
//        println("*******ASSERTION FAILED*******");
//        println("******************************");
//    } else
//        println("ASSERTION PASSED");
//}

void assertTrue(uint8_t expr) {
    globalCounter++;
    printf("%d ", globalCounter);
    if (!expr) {
        println("******************************");
        println("*******ASSERTION FAILED*******");
        println("******************************");
    } else
        println("ASSERTION PASSED");
}

void assertFalse(uint8_t expr) {
    assertTrue(!expr);
}

void assertArrayEquals(typeArrayEquals *ptr, typeArrayEquals *ptr2, uint32_t size1) {
    for (int i = 0; i < size1; ++i) {
        assertTrue(ptr[i] == ptr2[i]);
    }
}