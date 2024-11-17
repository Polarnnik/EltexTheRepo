#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include<stdlib.h>
#include<stdio.h>

#define MAX_SIZE 100

typedef struct Element {
    unsigned char priority;
    int data;
} Element;

typedef struct PriorityQueue {
    Element elements[MAX_SIZE];
    int size;
} PriorityQueue;

#endif

PriorityQueue* createQueue();
void addElement(PriorityQueue *pq, int data, int priority);
Element extractHighestPriority(PriorityQueue *pq);
Element extractWithPriority(PriorityQueue *pq, int priority);
Element extractWithMinPriority(PriorityQueue *pq, int minPriority);
void printQueue(PriorityQueue *pq);