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



void RemoveDuplicate(struct Node *p){
    struct Node *q=p->next; // p is tail pointer p follows q

    while(q!=NULL){
        if(p->data!=q->data){ // prev and next not same
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }

}
int main(){
    struct Node *temp;
    int A[]={3,3,5,7,7,15};

    create(A,5);

    RDisplay(first);
    printf("\n");

    RemoveDuplicate(first);

    RDisplay(first);
    return 0;
}





