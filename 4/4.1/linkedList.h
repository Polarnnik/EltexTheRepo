#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "contacts.h"

typedef struct Node {
    struct Node* next;
    struct Node* prev;
    Contact* contact;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
    int size;
} LinkedList;

LinkedList* createLinkedList();
void pushNode(LinkedList* list, Contact* contact);
void deleteNode(LinkedList* list, int index);
Node* getNodeAt(LinkedList* list, int index);
void deleteList(LinkedList* list);


#endif //LINKEDLIST_H
