#ifndef QUEUE_H
#define QUEUE_H

const int MAX = 5;

typedef int infotype;

typedef struct {
    infotype info[MAX];
    int head, tail;
} Queue;

// Deklarasi fungsi/prosedur
void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);

void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);

void printInfo(Queue Q);

#endif
