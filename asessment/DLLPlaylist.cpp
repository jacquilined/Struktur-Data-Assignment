#include "DLLPlaylist.h"
#include <iostream>
using namespace std;

void createList(List &L){ L.head=L.tail=NULL; }
bool isEmpty(List L){ return L.head==NULL; }

Node* allocate(lagu S){
    Node* P=new Node;
    P->info=S; P->prev=P->next=NULL;
    return P;
}

void insertLast(List &L, lagu S){
    Node* P=allocate(S);
    if(isEmpty(L)) L.head=L.tail=P;
    else{
        L.tail->next=P;
        P->prev=L.tail;
        L.tail=P;
    }
}

float getPopularityScore(lagu S){
    return (S.Rating*20) + (S.PlayCount*0.5);
}

void viewList(List L){
    Node* P=L.head;
    int i=1;
    while(P){
        cout<<i<<". "<<P->info.Title<<" - "<<P->info.Artist
            <<" | Score: "<<getPopularityScore(P->info)<<endl;
        P=P->next; i++;
    }
}