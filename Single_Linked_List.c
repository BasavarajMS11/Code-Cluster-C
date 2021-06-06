#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;

};

typedef struct Node *node;
node insert_rear(int item, node first);
node insert_front(int item, node first);
node getnode();
void display_list(node first);
node insert_pos(int item, int pos,node first);
node delete_rear(node first);
node delete_front(node first);
node delete_pos(int pos,node first);
void search(int key,node first);

main()
{
	node first = NULL;
	int choice ,item,pos;
	while(1)
	{
		printf("\n\nPress\n1-Insert Rear\n2-Display\n3-Insert front\n4-Insert at position\n5-Delete rear\n6-Delete front\n7-Delete at specified position\n8-Search\nAny-Exit\n\n\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\nEnter item to be Inserted\n");
			        scanf("%d",&item);
			        first=insert_rear(item,first);
			        break;
			case 2: printf("\nDisplay List Inserted\n");
			        display_list(first);
			        break;
			case 3: printf("\nEnter item to be Inserted\n");
			        scanf("%d",&item);
                    first=insert_front(item,first);
			        break;
			case 4: printf("\nEnter the position and item to be Inserted(Position starts from 1)\n");
			        scanf("%d%d",&pos,&item);
			        first=insert_pos(item,pos,first);
			        break;
			case 5: printf("\nRear element delete\n");
			        first=delete_rear(first);
			        break;
			case 6: printf("\nFront element delete\n");
                    first=delete_front(first);
                    break;
			case 7: printf("\nEnter the position and item to be Deleted(Position starts from 1)\n");
			        scanf("%d",&pos);
			        first=delete_pos(pos,first);
			        break;
            case 8: printf("\nEnter item to be searched\n");
                    scanf("%d",&item);
                    search(item,first);
                    break;
			default:exit(0);
		}
	}

}

node getnode()
{
	node t;
	t=(node *)malloc(sizeof(struct Node));
	if(t==NULL)
	{
		printf("Not created\n");
		exit(0);
	}
	t->next = NULL;
	return t;
}

void display_list(node first)
{
	node t;
	if(first==NULL)
	{
		printf("Empty List\n");
		return;
	}
	printf("elements are\n");
	t=first;
	while(t!=NULL)
	{
		printf("%d\t",t->data);
		t= t->next;
	}
	printf("\n");
}
node insert_rear(int item, node first)
{
	node t,c;
	t=getnode();
	t->data = item;
	t ->next = NULL;
	if(first ==NULL)
	  return t;
	c=first;
	while(c->next !=NULL)
	{
		c=c->next;
	}
	c->next = t;
	return c;
}

node insert_front(int item, node first)
{
	node t,c;
	t=getnode();
	t->data = item;
	t ->next = NULL;
	if(first ==NULL)
	  return t;
	t ->next = first;
	return t;
}
node delete_front(node first)
{
    node t;
    if(first==NULL)
	  {
	      printf("list empty\n");
	      return first;

	  }
	  t= first;
	 first =first->next;
	  printf("item deleted is %d\n",t->data);
	  free(t);
	  return first;
}


node insert_pos(int item ,int pos, node first)
{

    node t,prev,cur;
    int count;
    t=getnode();
	t->data = item;
	t ->next = NULL;
	if(first ==NULL &&pos==1)
	  return t;
    if(first ==NULL)
    {

        printf("invalid position\n");
        return first;
    }
if(pos==1)
{

    t->next= first;
    return t;
}
count=1;
prev=NULL;
cur= first;
while(cur!=NULL && count!=pos)
{

    prev=cur;
    cur=cur->next;
    count++;
}
if(count==pos)
{

    prev->next=t;
    t->next=cur;
    return first;
    }
    return first;
}
node delete_rear(node first)
{
	node prev,c;
	if(first ==NULL)
	{
		printf("List empty\n");
		return first;
	}


	prev=NULL;
	c= first;
	while(c->next!=NULL)
	{
		prev=c;
		c=c->next;
	}
if(prev!=NULL)
prev->next=NULL;
if(c== first)
first =NULL;
	printf("item deleted is %d\n",c->data);
	free(c);
	return first;
}

node delete_pos(int pos,node first)
{
    node cur,prev;
    int count;

    if(first ==NULL)
	{
		printf("List empty\n");
		return NULL;
	}
	if(pos==1)
	{

	    cur= first;
	   first = first ->next;
	    free(cur);
	    return first;
	}
	prev=NULL;
	cur= first;
	count=1;
	while(cur!=NULL && count!=pos)
	{
	    prev=cur;
	    cur=cur->next;
	    count++;
	}
	if(cur==NULL)
	{

	    printf("invalid position specified\n");
	    return first;

	}
	prev->next=cur->next;
	free(cur);
	return first;
}

void search(int key,node head)
{
    node cur;
    int count=0;
    if(head == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    cur = head;
    while(cur->data!=key)
    {
        cur = cur->next;
        count++;
    }
    if(cur->data==key)
    {
        printf("Key element found at position:%d\n",count+1);
    }
}
