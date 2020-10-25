//
// Created by Monishwaran Maheswaran on 8/23/20.
//

#ifndef EXPERIMENTS_PRINTERS_H
#define EXPERIMENTS_PRINTERS_H

#endif //EXPERIMENTS_PRINTERS_H


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

void printlnI(char *msg, long data);

void printMyType(char *msg, myType data);

void printlnDF(char *msg, float data);

void printlnS(char *msg, char *data);
void printlnS(char *msg, char *data);

void printSeparator();

void println(char *msg);

void printFunction(void (*func)(), char *msg);

void printFunctionWithFlag(void (*func)(), char *msg, int flag);

void printFunctionWithArgs(void (*func)(int args, ...), int args, ...);