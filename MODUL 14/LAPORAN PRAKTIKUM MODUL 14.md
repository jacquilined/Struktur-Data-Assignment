# <h1 align="center">Laporan Praktikum Modul 14 Graph
<p align="center">Nofia Dewi Fitriana  </p>

## Dasar Teori
Graph adalah himpunan dari simpul (node) yang terhubung melalui sambungan (edge). Setiap simpul mewakili entitas atau objek, sedangkan sambungan menggambarkan hubungan atau relasi antara entitas-entitas tersebut.

Fungsi Graph

1. Pencarian Jalur dan Rute
Memungkinkan kita untuk mencari jalur atau rute terpendek antara dua simpul tertentu. Contohnya adalah ketika menggunakan aplikasi peta untuk menemukan rute tercepat dari titik A ke titik B.

2. Pemodelan Jaringan
Untuk merepresentasikan jaringan-jaringan kompleks, seperti jaringan sosial di media sosial. Dengan menggunakan struktur data ini, kita dapat menganalisis hubungan antara individu atau entitas dalam jaringan tersebut.

3. Optimisasi
Dalam beberapa masalah, dapat digunakan untuk mencari solusi optimal, seperti dalam algoritma Travelling Salesman yang mencari rute terpendek yang mengunjungi semua titik yang ada.

Jenis-Jenis Graph
Graph dapat diklasifikasikan menjadi beberapa jenis berdasarkan sifat dan karakteristiknya:

1. Directed Graph : Pada jenis ini, sambungan antara simpul memiliki arah tertentu. Contohnya, jika ada sambungan dari simpul A ke simpul B, tidak selalu ada sambungan dari simpul B ke simpul A.
2. Undirected Graph: Jenis ini memiliki sambungan antara simpul tidak memiliki arah. Sambungan antara A dan B dianggap sama dengan sambungan antara B dan A.
3. Weighted Graph: Memiliki bobot pada setiap sambungan, yang menunjukkan nilai numerik dari hubungan antara simpul-simpul tersebut.
4. Unweighted Graph: Pada jenis ini, semua sambungan memiliki nilai yang sama tanpa adanya bobot.

   
## Guided 

### graph.h

```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info; //Menyimpan data node (misal: char/int).
    int visited; //Penanda untuk traversal (0/1) (Penanda apakah node sudah dikunjungi)
    adrEdge firstEdge; //Pointer ke edge pertama yang terhubung.
    adrNode Next; // Pointer ke node berikutnya dalam graph
};

struct ElmEdge {
    adrNode Node; //Pointer yang menunjuk ke lokasi node tujuan.
    adrEdge Next; //Pointer ke edge berikutnya (jika satu node memiliki banyak cabang).
};

struct Graph {
    adrNode First; //Pointer ke node pertama dalam list graph.
};

void CreateGraph(Graph &G); //prosedur untuk mengeset first dari graph sebagai NOUL
adrNode AlokasiNode(infoGraph data); //alokasi Node baru
adrEdge AlokasiEdge(adrNode nodeTujuan); //alokasi Edge baru

void InsertNode(Graph &G, infoGraph data); //Menambahkan Node ke dalam Graph
adrNode FindNode(Graph G, infoGraph data); //function untuk mencari alamat Node berdasarkan infonya
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2); //prosedur untuk menghubungkan dua Node (Undirected Graph)
void DisconnectNode(adrNode node1, adrNode node2); //prosedur untuk memutuskan hubungan dua node
void DeleteNode(Graph &G, infoGraph X); //prosedur untuk menghapus Rode X beserta semua edge yang berhubungan dengannya

void PrintInfoGraph(Graph G); //Menampilkan isi Graph (Adjacency List)
void ResetVisited(Graph &G); //Reset status visited sebelum traversal
void PrintBFS(Graph G, infoGraph StartInfo); //traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintDFS(Graph G, infoGraph StartInfo); //Traversal Depth First Search / DFS (Menggunakan Stack)

#endif
```

### graph.cpp

```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```

### main.cpp

```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    //hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A'); //BFS
    PrintDFS(G, 'A'); //DFS
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL){
        cout << "Node E berhasil terhapus" << endl;
    } else {
        cout << "Node E tidak berhasil terhapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A'); //BFS
    PrintDFS(G, 'A'); //DFS

    return 0;
}
```

## Unguided 
<img width="901" height="827" alt="image" src="https://github.com/user-attachments/assets/ae0dd413-88d7-4b89-8744-b59848745353" />


### graph1.h

```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;

struct ElmNode;
struct ElmEdge;

typedef ElmNode* adrNode;
typedef ElmEdge* adrEdge;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode InsertNode(Graph &G, infoGraph X);
void ConnectNode(Graph &G, adrNode N1, adrNode N2);

void PrintGraphASCII();

#endif
```
### graph1.cpp

```C++
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

```

### maingraph1.cpp

```C++
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

```
#### Output:
<img width="639" height="245" alt="image" src="https://github.com/user-attachments/assets/bdc972ce-f92c-4a00-8f26-a77745321221" />

Kode ini membangun **ADT Graph tidak berarah (undirected)** memakai **linked list**: `Graph` menyimpan pointer `first` ke daftar node, setiap `ElmNode` menyimpan `info` (huruf A–H), pointer `next` untuk menyambung ke node berikutnya, serta `firstEdge` yang menunjuk ke daftar edge (tetangga) miliknya; sedangkan `ElmEdge` menyimpan pointer `node` (tujuan/tetangga) dan `next` untuk edge berikutnya. `CreateGraph` mengosongkan graph, `InsertNode` membuat node baru dan menambahkannya ke akhir list node, lalu `ConnectNode` menghubungkan dua node dengan menambah edge **dua arah** (karena graph tidak berarah) lewat `addEdgeOneWay` sambil mencegah duplikat menggunakan `edgeExists`. Fungsi `PrintGraphASCII` hanya menampilkan bentuk graf seperti gambar dalam bentuk teks (hardcode), bukan hasil traversal dari struktur graph.

#### Full code Screenshot:
<img width="1617" height="1073" alt="image" src="https://github.com/user-attachments/assets/023074d8-d67b-48be-8456-427b5ac542e6" />
<img width="1621" height="972" alt="image" src="https://github.com/user-attachments/assets/0a28147e-6569-4fb6-b01b-c2bf3d38ac99" />
<img width="1620" height="972" alt="image" src="https://github.com/user-attachments/assets/08069c95-20c4-4006-98d7-12a022fd076b" />


### 
<img width="919" height="59" alt="image" src="https://github.com/user-attachments/assets/6977a35b-4748-4c85-bd72-9c47f375baef" />
<img width="861" height="54" alt="image" src="https://github.com/user-attachments/assets/f25198b3-3b5b-421d-bc6a-8211da16f9cf" />

### graph1.cpp
```C++
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

// prosedur DFS
void PrintDFS(Graph G, adrNode N) {
    if (N == nullptr) return;

    N->visited = 1;
    cout << N->info << " ";

    adrEdge e = N->firstEdge;
    while (e != nullptr) {
        if (e->node->visited == 0) {
            PrintDFS(G, e->node);
        }
        e = e->next;
    }
}
```
### maingraph1.cpp
```C++
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

    //dfs

    for (adrNode p = G.first; p != nullptr; p = p->next) {
        p->visited = 0;
    }

    cout << "Hasil DFS: ";
    PrintDFS(G, A);
    cout << endl;

    return 0;
}
```
### graph1.h
```C++
#ifndef GRAPH1_H
#define GRAPH1_H

#include <iostream>
using namespace std;

typedef char infoGraph;

struct ElmNode;
struct ElmEdge;

typedef ElmNode* adrNode;
typedef ElmEdge* adrEdge;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode InsertNode(Graph &G, infoGraph X);
void ConnectNode(Graph &G, adrNode N1, adrNode N2);

void PrintGraphASCII();
void PrintDFS(Graph G, adrNode N);//ditambah


#endif

```
#### Output:
<img width="632" height="160" alt="image" src="https://github.com/user-attachments/assets/c3a640eb-a846-42c8-bda3-b057d3c9bae4" />

Program ini digunakan untuk **membuat dan merepresentasikan graph tidak berarah** serta **menelusurinya menggunakan DFS (Depth First Search)**, yaitu mengunjungi setiap simpul dari satu simpul awal dengan cara masuk sedalam mungkin ke cabang sebelum pindah ke cabang lain.

#### Full code Screenshot:
<img width="1617" height="1064" alt="image" src="https://github.com/user-attachments/assets/e01b956b-d33c-4994-8f9e-43a18323301f" />
<img width="1604" height="1072" alt="image" src="https://github.com/user-attachments/assets/4b7b856f-eb85-41a4-a91e-7d2bab15c287" />
<img width="1620" height="1070" alt="image" src="https://github.com/user-attachments/assets/a1bc1bf8-060c-45f5-94a7-26b049ba8e1c" />

####
### 
<img width="656" height="95" alt="image" src="https://github.com/user-attachments/assets/87819ace-79d7-4992-887b-008d54667fac" />

### graph1.cpp
```C++
#include "graph1.h"
#include <queue> 

void PrintBFS(Graph G, adrNode N) {
    if (N == nullptr) return;

    // reset visited
    for (adrNode p = G.first; p != nullptr; p = p->next) {
        p->visited = 0;
    }

    queue<adrNode> q;

    N->visited = 1;
    q.push(N);

    while (!q.empty()) {
        adrNode cur = q.front();
        q.pop();

        cout << cur->info << " ";

        adrEdge e = cur->firstEdge;
        while (e != nullptr) {
            if (e->node->visited == 0) {
                e->node->visited = 1;
                q.push(e->node);
            }
            e = e->next;
        }
    }
}

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

// prosedur DFS
void PrintDFS(Graph G, adrNode N) {
    if (N == nullptr) return;

    N->visited = 1;
    cout << N->info << " ";

    adrEdge e = N->firstEdge;
    while (e != nullptr) {
        if (e->node->visited == 0) {
            PrintDFS(G, e->node);
        }
        e = e->next;
    }
}

```
### maingraph1.cpp
```C++
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

    //dfs

    for (adrNode p = G.first; p != nullptr; p = p->next) {
        p->visited = 0;
    }

    cout << "Hasil DFS: ";
    PrintDFS(G, A);
    cout << endl;

    cout << "Hasil BFS: "; //tambahkan untuk hasil BFS
    PrintBFS(G, A);
    cout << endl;


    return 0;
}
```
### graph1.h
```C++
#ifndef GRAPH1_H
#define GRAPH1_H

#include <iostream>
using namespace std;

typedef char infoGraph;

struct ElmNode;
struct ElmEdge;

typedef ElmNode* adrNode;
typedef ElmEdge* adrEdge;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode InsertNode(Graph &G, infoGraph X);
void ConnectNode(Graph &G, adrNode N1, adrNode N2);

void PrintGraphASCII();
void PrintDFS(Graph G, adrNode N);//ditambah
void PrintBFS(Graph G, adrNode N); //ditambah bfs


#endif

```
#### Output:
<img width="412" height="129" alt="image" src="https://github.com/user-attachments/assets/0423b97c-5c5d-439f-8063-56f715d69a82" />
Program ini menjelaskan tentang struktur data Graph (graf) tidak berarah dan cara menelusuri graf menggunakan algoritma BFS (Breadth First Search) (dan bisa juga DFS), yaitu mengunjungi simpul-simpul graf dari satu simpul awal berdasarkan tetangga terdekat dulu (per level).

#### Full code Screenshot:
<img width="1623" height="1071" alt="image" src="https://github.com/user-attachments/assets/8291b1d5-3f69-497c-82ca-37969693b107" />
<img width="1619" height="1095" alt="image" src="https://github.com/user-attachments/assets/d6fe7c33-ada7-45d1-89f5-cec2ec2389b6" />
<img width="1626" height="1059" alt="image" src="https://github.com/user-attachments/assets/8af951dc-6931-4e5e-ad63-13d0f4cc5256" />

####

## Kesimpulan

graph adalah struktur data yang terdiri dari simpul (node) dan sisi (edge) untuk merepresentasikan hubungan antar objek. Graph sangat berguna untuk memodelkan dan menyelesaikan berbagai masalah nyata seperti pencarian rute/jalur, analisis jaringan, dan optimisasi, karena mampu menggambarkan koneksi yang kompleks. Graph juga memiliki beberapa jenis (directed, undirected, weighted, unweighted) yang dipakai sesuai kebutuhan, sehingga penerapannya luas dalam kehidupan sehari-hari seperti peta, media sosial, rekomendasi, transportasi, dan sistem informasi.

## Referensi
MODUL 14 GRAPH, https://fikti.umsu.ac.id/graph-pengertian-fungsi-dan-jenisnya/
