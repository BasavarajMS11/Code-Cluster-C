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

void Reverse1(struct Node *p){ //Using Array
    int *A,i=0;
    struct Node *q=p;

    A=(int *)malloc(sizeof(int)*count(p));

    while(q!=NULL){
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL){
        q->data=A[i];
        q=q->next;
        i--;
    }
}

void Reverse2(struct Node *p){ // Using 3 sliding pointers
    struct Node *q=NULL, *r=NULL;

    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void Reverse3(struct Node *q, struct Node *p){
    if(p){
        Reverse3(p,p->next);
        p->next=q;
    }
    else
        first=q;
}

int main(){
    struct Node *temp;
    int A[]={3,5,7,9,11};

    create(A,5);

    RDisplay(first);
    printf("\n");

    Reverse3(NULL,first);

    RDisplay(first);
    return 0;
}






