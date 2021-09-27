#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first;

void create(int A[],int n){

    int i;
    struct Node *t,*last;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));

        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

}

void RDisplay(struct Node *p){

    if(p!=NULL){
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

int count(struct Node *p){
    int n=0;

    while(p!=NULL){
        n+=1;
        p=p->next;
    }
    return n;
}

int RCount(struct Node *p){

    if(p){
        return RCount(p->next)+1;
    }
    else
        return 0;
}

int R2Count(struct Node *p){
    if(p==0)
        return 0;
    else
        return R2Count(p->next)+1;
}

int R3Count(struct Node *p){
    int x=0;
    if(p){
        x=R3Count(p->next);
        return x+1;
    }
    else
        return x;
}

int main(){

    int A[]={3,5,7,10,15};

    create(A,5);

    RDisplay(first);
    printf("\n");
    printf("Nor of Nodes: %d \n",count(first));
    printf("Nor of Nodes Recursion: %d \n",RCount(first));
    printf("Nor of Nodes Recursion 2: %d \n",R2Count(first));
    printf("Nor of Nodes Recursion 3: %d \n",R3Count(first));

    return 0;
}


