#include<stdio.h>
#include"graph.h"

int main(){
    char function;
    //char temp;
    //int isA=0;
    int isWasA=0;
    //int isprint=0;
    scanf("%c",&function);
    //pnode head;
    while (function=='A'||function=='B'||function=='S'||function=='T'||function=='D')
    {
        
        //printf("this is function: %c\n",function);
        if(function=='A'){
            if(isWasA){
            deleteGraph_cmd();
            }
            isWasA=1;
            //isA=1;
            //head=NULL;
            function=build_graph_cmd();
            if(function=='\n')
                break;
            //isprint=0;
            //printGraph_cmd();
            //printf("this is the function we get: %c",function);
        }else if(function=='B'){
                function=insert_node_cmd();
                if(function=='\n')
                    break;
                //isprint=0;
                //printGraph_cmd();
                //isA=1;
            }else if(function=='D'){
                    delete_node_cmd();
                    //printGraph_cmd();
                    scanf("%c",&function);
                    //printf("function is: %c\n",function);
                    if(function=='\n')
                        break;
                    scanf("%c",&function);
                    //printf("function is: %c\n",function);
                    //isprint=0;
                   // isA=0;
                }else if (function=='S')
                    {
                       // isA=0;
                        int src,dest;
                        scanf("%d",&src);
                       // printf("function is: %d\n",src);
                        scanf("%d",&dest);
                        //printf("function is: %d\n",dest);
                        int shor=shortsPath_cmd(src,dest);
                        printf("Dijsktra shortest path: %d \n",shor);
                        //isprint=1;
                        scanf("%c",&function);
                       // printf("function is: %c\n",function);
                        if(function=='\n'){
                            //printf("\n");
                                break;
                        }    
                        scanf("%c",&function);
                       // printf("function is: %c\n",function);
                        
                    }else if (function=='T')
                        {
                           // isA=0;
                            int tsp=TSP_cmd();
                            printf("TSP shortest path: %d \n",tsp);

                            scanf("%c",&function);
                            //printf("function is: %c\n",function);
                            if(function=='\n'){
                                // printf("\n");
                                break;
                            }
                            scanf("%c",&function);
                            //printf("function is: %c\n",function);
                            //isprint=1;
                        }
                        //printf("function is: %c\n",function); 
                        if(function!='A'&&function!='B'&&function!='S'&&function!='T'&&function!='D'){
                            //printf("we sart free");
                             deleteGraph_cmd();
                        }
                       // printf("function is: %c\n",function);      
        }
        return 0;
    }
    
    
