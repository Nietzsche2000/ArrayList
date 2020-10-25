//
// Created by Monishwaran Maheswaran on 10/24/20.
//

#include "ArrayList.h"

/** MALLOC FAILED EXIT CODE 1 */
ArrayList *constructor() {
    ArrayList *list = (ArrayList *) malloc(sizeof(ArrayList));
    if (list == NULL) {
        printf("%s\n", "CANNOT CREATE LIST, MALLOC FAILED");
        exit(1);
    }
    list->size = 0;
    list->capacity = startSize;
    list->arr = (type *) malloc(sizeof(type) * startSize);
    if (list->arr == NULL) {
        printf("%s\n", "CANNOT CREATE INTERNAL LIST, MALLOC FAILED");
        exit(1);
    }
    return list;
}

void resize(uint32_t newCapacity, ArrayList *list) {
    type *newList = (type *) realloc(list->arr, sizeof(type) * newCapacity);
    if (newList == NULL) {
        printf("%s\n", "CANNOT RESIZE INTERNAL LIST, RE-ALLOC FAILED");
        exit(1);
    }
    list->arr = newList;
    list->capacity = newCapacity;
}

void addLast(type item, ArrayList *list) {
    if (list->size >= list->capacity) {
        resize(list->capacity * 2, list);
    }
    list->arr[list->size] = item;
    list->size++;
}


