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

void RDisplay(struct Node *p){
    if(p!=NULL){
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

int checkloop(struct Node *first){
    struct Node *p,*q;
    p=q=first;

    do{
        p=p->next;
        q=q->next;
        q=(q!=NULL)?q->next:q;
    }while(p && q && p!=q);

    if(p==q)
        return 1;
    else
        return 0;
}



int main(){
    struct Node *t1,*t2;
    int A[]={3,5,7,9,11};
    create(A,5);

    t1=first->next->next; //make point upon node 3
    t2=first->next->next->next->next; //make point on last or 5th node
    t2->next=t1; //Making loop connecting 5th node to 3rd

    printf("\n");

    if(checkloop(first))
        printf("\nLoop\n");
    else
        printf("\nNo loop or Linear\n");

    return 0;
}






