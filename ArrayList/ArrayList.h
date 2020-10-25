//
// Created by Monishwaran Maheswaran on 10/24/20.
//

#ifndef QUESTCREVISION_ARRAYLIST_H
#define QUESTCREVISION_ARRAYLIST_H

#endif //QUESTCREVISION_ARRAYLIST_H

#define type uint32_t
#define startSize 8

#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>

struct ArrayList {
    type *arr;
    uint32_t size;
    uint32_t capacity;
};

typedef struct ArrayList ArrayList;

ArrayList *constructorArrayList();

uint32_t size(ArrayList *list);

void addLast(type item, ArrayList *list);

type getItem(uint32_t index, ArrayList *list);

void addFirst(type item, ArrayList *list);

void delete(ArrayList *list);


