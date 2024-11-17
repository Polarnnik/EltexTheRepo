#include"priorityQueue.h"
#include <stdio.h>

int main() {
    PriorityQueue *pq = createQueue();

    addElement(pq, 10, 3);
    addElement(pq, 20, 1);
    addElement(pq, 30, 5);
    addElement(pq, 40, 2);
    addElement(pq, 15, 96);

    printf("Содержимое очереди после добавления элементов:\n");
    printQueue(pq);

    Element elem = extractHighestPriority(pq);
    printf("\nИзвлечен элемент с наивысшим приоритетом: Data: %d, Priority: %d\n", elem.data, elem.priority);

    Element elemWithPriority;
    elemWithPriority = extractWithPriority(pq, 2 );
    printf("\nИзвлечен элемент с приоритетом 2: Data: %d, Priority: %d\n", elemWithPriority.data, elemWithPriority.priority);

    Element elemWithMinPriority;
    elemWithMinPriority = extractWithMinPriority(pq, 4);
    printf("\nИзвлечен элемент с приоритетом не ниже 4: Data:  %d, Priority: %d\n", elemWithMinPriority.data, elemWithMinPriority.priority);

    printf("\nСодержимое очереди после извлечений:\n");
    printQueue(pq);

    return 0;
}