//
// Created by Monishwaran Maheswaran on 10/24/20.
//

#include "ArrayList.h"

/** MALLOC FAILED EXIT CODE 1 */
ArrayList *constructorArrayList() {
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

uint32_t size(ArrayList *list) {
    return list->size;
}

void delete(ArrayList *list) {
    free(list->arr);
    free(list);
}

type getItem(uint32_t index, ArrayList *list) {
    return list->arr[index];
}

uint8_t containsArrayList(uint32_t item, ArrayList *list) {
    for (int i = 0; i < list->size; ++i) {
        if (item == list->arr[i]->id)
            return 1;
    }
    return 0;
}