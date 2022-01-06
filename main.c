#include<stdio.h>
#include"graph.h"

int main(){
    char function;
    int isWasA=0;
    scanf("%c",&function);
    while (function=='A'||function=='B'||function=='S'||function=='T'||function=='D')
    {
        if(function=='A'){
            if(isWasA){
            deleteGraph_cmd();
            }
            isWasA=1;
            function=build_graph_cmd();
            if(function=='\n'){
                deleteGraph_cmd();
                break;
            }
        }else if(function=='B'){
            function=insert_node_cmd();
            if(function=='\n'){
                break;
                deleteGraph_cmd();
            }
        }else if(function=='D'){
            delete_node_cmd();
            scanf("%c",&function);
            if(function=='\n'){
                deleteGraph_cmd();
                break;
            }
            scanf("%c",&function);
        }else if (function=='S'){
            int src,dest;
            scanf("%d",&src);
            scanf("%d",&dest);
            int shor=shortsPath_cmd(src,dest);
            printf("Dijsktra shortest path: %d \n",shor);
            scanf("%c",&function);
            if(function=='\n'){
                deleteGraph_cmd();
                break;
            }    
            scanf("%c",&function);                
        }else if (function=='T'){
            int tsp=TSP_cmd();
            printf("TSP shortest path: %d \n",tsp);
            scanf("%c",&function);
            if(function=='\n'){
                deleteGraph_cmd();
                break;
            }
            scanf("%c",&function);
        }    
    }
     return 0;
}
    
    
