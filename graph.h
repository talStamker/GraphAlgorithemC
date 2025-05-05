#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_*pnode;;

 typedef struct edge_ {
    int w; //w
    pnode  de;//dest
    int dest;
    struct edge_ *next;//the next esge with the sane src
} edge, *pedge;

typedef struct queue
{
    pnode arr;
    struct queue *next;
}Qe,*pQe;
typedef struct GRAPH_NODE_ {
    int key;//id
    pedge edges;//all the edge out of him
    int d;
    struct GRAPH_NODE_ *next;//the next node in the graph
} node, *pnode;

char build_graph_cmd();
char insert_node_cmd();
void delete_node_cmd();
void deleteGraph_cmd();
int shortsPath_cmd( int src,int dest);
int TSP_cmd();

#endif
