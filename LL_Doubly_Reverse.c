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

void Reverse(struct Node *p){
    struct Node *temp;

    while(p!=NULL){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL){
            first=p;
        }
    }
}

int main(){
    int A[]={2,4,6,8,10};
    create(A,5);

    Display(first);
    Reverse(first);
    Display(first);

    return 0;
}

