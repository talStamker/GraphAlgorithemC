#include <stdio.h>
#include "graph.h"
#include <string.h>
#include<limits.h>
#include<ctype.h>
#include <stdlib.h>
//elements:
static pnode head;
static int size=0;
static pQe Q;
static pnode min;
static int sizeQ=0;

/////////queue////////
void insert(pnode n){
    pQe currentQ;
    if(Q==NULL)
    {//beginning
        Q=(pQe)malloc(sizeof(Qe));
        Q->arr=n;
        min=n;
        Q->next=NULL;
        currentQ=Q;
    }else{//continue
        currentQ=Q;
        while (currentQ->next!=NULL)
        {
            currentQ=currentQ->next;
        }
        currentQ->next=(pQe)malloc(sizeof(Qe));
        currentQ->next->arr=n;
        currentQ->next->next=NULL;
        if (n->d < min->d)
        {
            min=n;
        }
    }
    sizeQ++;
}

void updateMin(int key){
    pQe currentQ=Q;
    int minimum=INT_MAX;
    int isChange=1;
    while (currentQ!=NULL)
    {
        if (currentQ->arr->d < minimum )
        {
            min=currentQ->arr;
            minimum=currentQ->arr->d;
            isChange=0;
        }
        if (currentQ->next==NULL&&isChange==1)
        {
            min=currentQ->arr;
        } 
        currentQ=currentQ->next;
    } 
}

void delete(){
    pQe currentQ=Q;
    if(currentQ->arr->d==min->d){
        pQe temp=Q;
        Q=Q->next;
        free(temp);
        
    }else{
        while (currentQ->next->arr->key!=min->key)
        {
            currentQ=currentQ->next;
        }
        pQe temp=currentQ->next;
        currentQ->next=currentQ->next->next;
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

///////graph/////
char build_graph_cmd()
{
    int n;
    char isN;
    scanf("%d", &n);
    scanf("%c", &isN);
    scanf("%c", &isN);
    for (int  i = 0; i < n; i++)
    {
        isN= insert_node_cmd();
    }
    return isN;
}

char insert_node_cmd()
{   
    int id;
    pnode currentNode;
    scanf("%d", &id);
    pnode currentN;
    if(head==NULL){//beginning
        head=(pnode)malloc(sizeof(node));
        head->key=id;
        head->next=NULL;
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
        currentN->next->next=NULL;
        currentNode=currentN->next;
        pnode V=head;
        pedge E=NULL;
        currentN->next->edges=NULL;
            while (V!=NULL)
            {//update all dest
                 E=V->edges;
                while (E!=NULL)
                {
                    if(E->dest==id){
                        E->de=currentN->next;
                     }
                    E=E->next;
                }
                V=V->next;  
            }
        }else{
            pedge E=currentN->next->edges;
            while (E!=NULL)
            {
                pedge temp=E;
                E=E->next;
                free(temp);
            }  
            currentN->next->edges=NULL;
            char temp,w,dest;
            scanf("%c",&temp);
            scanf("%c",&dest);
            if(dest<'0'||dest>'9')
            {
                return dest;
            }
            scanf("%c",&temp);
            scanf("%c",&w);
            currentN->next->edges=(pedge)malloc(sizeof(edge));
            currentN->next->edges->dest=(int)(dest)-48;
            currentN->next->edges->w=(int)(w)-48;
            currentN->next->edges->next=NULL;
            pnode v1=head;
            while (v1!=NULL)
            {
             if (currentN->next->edges->dest==v1->key)
                {
                currentN->next->edges->de=v1;
                }
                v1=v1->next;   
            }
            pedge currentE=currentN->next->edges;
            while (1)
            {
                char temp,w,dest;
                scanf("%c",&temp);
                scanf("%c",&dest);
                if(dest<'0'||dest>'9')
                {
                    currentE->next=NULL;
                    return dest;
                }
                scanf("%c",&temp);
                scanf("%c",&w);
                currentE->next=(pedge)malloc(sizeof(edge));
                currentE->next->dest=(int)(dest)-48;
                currentE->next->w=(int)(w)-48;
                pnode v2=head;
                while (v2!=NULL)
                {
                    if (currentE->next->dest==v2->key)
                    {
                        currentE->next->de=v2;
                    }
                    v2=v2->next;   
                }
                currentE=currentE->next;
            }
        }
    }
    //add edge:
    char temp,w,dest;
    scanf("%c",&temp);
    scanf("%c",&dest);
    if(dest<'0'||dest>'9'){
        currentNode->edges=NULL;
        return dest;
    }
    scanf("%c",&temp);
    scanf("%c",&w);
    currentNode->edges=(pedge)malloc(sizeof(edge));
    currentNode->edges->dest=(int)(dest)-48;
    currentNode->edges->w=(int)(w)-48;
    currentNode->edges->next=NULL;
    pnode v1=head;
    while (v1!=NULL)
    {
        if (currentNode->edges->dest==v1->key)
        {
            currentNode->edges->de=v1;
        }
        v1=v1->next;   
    }
    pedge currentE=currentNode->edges;
    while (1)
    {
        char temp,w,dest;
        scanf("%c",&temp);
        scanf("%c",&dest);
        if(dest<'0'||dest>'9')
        {
            currentE->next=NULL;
            return dest;
        }
        scanf("%c",&temp);
        scanf("%c",&w);
        currentE->next=(pedge)malloc(sizeof(edge));
        currentE->next->dest=(int)(dest)-48;
        currentE->next->w=(int)(w)-48;
        pnode v2=head;
        while (v2!=NULL)
        {
            if (currentE->next->dest==v2->key)
            {
                currentE->next->de=v2;
            }
            v2=v2->next;   
        }
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
    if (containsN(data)==0)
    {
        return;
    }
    pnode currentNode=head;   
    if(currentNode->key==data){
        pedge E=currentNode->edges;
        while (E!=NULL)
        {
            pedge temp=E;
            E=E->next;
            free(temp);
        }
        pnode tem=head;
        head=head->next;
        free(tem);
    }else{
       
        while (currentNode->next->key!=data)
        {
            currentNode=currentNode->next;
        }
        pedge E=currentNode->next->edges;
        while (E!=NULL)
        {
            pedge temp=E;
            E=E->next;
            free(temp);
        }
        pnode tem=currentNode->next;
        currentNode->next=currentNode->next->next;
        free(tem);
    }
    currentNode=head;
    while (currentNode!=NULL)
    {
        pedge currentE=currentNode->edges;
        if (containsE(data,currentE)==1)
        {
            if(currentE->dest==data){
                pedge temp=currentNode->edges;
                currentNode->edges=currentNode->edges->next;
                free(temp);
            }else{
               while (currentE->next->dest!=data)
               {
                   currentE=currentE->next;
               }
               pedge temp=currentE->next;
               currentE->next=currentE->next->next;
               free(temp);   
            }
        }
        currentNode=currentNode->next; 
    }   
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
            currentE=currentE->next;
            free(temp);
        }
        pnode ptr=currentN;
        currentN=currentN->next;
        free(ptr); 
    }
    head=NULL;   
}

void relax(pnode u,pnode v,int w){
    if(u->d!=INT_MAX){
        if (v->d > u->d+w)
        {
            v->d =u->d+w;
        }
    }   
}

int shortsPath_cmd(int src,int dest){
    pnode currentN=head;
    while (currentN!=NULL)
    {
        currentN->d=INT_MAX;
        if(currentN->key==src){
            currentN->d=0;
        }
        insert(currentN);
        currentN=currentN->next;
    }
    while (isEmpty()==0)
    {
        delete();
        pedge E=min->edges;
        while (E!=NULL)
        {
            relax(min,E->de,E->w);
            E=E->next;
        }
        updateMin(min->key);     
    }
    pnode p=head;
    while (p !=NULL&&p->key!=dest)
    {
        p=p->next;
    }
    //freeQ();
    if(p->d==INT_MAX){
        return -1;
    }else{
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
    int cities[n];
    for (int i = 0; i < n; i++)
    {
      int city;
      scanf("%d",&city);
      cities[i]=city;  
    }
    int c[n][n],A[n][n],fsum=INT_MAX,sum=0,min=INT_MAX;
    for (int  i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i!=j){
                A[i][j]=shortsPath_cmd(cities[i],cities[j]);
            }else{
             A[i][j]=0;
            }
        }
    }  
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
        if(fsum!=-1&&fsum<min&&fsum!=0){
            min=fsum;
        }
        sum=0;
        fsum=INT_MAX;
    }
    if(min==INT_MAX){
        return-1;
    }else{
        return min;
    }
}
