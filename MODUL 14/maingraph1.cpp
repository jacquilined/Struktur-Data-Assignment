#include "graph1.h"

int main() {
    Graph G;
    CreateGraph(G);

    adrNode A = InsertNode(G, 'A');
    adrNode B = InsertNode(G, 'B');
    adrNode C = InsertNode(G, 'C');
    adrNode D = InsertNode(G, 'D');
    adrNode E = InsertNode(G, 'E');
    adrNode F = InsertNode(G, 'F');
    adrNode Gg = InsertNode(G, 'G');
    adrNode H = InsertNode(G, 'H');

    ConnectNode(G, A, B);
    ConnectNode(G, A, C);

    ConnectNode(G, B, D);
    ConnectNode(G, B, E);

    ConnectNode(G, C, F);
    ConnectNode(G, C, Gg);

    ConnectNode(G, D, H);
    ConnectNode(G, E, H);
    ConnectNode(G, F, H);
    ConnectNode(G, Gg, H);

    PrintGraphASCII();

    return 0;
}
