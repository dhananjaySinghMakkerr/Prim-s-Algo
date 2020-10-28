#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include <queue>
using namespace std;

typedef struct edge
{
    char name;
    int index;
    int weight;
    struct edge* nxt;
}edge;

typedef struct vertex
{
    char name;
    int status;
    int  distance;
    int predessor;
    edge* next;

}vertex;

vertex graph[10];

void initializeGraph(char name)
{
    int i=0;
    for(i=0;i<10;i++)
    {
        if(graph[i].name=='0')
        {
            graph[i].name=name;
            break;
        }
    }
}

void Edge(char s,char o,int w)
{
    edge* temp=(edge*)malloc(sizeof(edge));
    temp->name=o;
    temp->nxt=NULL;
    temp->weight=w;
    int i=0;
    int index;
    for(i=0;i<9;i++)
    {
        if(graph[i].name==o)
        {
            index=i;
            break;
        }
    }
    temp->index=index;
    for(i=0;i<9;i++)
    {
        if(graph[i].name==s)
        {
            edge* p=graph[i].next;
            if(p==NULL)
            {
                graph[i].next=temp;
            }
            else
            {
            while(p->nxt!=NULL)
            {
                p=p->nxt;
            }
            p->nxt=temp;
            }
            break;
        }
    }
}


void MST_Prim(int index)
{
    int i,sum;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    int j;
    for(i=0;i<9;i++)
    {
        graph[i].predessor=-1;
        graph[i].distance=INT_MAX;
        graph[i].status=0;
    }
    graph[0].distance=0;
    for(i=0;i<9;i++)
    {
         pair<int,int> p;
        p=make_pair(graph[i].distance,i);
        q.push(p);
    }
    //graph[index].distance=0;
    while(q.size()!=0)
    {
        j=q.top().second;
        q.pop();
        edge* p=graph[j].next;
         graph[j].status=1;
         printf("  %c  ",graph[j].name);

        while(p!=NULL)
        {
            if((p->weight)<graph[p->index].distance&&graph[p->index].status!=1)
            {
                graph[p->index].distance=p->weight;

                graph[p->index].predessor=j;
                while(q.size()!=0)
                {
                    q.pop();
                }
                for(i=0;i<9;i++)
                {
                    if(graph[i].status!=1)
                        q.push(make_pair(graph[i].distance,i));
                }

            }
            p=p->nxt;
        }
    }



}




int main()
{

int i,sum=0;
for(i=0;i<9;i++)
{
    graph[i].name='0';
}
    initializeGraph('a');
    initializeGraph('b');
    initializeGraph('c');
    initializeGraph('d');
    initializeGraph('e');
      initializeGraph('f');
        initializeGraph('g');
        initializeGraph('h');
          initializeGraph('i');
    Edge('a','b',4);
    Edge('b','a',4);
    Edge('a','h',8);
    Edge('h','a',8);
    Edge('b','c',8);
    Edge('c','b',8);
    Edge('b','h',11);
    Edge('h','b',11);
Edge('h','g',1);
    Edge('g','h',1);
    Edge('h','i',7);
    Edge('i','h',7);
    Edge('g','i',6);
    Edge('i','g',6);
    Edge('g','f',2);
    Edge('f','g',2);
    Edge('f','c',4);
    Edge('c','f',4);
    Edge('f','d',14);
    Edge('d','f',14);
    Edge('f','e',10);
    Edge('e','f',10);
    Edge('e','d',9);
    Edge('d','e',9);
    Edge('d','c',7);
    Edge('c','d',7);
    Edge('c','i',2);
    Edge('i','c',2);
MST_Prim(0);
printf("\n");
for(i=0;i<9;i++)
{

printf(" %c---->%c   %d\n ",graph[i].name,graph[graph[i].predessor].name,graph[i].distance);

}
for(i=0;i<9;i++)
    {
        sum=sum+graph[i].distance;
    }

printf("%d",sum);
    //_getch();
    return 0;

}
