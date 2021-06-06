#include <stdlib.h>
#include <stdio.h>
#define MAX 20

struct Node
{
int data;
struct Node *next,*front,*rear;
};

struct Node *front=NULL,*rear=NULL;

void enqueue(int x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("Queue is FUll\n");
    else
    {
        t->data=x;
        t->next=NULL;
        if(front==NULL)
            front=rear=t;
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}
int dequeue()
{
    int x=-1;
    struct Node* t;
    if(front==NULL)
        printf("Queue is Empty\n");
    else
    {
        x=front->data;
        t=front;
        front=front->next;
        free(t);
    }
    return x;
}

int isEmpty()
{
return front==NULL;
}

void BFS(int G[MAX][MAX],int start,int n)
{
    int i=start,j,visited[MAX],k;
//int visited[7]={0};
    for(k=0;k<=n;k++)
    {
        visited[k]=0;
    }
    printf("%d ",i);
    visited[i]=1;
    enqueue(i);
    while(!isEmpty())
    {
        i=dequeue();
        for(j=0;j<n;j++)
        {
            if(G[i][j]==1 && visited[j]==0)
            {
                printf("%d ",j);
                visited[j]=1;
                enqueue(j);
            }
        }
    }
}

void DFS(int G[MAX][MAX],int start,int n,int visited[MAX])
{
    int j,i;
    i=start;

    if(visited[i]==0)
    {
        printf("%d ",i);
        visited[i]=1;
        for(j=0;j<=n;j++)
        {
            if(G[i][j]==1 && visited[j]==0)
               DFS(G,j,n,visited);
        }
    }
}
int main()
{
    int n,G[MAX][MAX],i,j,k,start,visited[MAX],ch;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter adjacency MATRIX:");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&G[i][j]);
        }
    }
    printf("Enter starting vertex:");
    scanf("%d",&start);
    while(1)
    {
        printf("\nEnter choice:\n1-BFS\n2-DFS");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("BFS ORDER:");
                   BFS(G,start,n);
                   break;
            case 2:printf("DFS ORDE:");
                   for(k=0;k<n;k++)
                   {
                      visited[k]=0;
                   }
                   DFS(G,start,n,visited);
                   break;
            default:exit(0);
        }

    }

    return 0;
}
