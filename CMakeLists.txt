PROJECT(ArrayList)

add_executable(ArrayList ArrayList/ArrayList.c)
add_executable(testing ArrayList/ArrayList.c ArrayList/Testing.c printers.c  AssertionTests.c)
add_executable(test2 HashTable.c  ArrayList/ArrayList.c printers.c  AssertionTests.c TestHashTable.c)