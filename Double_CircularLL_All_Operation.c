#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *rlink ;
	struct Node *llink;
};

typedef struct Node *node;
node insert_rear(int item, node first);
node insert_front(int item, node first);
node getnode();
void display_list_forward(node first);
void display_list_backward(node first);
node delete_rear(node first);
node delete_front(node last);
node delete_pos(node first,int pos);
node insert_pos(node first,int item,int pos);

int main()
{
	node first = NULL;
	int choice,item,pos;
	while(1)
	{
		printf("\n1-Insert front\n2-Display Forward\n3-Insert Rear\n4-Delete front\n5-Delete Rear\n6-Insert at Position\n7-Display Backward\n8-Delete at Position\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter item to be Inserted in first list\n");
                    scanf("%d",&item);
                    first=insert_front(item,first);
                    break;
			case 2: printf("Display List Inserted\n");
                    display_list_forward(first);
                    break;
	 		case 3: printf("Enter item to be Inserted\n");
                    scanf("%d",&item);
                    first=insert_rear(item,first);
                    break;
	 		case 4: printf("Rear element delete\n");
                    first=delete_front(first);
                    break;
			case 5: printf("front element delete\n");
                    first=delete_rear(first);
                    break;
            case 6: printf("enter item and position to be inserted\n");
                    scanf("%d%d",&item,&pos);
                    first=insert_pos(first,item,pos);
                    break;
            case 7: printf("Display List Backward\n");
                    display_list_backward(first);
                    break;
            case 8: printf("enter position to be deleted\n");
                    scanf("%d",&pos);
                    first=delete_pos(first,pos);
                    break;
            default: exit(0);
		}
	}

}

node getnode()
{
	node t;
	t=(node )malloc(sizeof(struct Node));
	if(t==NULL)
	{
		printf("Not created\n");
		exit(0);
	}
	t->rlink = t;
	t->llink = t;
	return t;
}

void display_list_forward(node first)
{
	node t;
	if(first==NULL)
	{
		printf("Empty List\n");
		return;
	}
	printf("elements are\n");
	t=first;
	while(t->rlink!=first)
	{
		printf("%d\t",t->data);
		t= t->rlink;
	}
    printf("%d\t",t->data);
	return;
}

void display_list_backward(node first)
{
	node t,p;
	if(first==NULL)
	{
		printf("Empty List\n");
		return;
	}
	printf("elements are\n");
	p=first->llink;

	while(p!=first)
	{
		printf("%d\t",p->data);
		p= p->llink;
	}
    printf("%d\t",p->data);
    return;
}

node insert_front(int item, node first)
{
	node t,c;
	t=getnode();
	t->data = item;
	if(first ==NULL)
        return t;
    else
    {
        node last=first->llink;
        t->rlink=first;
        first->llink=t;
        first=t;
        last->rlink=first;
        first->llink=last;
        return first;
    }
}
node insert_rear(int item,node first)
{
    node t,c;
	t=getnode();
	t->data = item;
	if(first ==NULL)
        return t;
    else
    {
        node last=first->llink;
        t->rlink=first;
        first->llink=t;
        last->rlink=t;
        t->llink=last;

        return first;
    }
}
node delete_front(node first)
{
    node last,t =first;
    if(first==NULL)
    {
        printf("Empty List\n");
        return NULL;
    }
    if(first->rlink==first && first->llink==first)
    {
        printf("Element to be deleted is : %d\n",first->data);
        free(first);
        return NULL;
    }
    else
    {
        last=first->llink;
        first=t->rlink;
        first->llink=last;
        last->rlink=first;
        printf("Element to be deleted is : %d\n",t->data);
        free(t);
    }
    return first;
}
node delete_rear(node first)
{
    node t ,c;
    if(first==NULL)
    {
        printf("Empty List\n");
        return NULL;
    }
    if(first->rlink==first && first->llink==first)
    {
        printf("Element to be deleted is : %d\n",first->data);
        free(first);
        return NULL;
    }
    t =first;

    while(t->rlink != first)
    {
        t=t->rlink;
    }
    t->llink->rlink=first;
    first->llink=t->llink;

    printf("Element to be deleted is : %d\n",t->data);
    free(t);
    return first;
}

node insert_pos(node first,int item,int pos)
{
    node t,prev,c;
    int count=1;
    if(pos==1)
    {
    first=insert_front(item,first);
    return first;
    }
    t=getnode();
    t->data=item;
    if(first==NULL)
    {
        return t;
    }

    c=first;
    while(c->rlink!=first && pos!=count)
    {
        prev=c;
        c=c->rlink;
        count++;
    }
    if(pos<=count){

        prev->rlink=t;
        t->llink=prev;
        t->rlink=c;
        c->llink=t;
    }
    if(pos==count+1)
    {
        c->rlink=t;
        t->llink=c;
        first->llink=t;
        t->rlink=first;
    }
    if(pos>count+1)
    {
        printf("Invalid Pos\n");
    }
    return first;
}

node delete_pos(node first, int pos)
{
    node t,pr;
    int i,count=1;

    t=first;
    if(first==NULL)
    {
        exit(0);
    }
    if(pos==1)
    {
        first=delete_front(first);
        return first;
    }
    if(pos==count)
    {
        first=delete_rear(first);
        return first;
    }

    while(t->rlink!=first && pos!=count)
    {
        pr=t;
        t=t->rlink;
        count++;
    }

    pr->rlink=t->rlink;
    (t->rlink)->llink=pr;
    free(t);
    return first;
}
