#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next ;
	struct Node *prev;
};
typedef struct Node *node;

node insert_rear(int item, node head);
node insert_front(int item, node head);
node getnode();
void display_list_forward(node head);
void display_list_backward(node head);
node delete_rear(node head);
node delete_front(node last);
node delete_pos(node head,int pos);
node insert_pos(node head,int item,int pos);

int main()
{
	node head = NULL;
	int choice,item,pos;

	printf("\n.................Double Linked List(left and right)..............\n");
	while(1)
	{
		printf("\n1-Insert front\n2-Display Forward\n3-Insert Rear\n4-Delete front\n5-Delete Rear\n6-Insert Pos\n7-Display Backward\n8-Delete Pos\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter item to be Inserted in head list\n");
                    scanf("%d",&item);
                    head=insert_front(item,head);
                    break;
			case 2: printf("Display List Inserted\n");
                    display_list_forward(head);
                    break;
	 		case 3 :printf("Enter item to be Inserted\n");
                    scanf("%d",&item);
                    head=insert_rear(item,head);
                    break;

	 		case 4: printf("Rear element delete\n");
                    head=delete_front(head);
                    break;

			case 5: printf("Front element delete\n");
                    head=delete_rear(head);
                    break;

            case 6: printf("enter item and position to be inserted\n");
                    scanf("%d%d",&item,&pos);
                    head=insert_pos(head,item,pos);
                    break;

            case 7: printf("Display List Backward\n");
                    display_list_backward(head);
                    break;

            case 8: printf("enter position to be deleted\n");
                    scanf("%d",&pos);
                    head=delete_pos(head,pos);
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
	t->next = NULL;
	t->prev = NULL;
	return t;
}

void display_list_forward(node head)
{
	node t;
	if(head==NULL)
	{
		printf("Empty List\n");
		return;
	}
	printf("elements are\n");
	t=head;
	while(t->next!=NULL)
	{
		printf("%d\t",t->data);
		t= t->next;
	}
    printf("%d\t",t->data);
	return;
}

void display_list_backward(node head)
{
	node t,p;
	if(head==NULL)
	{
		printf("Empty List\n");
		return;
	}
	printf("elements are\n");
	t=head;
	while(t->next!=NULL)
	{
	    t= t->next;
	}
	p=t;
	while(p->prev!=NULL)
	{
		printf("%d\t",p->data);
		p= p->prev;
	}
    printf("%d\t",p->data);
    return;
}

node insert_front(int item, node head)
{
	node t,c;
	t=getnode();
	t->data = item;
	if(head ==NULL)
        return t;
    t->next=head;
    head->prev=t;
    return t;
}

node insert_rear(int item,node head)
{
    node t,c;
	t=getnode();
	t->data = item;
	if(head ==NULL)
        return t;
        c=head;
     while(c->next!=NULL)
     {
     	c= c->next;
     }
    c->next=t;
    t->prev=c;
    return head;
}

node delete_front(node head)
{
    node t =head;
    if(head==NULL)
    {
        printf("Empty List\n");
        return NULL;
    }
    if(head->next==NULL && head->prev==NULL)
    {
        printf("Element to be deleted is : %d\n",head->data);
        free(head);
        return NULL;
    }
    head=t->next;
    head->prev=NULL;
    printf("Element to be deleted is : %d\n",t->data);
    free(t);
    return head;
}

node delete_rear(node head)
{
    node t ,c;
    if(head==NULL)
    {
        printf("Empty List\n");
        return NULL;
    }
    if(head->next==NULL && head->prev==NULL)
    {
        printf("Element to be deleted is : %d\n",head->data);
        free(head);
        return NULL;
    }
    t =head;
    while(t->next != NULL)
    {
        t=t->next;
    }
    c=t->prev;
    c->next=NULL;
    printf("Element to be deleted is : %d\n",t->data);
    free(t);
    return head;
}


node insert_pos(node head,int item,int pos)
{
    node t,prev,c;
    int count=1;
    if(pos==1)
    {
        head=insert_front(item,head);
        return head;
    }
    t=getnode();
    t->data=item;
    if(head==NULL)
    {
        return t;
    }

    c=head;
    while(c->next!=NULL && pos!=count)
    {
        prev=c;
        c=c->next;
        count++;
    }
    if(pos<=count){

        prev->next=t;
        t->prev=prev;
        t->next=c;
        c->prev=t;}
    if(pos==count+1)
    {
        c->next=t;
        t->prev=c;
    }
    if(pos>count+1)
    {
        printf("Invalid Pos\n");
    }
    return head;
}


node delete_pos(node head,int pos)
{
    node prev,c;
    int count=1;
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    else if(pos==1)
    {
        head=delete_front(head);
    }
    else
    {
        c=head;
        while(c->next!=NULL && pos!=count)
        {
            prev=c;
            c=c->next;
            count++;
        }
        if(pos<=count)
        {
            prev->next=c->next;
            (c->next)->prev=prev;
            free(c);
        }
        if(pos==count &&c->next==NULL)
        {
            head=delete_rear(head);
        }
        if(pos>count)
        {
            printf("Invalid Pos\n");
        }
    }

    return head;
}

