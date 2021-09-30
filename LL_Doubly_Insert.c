#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;


void create(int A[],int n){
    struct Node *t,*last;

    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p){
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int Length(struct Node *p){
    int l=0;

    while(p){
        l++;
        p=p->next;
    }

    return l;
}

void Insert(struct Node *p,int index, int x){
    struct Node *t;

    if(index<0 || index>Length(p))
        return;

    if(index==0){ //Insert before first node
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;

        t->prev=p;
        t->next=p->next;
        if(p->next) p->next->prev=t;
        p->next=t;
    }
}

int main(){
    int A[]={2,4,6,8,10};
    create(A,5);

    Insert(first,0,1);

    Display(first);
    return 0;
}

