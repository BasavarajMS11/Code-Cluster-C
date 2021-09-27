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

int Add(struct Node *p){
    int sum=0;
    while(p!=NULL){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int RAdd(struct Node *p){
    if(p==0){
        return 0;
    }
    else
        return RAdd(p->next)+p->data;

}


int main(){

    int A[]={3,5,7,10,15};

    create(A,5);

    RDisplay(first);
    printf("\n");
    printf("Sum of elements: %d \n",Add(first));
    printf("Sum of elements Recursion: %d \n",RAdd(first));

    return 0;
}
