//
// Created by Monishwaran Maheswaran on 8/29/20.
//
#include <stdio.h>

enum boolean {
    false, true
};

typedef union {
    int intVal;
    long longVal;
    float floatVal;
    double doubleVal;
    char charVal;
} myType;

void printlnI(char *msg, long data) {
    printf(msg, data);
    printf("\n");
}

void printMyType(char *msg, myType data) {
    printf(msg, data);
    printf("\n");
}

void printlnDF(char *msg, float data) {
    printf("%g\n", data); // %g prints in scientific notation.
    printf(msg, data);
    printf("\n");
}

void printlnS(char *msg, char *data) {
    printf(msg, data);
    printf("\n");
}

void printSeparator() {
    printlnS("%s", "-------------------------------------------------------");
}

void println(char *msg) {
    printlnS("%s", msg);
}

void printlnC(char *msg) {
    printlnS("%c", msg);
}

void printFunction(void (*func)(), char *msg) {
    printSeparator();
    println(msg);
    (*func)(); // QUESTION TODO: why is this the same as func();
    printSeparator();
}

void printFunctionWithFlag(void (*func)(), char *msg, int flag) {
    if (flag == 1)
        println("CURRENT PLAY:");
    printFunction(func, msg);
}

void printFunctionWithArgs(void (*func)(int args, ...), char *msg, int flag, int args, ...) {
    if (flag == 1)
        println("CURRENT PLAY:");
    func(args);
}

//void printlnMyType(char *msg, char *type, myType data) {
//    switch (*type) {
//        case "%d":
//            printlnI(*msg + *type, data.intVal);
//            break;
//        case '%f':
//            printf(*msg + *type, data.floatVal);
//            break;
//        case '%lf':
//            printf(*msg + *type, data.doubleVal);
//            break;
//        case '%li':
//            printf(*msg + *type, data.floatVal);
//            break;
//    }
//    printf(msg, data);
//    printf("\n");
//}