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


int Delete(struct Node *p,int index){
    struct Node *q=NULL;
    int x=-1;

    if(index<1 || index > count(p)) //invalid index element not deleted
        return -1;

    if(index==1) //if first node
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else{
        for(int i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }

}


int main(){
    struct Node *temp;
    int A[]={3,5,7,10,15};

    create(A,5);

    RDisplay(first);
    printf("\n");
    printf("Deleted element %d\n",Delete(first,2)); //delete 5

    RDisplay(first);
    return 0;
}



