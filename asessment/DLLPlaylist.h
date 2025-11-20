#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H
#include <string>
using namespace std;

struct lagu {
    string Title, Artist;
    int DurationSec, PlayCount;
    float Rating;
};

struct Node {
    lagu info;
    Node *prev, *next;
};

struct List {
    Node *head, *tail;
};

void createList(List &L);
bool isEmpty(List L);
Node* allocate(lagu S);
void insertLast(List &L, lagu S);
void viewList(List L);
float getPopularityScore(lagu S);

#endif