//
// Created by Monishwaran Maheswaran on 8/31/20.
//

#ifndef EXPERIMENTS_ASSERTIONTESTS_H
#define EXPERIMENTS_ASSERTIONTESTS_H

#endif //EXPERIMENTS_ASSERTIONTESTS_H
#include <inttypes.h>

//void assertTrue(enum boolean expr);
void assertTrue(uint8_t expr, uint8_t withPrint);

void assertFalse(uint8_t expr, uint8_t withPrint);

#define typeArrayEquals uint32_t
void assertArrayEquals(typeArrayEquals *ptr, typeArrayEquals *ptr2, uint32_t size1, uint8_t withPrint);
