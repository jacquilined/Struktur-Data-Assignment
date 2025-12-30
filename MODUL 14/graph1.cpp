#include "graph1.h"

static adrNode newNode(infoGraph x) {
    adrNode p = new ElmNode;
    p->info = x;
    p->visited = 0;
    p->firstEdge = nullptr;
    p->next = nullptr;
    return p;
}

static adrEdge newEdge(adrNode dest) {
    adrEdge e = new ElmEdge;
    e->node = dest;
    e->next = nullptr;
    return e;
}

static bool edgeExists(adrNode from, adrNode to) {
    for (adrEdge e = from->firstEdge; e != nullptr; e = e->next) {
        if (e->node == to) return true;
    }
    return false;
}

static void addEdgeOneWay(adrNode from, adrNode to) {
    if (from == nullptr || to == nullptr) return;
    if (edgeExists(from, to)) return;

    adrEdge e = newEdge(to);

    e->next = from->firstEdge;
    from->firstEdge = e;
}

void CreateGraph(Graph &G) {
    G.first = nullptr;
}

adrNode InsertNode(Graph &G, infoGraph X) {
    adrNode p = newNode(X);

    if (G.first == nullptr) {
        G.first = p;
    } else {
        adrNode last = G.first;
        while (last->next != nullptr) last = last->next;
        last->next = p;
    }

    return p;
}

void ConnectNode(Graph &G, adrNode N1, adrNode N2) {
    if (N1 == nullptr || N2 == nullptr) return;
    if (N1 == N2) return;

    addEdgeOneWay(N1, N2);
    addEdgeOneWay(N2, N1);
}

void PrintGraphASCII() {
    cout << "          A\n";
    cout << "        /   \\\n";
    cout << "       B     C\n";
    cout << "     /  \\   / \\\n";
    cout << "    D    E F   G\n";
    cout << "     \\    \\|   /\n";
    cout << "          H\n\n";
}
