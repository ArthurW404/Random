// A singly linked list of integers

#ifndef LIST_H
#define LIST_H

#include <stdbool.h> // Provides the constants 'true' and 'false'
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 1024

typedef struct node *Node;
struct node {
    int value;
    Node next;
};

typedef struct list *List;
struct list {
    Node head;
};


bool listIsOrdered(List l) {
    // TODO
    bool is_ascend = 
    return isOrdered(l->head);
}
