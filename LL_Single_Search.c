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


struct Node * LinearSearch( struct Node *p, int key){
    struct Node *q;

    while(p!=NULL){
        if(key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;

            return p;
        }
        q=p;
        p=p->next;
    }

    return NULL;
}

struct Node * RLinearSearch( struct Node *p, int key){
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return RLinearSearch(p->next,key);
}


int main(){
    struct Node *temp;
    int A[]={3,5,7,10,15};

    create(A,5);

    RDisplay(first);
    printf("\n");
    temp=LinearSearch(first,10);
    //temp=LinearSearch(first,7);
    if(temp)
        printf("Key is Found %d\n", temp->data);
    else
        printf("Key not found\n");

    RDisplay(first);
    return 0;
}
