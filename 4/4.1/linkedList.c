#include "linkedList.h"
#include <malloc.h>
#include <stdio.h>



LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

void pushNode(LinkedList* list, Contact* contact) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->contact = contact;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->tail != NULL) {
        list->tail->next = newNode;
    } else {
        list->head = newNode;
    }
    list->tail = newNode;
    list->size++;
}

void deleteNode(LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Индекс за пределом списка.\n");
        return;
    }

    if (index == 0 && list->size == 1) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return;
    }
    else if (index == 0 && list->size > 1) {
        Node* next = list->head->next;
        next->prev = NULL;
        free(list->head);
        list->head = next;
        list->size--;
        return;
    }

    if (index == list->size - 1) {
        Node* prev = list->tail->prev;
        prev->next = NULL;
        free(list->tail);
        list->tail = prev;
        list->size--;
        return;
    }

    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    Node* prev = current->prev;
    Node* next = current->next;

    prev-> next = next;
    next->prev = prev;

    free(current);
    list->size--;
}

Node* getNodeAt(LinkedList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Индекс за пределом списка.\n");
        return NULL;
    }
    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

void deleteList(LinkedList* list) {
    Node* current = list->head;
    Node* next = NULL;
    for (int i = 0; i < list->size; i++) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}
