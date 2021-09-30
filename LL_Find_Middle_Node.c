#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

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

int FindMiddle(struct Node *f){
    struct Node *p,*q;
    p=q=f;

    while(q!=NULL){
        q=q->next;
        if(q) q=q->next;
        if(q) p=p->next;
    }
    return p->data;
}

int main(){
    struct Node *temp;
    int A[]={3,5,7,9,11};

    create(A,5);

    RDisplay(first);
    printf("\n");


    printf("\nMiddle Node: %d",FindMiddle(first));
    printf("\n");


    return 0;
}







