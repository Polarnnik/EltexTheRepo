#include"priorityQueue.h"

PriorityQueue* createQueue() {
    PriorityQueue* queue = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    queue->size = 0;
    return queue;
}

void addElement(PriorityQueue *pq, int data, int priority) {
    if (pq->size >= MAX_SIZE) {
        printf("Ошибка: очередь переполнена.\n");
        return;
    }

    if (priority < 0 || priority > 255) {
        printf("Ошибка: приоритет должен быть в диапазоне от 0 до 255.\n");
        return;
    }

    Element newElement = {priority, data};
    int i = pq->size - 1;

    while (i >= 0 && pq->elements[i].priority > priority) {
        pq->elements[i + 1] = pq->elements[i];
        i--;
    }

    pq->elements[i + 1] = newElement;
    pq->size++;
}

Element extractHighestPriority(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Ошибка: очередь пуста.\n");
        exit(1);
    }

    Element result = pq->elements[0];

    for (int i = 0; i < pq->size - 1; i++) {
        pq->elements[i] = pq->elements[i + 1];
    }
    
    pq->size--;
    return result;
}

Element extractWithPriority(PriorityQueue *pq, int priority) {
    if (pq->size == 0) {
        printf("Ошибка: очередь пуста.\n");
        exit(1); // Выход с ошибкой, если очередь пуста.
    }

    for (int i = 0; i < pq->size; i++) {
        if (pq->elements[i].priority == priority) {
            Element result = pq->elements[i];

            for (int j = i; j < pq->size - 1; j++) {
                pq->elements[j] = pq->elements[j + 1];
            }

            pq->size--;
            return result;
        }
    }

    printf("Ошибка: элемент с приоритетом %d не найден.\n", priority);
    Element none = {0, 0};
    return none;
}

Element extractWithMinPriority(PriorityQueue *pq, int minPriority) {
    if (pq->size == 0) {
        printf("Ошибка: очередь пуста.\n");
        exit(1); // Выход с ошибкой, если очередь пуста.
    }

    for (int i = 0; i < pq->size; i++) {
        if (pq->elements[i].priority <= minPriority) {
            Element result = pq->elements[i];

            for (int j = i; j < pq->size - 1; j++) {
                pq->elements[j] = pq->elements[j + 1];
            }

            pq->size--;
            return result;
        }
    }

    printf("Ошибка: элемент с приоритетом не ниже %d не найден.\n", minPriority);
    Element none = {0, 0};
    return none;
}

void printQueue(PriorityQueue *pq) {
    for (int i = 0; i < pq->size; i++) {
        printf("Data: %d, Priority: %d\n", pq->elements[i].data, pq->elements[i].priority);
    }
}