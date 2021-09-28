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



int isSorted(struct Node *p){
    int x=-32678;

    while(p!=NULL){
        if(p->data<x){ //if next element is not greater
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
}

int main(){
    struct Node *temp;
    int A[]={3,5,7,10,15};

    create(A,5);

    RDisplay(first);
    printf("\n");

    if(isSorted(first)){
        printf("Is Sorted\n");
    }
    else{
        printf("Not Sorted\n");
    }


    RDisplay(first);
    return 0;
}




