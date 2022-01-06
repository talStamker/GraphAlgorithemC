#include <stdio.h>
#include "graph.h"
#include <string.h>
#include<limits.h>
#include<ctype.h>
#include <stdlib.h>
//#include <bits/stdc++.h>
//using namespace std;
static pnode head;
static int size=0;
static pQe Q;
static pnode min;
static int sizeQ=0;
//queue

void insert(pnode n){
    pQe currentQ;
    if(Q==NULL){//beginning
        Q=(pQe)malloc(sizeof(Qe));
        Q->arr=n;
        min=n;
        Q->next=NULL;
        currentQ=Q;
        //printf("in insert function we do malloc to Q; %d\n",Q->arr->key);
       // printf("add: %d\n",Q->arr->key);
    }else{//continue
        currentQ=Q;
        while (currentQ->next!=NULL)
        {
            currentQ=currentQ->next;
        }
        currentQ->next=(pQe)malloc(sizeof(Qe));
        currentQ->next->arr=n;
        //printf("in insert function we do malloc to Q; %d\n",currentQ->next->arr->key);
        currentQ->next->next=NULL;
       // printf("add: %d",currentQ->next->arr->key);
        if (n->d < min->d)
        {
            min=n;
        }
    }
    sizeQ++;
}

void updateMin(int key){
    //printf("0\n");
    pQe currentQ=Q;
    //printf("1");
    int minimum=INT_MAX;
    //printf("2");
    int isChange=1;
    while (currentQ!=NULL)
    {
        //printf("this is d current: %d\n",currentQ->arr->d);
        if (currentQ->arr->d < minimum )
        {
            //printf("4");
            min=currentQ->arr;
            minimum=currentQ->arr->d;
            //printf("5");
            isChange=0;
        }
        if (currentQ->next==NULL&&isChange==1)
        {
            min=currentQ->arr;
            //printf("min cahnge to %d\n",min->key);
            //printf("this id d of min%d\n",min->d);
        }
        
        currentQ=currentQ->next;
        //printf("6\n");
    } 
}

void delete(){
    //printf("1\n");
    pQe currentQ=Q;
    //printf("2\n");
    //printf("min is: %d",min->key);
    if(currentQ->arr->d==min->d){
        //printf("3\n");
        pQe temp=Q;
        //printf("4\n");
        //printf("5\n");
        Q=Q->next;
        //printf("in delete we do free to Q: %d\n",temp->arr->key);
        free(temp);
        
    }else{
        while (currentQ->next->arr->key!=min->key)
        {
            currentQ=currentQ->next;
        }
        //printf("min cahnge to %d\n",min->key);
        //printf("this id d of min%d\n",min->d);
        pQe temp=currentQ->next;
        currentQ->next=currentQ->next->next;
        //printf("this is min key: %d",min->key); 
        // printf("in delete we do free to Q: %d\n",temp->arr->key);
        free(temp);
    } 
    sizeQ--;
    
}

int isEmpty(){
    if(sizeQ==0){
        return 1;
    }
    return 0;
}
// void freeQ(){
//     pQe currentQ=Q;
//     while (Q!=NULL)
//     {
//         pQe ptr=currentQ;
//         currentQ=currentQ->next;
//         free(ptr); 
//     }
    
// }


//graph
char build_graph_cmd()
{

    int n;
    char isN;
    scanf("%d", &n);
    //printf("n is: %d\n",n);
    scanf("%c", &isN);
    //printf("n is: %c\n",isN);
    //printf("this is n: %c\n",isN);
    scanf("%c", &isN);
    //printf("n is: %c\n",isN);
    //printf("this is n: %c\n",isN);
    for (int  i = 0; i < n; i++)
    {
            //printf("build\n");
           isN= insert_node_cmd();
    }
    return isN;
}
// node GET(int k){
//     pnode currentN=head;
//     while (currentN !=NULL&&currentN->key!=k)
//     {
//         currentN=currentN->next;
//     }
//     return *currentN;
    

// }
// void updateDe(pnode n){
//     pnode currentN=head;
//     while (*currentN!=NULL)
//     {
//         pedge currentE=currentN->edges;
//         while (currentE!=NULL)
//         {
//             if(currentE->dest==n->key){
//                 currentE->de=n;
//             }
//             currentE=currentE->next;
//         }
        
//     }
    
// }
char insert_node_cmd()
{   
    // add node:
    int id;
    pnode currentNode;
    scanf("%d", &id);
    //printf("id is: %d\n",id);
    //printf("this is id: %d\n",id);
    pnode currentN;
    if(head==NULL){//beginning
        head=(pnode)malloc(sizeof(node));
        head->key=id;
        head->next=NULL;
        //printf("in insert_node_cmd we do malloc for vertex: %d",head->key);
        currentN=head;
        currentNode=head;
    }else{//continue
        currentN=head;
        while (currentN->next!=NULL&&currentN->next->key!=id)
        {
            currentN=currentN->next;
        }
        if(currentN->next==NULL){
        size++;
        currentN->next=(pnode)malloc(sizeof(node));
        currentN->next->key=id;
        //printf("in insert_node_cmd we do malloc for vertex: %d",currentN->next->key);
        currentN->next->next=NULL;
        currentNode=currentN->next;
        //printf("this is not begining\n");
        pnode V=head;
        pedge E=NULL;
        currentN->next->edges=NULL;
            while (V!=NULL)
            {//update all dest
            //printf("we start match\n");
                 E=V->edges;
                while (E!=NULL)
                {
                    //printf("we start check\n");
                    if(E->dest==id){
                        //printf("we match %d\n",V->key);
                        E->de=currentN->next;
                        //printf("we  actually match %d\n",E->de->key);
                     }//else{
                    //     pnode v1=head;
                    //     while (v1!=NULL)
                    //     {
                    //         if (E->dest==v1->key&&E->de==NULL)
                    //         {
                    //             E->de=v1;
                    //         }
                    //         v1=v1->next;   
                    //     }
                        
                    // }
                    E=E->next;
                }
                V=V->next;  
            }
        }else{
            pedge E=currentN->next->edges;
            while (E!=NULL)
            {
                pedge temp=E;
                //printf("{%d,%d}",currentN->next->key,E->dest);
                //printf("we do free in insert_node_cmd for edge {%d,%d}\n",currentN->next->key,temp->dest);
                E=E->next;
                free(temp);
            }  
            currentN->next->edges=NULL;
             //printf("1\n");
            char temp,w,dest;
            scanf("%c",&temp);
            //printf("this is temp:%c\n",temp);
            scanf("%c",&dest);
            //printf("this is dest:%c\n",dest);
            if(dest<'0'||dest>'9'){
                return dest;
            }
            scanf("%c",&temp);
            //printf("this is temp:%c\n",temp);
            scanf("%c",&w);
            //printf("this is w:%c\n",w);

            // char str[2];
            // scanf("%s", str);
            // printf("str is: %s\n",str);
            // if (str[1] == '\0')
            // {
            // return str[0];
            // }
            //printf("2\n");
            currentN->next->edges=(pedge)malloc(sizeof(edge));

            //printf("3\n");
            currentN->next->edges->dest=(int)(dest)-48;
            //printf("4\n");
            currentN->next->edges->w=(int)(w)-48;
            currentN->next->edges->next=NULL;
            //printf("5\n");
            // printf("we do malloc in insert_node_cmd for edge {%d,%d}\n",currentN->next->key,currentN->next->edges->dest);
            pnode v1=head;
            while (v1!=NULL)
            {
            //printf("try the node :%d\n",v1->key);
             if (currentN->next->edges->dest==v1->key)
                {
                //printf("we  strat enter edge\n");
                currentN->next->edges->de=v1;
                //printf("we end enter\n");
                }
                v1=v1->next;   
            }
            //printf("{%d,%d,w=%d},\n",currentN->next->key,currentN->next->edges->dest,currentN->next->edges->w);
            pedge currentE=currentN->next->edges;
            while (1)
            {
            //printf("please enter edge\n");
            char temp,w,dest;
            scanf("%c",&temp);
            // printf("this is temp:%c\n",temp);
            scanf("%c",&dest);
            //printf("this is dest:%c\n",dest);
            if(dest<'0'||dest>'9'){
                currentE->next=NULL;
                return dest;
            }
            scanf("%c",&temp);
             //printf("this is temp:%c\n",temp);
            scanf("%c",&w);
             //printf("this is w:%c\n",w);
            // char strin[2];
            // scanf("%s", strin);
            //  printf("str is: %s\n",strin);
            // if (strin[1] == '\0')
            // {
            // currentE->next=NULL;
            // return strin[0];
            // }
            currentE->next=(pedge)malloc(sizeof(edge));
            currentE->next->dest=(int)(dest)-48;
            currentE->next->w=(int)(w)-48;
           // printf("we do malloc in insert_node_cmd for edge {%d,%d}\n",currentN->next->key,currentE->next->dest);
            pnode v2=head;
            while (v2!=NULL)
            {
                if (currentE->next->dest==v2->key)
                {
                    currentE->next->de=v2;
                }
                v2=v2->next;   
            }
           // printf("{%d,%d,w:%d},\n",currentN->next->key,currentE->next->dest,currentE->next->w);
            currentE=currentE->next;
        }
        }
    }
    //add edge:
    //printf("1\n");
    char temp,w,dest;
    scanf("%c",&temp);
     //printf("this is temp:%c\n",temp);
    scanf("%c",&dest);
     //printf("this is dest:%c\n",dest);
    if(dest<'0'||dest>'9'){
        currentNode->edges=NULL;
        return dest;
    }
    scanf("%c",&temp);
    //printf("this is temp:%c\n",temp);
    scanf("%c",&w);
    //printf("this is w:%c\n",w);
    // char str[2];
    // scanf("%s", str);
    //  printf("str is: %s\n",str);
    // if (str[1] == '\0')
    // {
    //     currentNode->edges=NULL;
    //     return str[0];
    // }
    //printf("2\n");
    currentNode->edges=(pedge)malloc(sizeof(edge));
    //printf("3\n");
    currentNode->edges->dest=(int)(dest)-48;
    //printf("4\n");
    currentNode->edges->w=(int)(w)-48;
    currentNode->edges->next=NULL;
    //printf("we do malloc in insert_node_cmd for edge {%d,%d}\n",currentNode->key,currentNode->edges->dest);
    //printf("5\n");
    pnode v1=head;
    while (v1!=NULL)
    {
        //printf("try the node :%d\n",v1->key);
        if (currentNode->edges->dest==v1->key)
        {
            //printf("we  strat enter edge\n");
            currentNode->edges->de=v1;
            //printf("we end enter\n");
        }
        v1=v1->next;   
   }
   //printf("{%d,%d,w=%d},\n",currentNode->key,currentNode->edges->dest,currentNode->edges->w);
    pedge currentE=currentNode->edges;
    while (1)
    {
        //printf("please enter edge\n");
        char temp,w,dest;
        scanf("%c",&temp);
             //printf("this is temp:%c\n",temp);
    scanf("%c",&dest);
     //printf("this is dest:%c\n",dest);
    if(dest<'0'||dest>'9'){
        currentE->next=NULL;
        return dest;
    }
    scanf("%c",&temp);
     //printf("this is temp:%c\n",temp);
    scanf("%c",&w);
    //printf("this is w:%c\n",w);
        // char strin[2];
        // scanf("%s", strin);
        //  printf("str is: %s\n",strin);
        // if (strin[1] == '\0')
        // {
        //     currentE->next=NULL;
        //     return strin[0];
        // }
        currentE->next=(pedge)malloc(sizeof(edge));
        currentE->next->dest=(int)(dest)-48;
        currentE->next->w=(int)(w)-48;
        //printf("we do malloc in insert_node_cmd for edge {%d,%d}\n",currentNode->key,currentE->next->dest);
        pnode v2=head;
        while (v2!=NULL)
        {
            if (currentE->next->dest==v2->key)
            {
                currentE->next->de=v2;
            }
            v2=v2->next;   
        }
        //printf("{%d,%d,w:%d},\n",currentNode->key,currentE->next->dest,currentE->next->w);
        currentE=currentE->next;

    }
}

int containsN(int data){
    pnode currentNode=head;
    while (currentNode!=NULL)
    {
        if(currentNode->key==data){
            return 1;
        }
        else{
            currentNode=currentNode->next;
        }
    }
    return 0;
}
int containsE(int data,pedge E){
    pedge currentE=E;
    while (currentE!=NULL)
    {
        if(currentE->dest==data){
            return 1;
        }
        else{
            currentE=currentE->next;
        }
    }
    return 0;
    
}
void delete_node_cmd(){
    int data;
    scanf("%d",&data);
    //printf("data is: %d\n",data);
    if (containsN(data)==0)
    {
        return;
    }
    pnode currentNode=head;
    if(currentNode->key==data){
        pnode temp=head;
        head=head->next;
        //printf("we free in delete_node_cmd the vertex: %d\n",temp->key);
        free(temp);
    }else{
        while (currentNode->next->key!=data)
        {
            currentNode=currentNode->next;
        }
        pnode temp=currentNode->next;
        currentNode->next=currentNode->next->next;
        //printf("we free in delete_node_cmd the vertex: %d\n",temp->key);
        free(temp);
    }
    currentNode=head;
    while (currentNode!=NULL)
    {
        pedge currentE=currentNode->edges;
        if (containsE(data,currentE)==1)
        {
            if(currentE->dest==data){
                pedge temp=currentNode->edges;
                //printf("we free in delete_node_cmd th edge:{%d,%d}\n",currentNode->key,temp->dest);
                currentNode->edges=currentNode->edges->next;
                free(temp);
            }else{
               while (currentE->next->dest!=data)
               {
                   currentE=currentE->next;
               }
               pedge temp=currentE->next;
               //printf("we free in delete_node_cmd th edge:{%d,%d}\n",currentNode->key,temp->dest);
               currentE->next=currentE->next->next;
               free(temp);   
            }
        }
        currentNode=currentNode->next; 
    }
}
void Printq(){
    pQe currentQ=Q;
    char ans[1000]="Q:{";
    while (currentQ!=NULL)
    {
        char st[12];
        sprintf(st,"%d",currentQ->arr->key);
        strcat(ans,st);
        strcat(ans,",");
        currentQ=currentQ->next;
    }
    strcat(ans,"}");
    printf("this is the q: %s\n",ans);
    
}
void printGraph_cmd(){
    char st [1000]="Nodes: { ";
    pnode currentN=head;
    char E[1000]="";
    while (currentN!=NULL)
    {
        char str[12];
        sprintf(str,"%d",currentN->key);
        strcat(st,str);
        strcat(st,",");
        pedge currentE=currentN->edges;
        while (currentE!=NULL)
        {
            char temp[15]="{ ";
            char ke[12];
            sprintf(ke,"%d",currentN->key);
            strcat(temp,ke);
            strcat(temp,",");
            char dest[12];
            sprintf(dest,"%d",currentE->de->key);
            strcat(temp,dest);
            strcat(temp,",w: ");
            char w[12];
            sprintf(w,"%d",currentE->w);
            strcat(temp,w);
            strcat(temp," }");
            strcat(E,temp);
            currentE=currentE->next;
        }
        currentN=currentN->next;
    }
    st[strlen(st)-1]=' ';
    strcat(st,"} , Edges: {");
    strcat(st,E);
    strcat(st," }");
    printf("the graph is: %s\n",st);
}
void deleteGraph_cmd(){
    pnode currentN=head;
    pedge currentE=NULL;
    while (currentN!=NULL)
    {
        currentE=currentN->edges;
        while (currentE!=NULL)
        {
            pedge temp=currentE;
            //printf("we free in deleteGraph_cmd the edge:{%d,%d}\n",currentN->key,temp->dest);
            currentE=currentE->next;
            free(temp);
        }
        pnode ptr=currentN;
        //printf("we free the vertex:%d\n",ptr->key);
        currentN=currentN->next;
        free(ptr); 
    }
    head=NULL;   
}

void relax(pnode u,pnode v,int w){
    //printf("this is u:%d\n this is v%d\n",u->key,v->key);
    //printf("this is u->d:%d\n this is u->d:%d\n",u->d,v->d);
    //printf("this is u->d+w:%d\n this is u->d",u->d+w);
    if(u->d!=INT_MAX){
    if (v->d > u->d+w)
    {
        v->d =u->d+w;
        //printf("we change te d of vertex%d to %d\n",v->key,v->d);
    }
    }
    
    
}
int shortsPath_cmd(int src,int dest){
    pnode currentN=head;
    //printGraph_cmd();
    while (currentN!=NULL)
    {
        currentN->d=INT_MAX;
        if(currentN->key==src){
            currentN->d=0;
        }
        insert(currentN);
        currentN=currentN->next;
    }
    //Printq();
    while (isEmpty()==0)
    {
        //printf("we start delete u \n");
        delete();
        //pQe U=min;
        //Printq();
        pedge E=min->edges;
        while (E!=NULL)
        {
            //printf("we start relax\n");
            relax(min,E->de,E->w);
           // printf("we do relax\n");
            E=E->next;
        }
        updateMin(min->key);     
    }
   // printf("we find short path\n");
    pnode p=head;
    while (p !=NULL&&p->key!=dest)
    {
        p=p->next;
    }
    //freeQ();
    if(p->d==INT_MAX){
        return -1;
    }else{
        //printf("this is d: %d",p->d);
        return p->d;
    }
    return 1;

}

void TSP(int *c,int *A,int*sum,int *fsum,int flag,int n,int b,int a){
    flag++;
    for (int k = 0; k < n; k++)
    {
        if(*(c+n*flag+k)==0&&*(A+n*b+k)!=-1){
           *(c+n*flag+k)=k+1;
           *sum=*sum+*(A+n*b+k); 
           if(flag<n){
               for ( int i = flag+1; i < n; i++)
               {
                   *(c+i*n+k)=k+1;
               }
               
           }
           if(flag<n-1){
               TSP(c,A,sum,fsum,flag,n,k,a);
           }
           if(flag==n-1){
                if(*sum<*fsum){
                    //printf("this is fsum: %d\n",*sum);
                   *fsum=*sum;
               }
               
           }
           for (int i = flag; i < n; i++)
           {
               *(c+n*i+k)=0;
           }
           *sum=*sum-*(A+n*b+k);
        }
    }
    
}
int TSP_cmd(){
    int n;
    scanf("%d",&n);
     //printf("n is: %d\n",n);
    int cities[n];
    for (int i = 0; i < n; i++)
    {
      int city;
      scanf("%d",&city);
       //printf("city is: %d\n",city);
      cities[i]=city;  
    }
    //printf("we done with scan\n");
    int c[n][n],A[n][n],fsum=INT_MAX,sum=0,min=INT_MAX;
    for (int  i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i!=j){
                //printf("we start with short path");
                A[i][j]=shortsPath_cmd(cities[i],cities[j]);
            }else{
             A[i][j]=0;
            }
        }
    } 
    //printf("we done with a\n");
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("%d,",A[i][j]);
    //     }
    // }
    
    
    //printf("we done with c\n");
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j]=0;
        }
        
    }
        for (int j = 0; j < n; j++)
        {
            c[j][i]=i+1;
        }
        TSP(*c,*A,&sum,&fsum,0,n,i,i);
        //printf("we done with tsp\n");
        if(fsum!=-1&&fsum<min&&fsum!=0){
            min=fsum;
        }
        sum=0;
        fsum=INT_MAX;
    }
    
      
    
//     vector<int> vertex;
//     for (int i = 1; i < n; i++)
//         vertex.push_back(i);
//     int min_path = INT_MAX;
//     do {
//         int current_pathweight = 0;
//         int k = 0;
//         for (int i = 0; i < vertex.size(); i++) {
//             if (c[k][vertex[i]]==INT_MAX)
//             {
//                 current_pathweight=INT_MAX;
//                 break;
//             }
//             current_pathweight += c[k][vertex[i]];
//             k = vertex[i];
//         }
//         if (c[k][0]==INT_MAX)
//         {
//             current_pathweight=INT_MAX;
//         }else{
//             current_pathweight += c[k][0];
//         }
//         min_path = min(min_path, current_pathweight);
//     } while (
//         next_permutation(vertex.begin(), vertex.end()));
//     if(min_path==INT_MAX){
//         return -1;
//     }else{
//         return min_path;
//     }
//     }
    
   
    

    
//     int min=INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if(i!=j){

//             }
//         }
        
//     }
    
    
       
    
if(min==INT_MAX){
    return-1;
}else{
    return min;
}
 }
