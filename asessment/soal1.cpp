#include <soal1.h> 
#include <iostream>

bool isEmpthy(list L){
    return L.head == nullptr;
}
void createList(List L){
    L.head == nullptr;
}
Node* allocate(Product P){
    Node* N = new Node;
    N -> info = P
    N -> next = nullptr
    return N;
}
void deallocate(Node* N){
    delete N;
}
void insertFirst(List &L, Product P){
    Node* N = allocatee(P);
    N -> next = L.head
    L.head = N
}
void insertLast(List &L, Product P){
    Node* N = allocate(P);
    if (isEmpthy(L)) {
        L.Head = N;
    }else{
        Node* Q = L.head;
        while (Q -> next != nullptr)
        Q -> next = N;
    }
    }
void insertFirst(List &L, Product P){
    Node* N = allocatee(P);
    N -> next = L.head
    L.head = N
}
