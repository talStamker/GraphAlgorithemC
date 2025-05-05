# GraphAlgorithemC
## How to run it?
### make
### ./graph
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
#### static pnode head;- the head of the linked list of nodes
#### static int size=0;- the size of node that we get fromj user
#### static pQe Q;- gueue of the nodes in graph
#### static pnode min;- the pnode that is minimum in the graph
#### static int sizeQ=0; - the nmber of nodes in graph
#### functions:
##### void insert(pnode n)- This function insert the node to the graph and update min,size and queue.
##### void updateMin(int key) - This function update min about the queue
##### void delete()- This function delete the min node in the graph
##### int isEmpty()- This function checks if the graph is empty
##### char build_graph_cmd()- This function build the graph by the user
##### char insert_node_cmd()- This function insert nodes to the graph by user
##### int containsN(int data) -  This function checks if the graph has node with the key that equals data.
##### int containsE(int data,pedge E)- This function checks if the edge exist in graph.
##### void delete_node_cmd()-This function delete nodes by the user
##### void deleteGraph_cmd()- This function delete all graph
##### void relax(pnode u,pnode v,int w)- This function is help function for shortpath calculate.
##### int shortsPath_cmd(int src,int dest) This function return the short path from src to dest
##### void TSP(int *c,int *A,int*sum,int *fsum,int flag,int n,int b,int a)- This function is help function for TSP problem that update fsum and sum
##### int TSP_cmd()- This function return the weight of the path in TSP result.



