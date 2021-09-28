#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

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

void create2(int A[],int n){

    int i;
    struct Node *t,*last;

    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;

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

void concat(struct Node *p, struct Node *q){
    third=p;

    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
}



int main(){
    struct Node *temp;
    int A[]={3,5,7,9,11};
    int B[]={2,4,6,8,10};

    create(A,5);
    create2(B,5);

    RDisplay(first);
    printf("\n");
    RDisplay(second);

    concat(first,second);
    printf("\n");
    RDisplay(third);

    return 0;
}






