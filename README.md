# GraphAlgorithemC
## How to run it?
- make
- ./graph
## graph.h
### typedef struct edge_ { -edge in the graph
###    int w; //w
###    pnode  de;//dest
###    int dest;
###    struct edge_ *next;//the next esge with the sane src
### } edge, *pedge;

### typedef struct queue - queue of nodes in graph
### {
###    pnode arr;
###    struct queue *next;
### }Qe,*pQe;
### typedef struct GRAPH_NODE_ {- node in graph
###    int key;//id
###    pedge edges;//all the edge out of him
###    int d;
###    struct GRAPH_NODE_ *next;//the next node in the graph
### } node, *pnode;

## graphAlgo.c:
### elements
static pnode head;- the head of the linked list of nodes
static int size=0;- the size of the queue
static pQe Q;
static pnode min;- the min in the graph
static int sizeQ=0;


