#include<stdio.h>
#include<stdlib.h>
#define MIN_INT -32768

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

int max(struct Node *p){
    int m=MIN_INT;
    while(p!=NULL){
        if(p->data>m)
            m=p->data;
        p=p->next;
    }
    return m;
}

int Rmax(struct Node *p){
    int x=0;
    if(p==0)
        return MIN_INT;
    x=Rmax(p->next);
    return x>p->data?x:p->data;
}


int main(){

    int A[]={3,5,7,10,15};

    create(A,5);

    RDisplay(first);
    printf("\n");
    printf("Max element: %d \n",max(first));
    printf("Max element Recursion: %d \n",Rmax(first));

    return 0;
}
