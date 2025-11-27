#ifndef SOAL2_H
#define SOAL2_H

const int MAX = 5;
typedef int infotype;

typedef struct {
    infotype info[MAX];
    int head, tail;
} Queue;

// Prosedur dan fungsi
void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
