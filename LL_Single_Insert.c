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

void Insert(struct Node *p, int index, int x){
    struct Node *t;
    if(index<0 || index > count(p)){
        return;
    }
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index==0){
        t->next=first;
        first=t;
    }
    else{

        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }

}


int main(){
    struct Node *temp;
    int A[]={3,5,7,10,15};

    create(A,5);

    RDisplay(first);
    printf("\n");
    Insert(first,0,2);
    Insert(first,6,20);
    Insert(first,2,4);

    RDisplay(first);
    return 0;
}

