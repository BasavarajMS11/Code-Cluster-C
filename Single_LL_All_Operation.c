#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *NODE;

NODE getnode();
void display(NODE head);
NODE insert_front(NODE head,int);
NODE insert_last(NODE head,int);
NODE insert_position(NODE head,int,int);
NODE delete_front(NODE head);
void delete_last(NODE head);
NODE delete_position(NODE head,int);
void search(NODE head,int);


int main()
{
    NODE head=NULL;
    int num,ch,pos;
    printf("\n.................Single Linked List(next)..............\n");
    printf("Please Enter the below choices to chose the operation\n");
    while(ch!=9)
    {
        printf("\n\n1:Insert at the front of list\n2:Display the list\n3:Insert at last of the list\n"
               "4:Delete first node of list\n5:Delete last node\n6:Insert at any position\n"
               "7:Delete at any position\n8:Search an Element\n9:Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the data into list\n");
                    scanf("%d",&num);
                    head=insert_front(head,num);
                    break;
            case 2: display(head);
                    break;
            case 3: printf("Enter the data into list\n");
                    scanf("%d",&num);
                    head=insert_last(head,num);
                    break;
            case 4: head=delete_front(head);
                    break;
            case 5: delete_last(head);
                    break;
            case 6: printf("Enter the position you want to insert into list\n");
                    scanf("%d",&pos);
                    printf("Enter the data into list\n");
                    scanf("%d",&num);
                    head=insert_position(head,num,pos);
                    break;
            case 7: printf("Enter the position to be deleted\n");
                    scanf("%d",&pos);
                    delete_position(head,pos);
                    break;
            case 8: printf("Enter data to be searched\n");
                    scanf("%d",&num);
                    search(head,num);
                    break;
            default: printf("Enter the correct choice\n");
                    break;
        }

    }
}



NODE getnode()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(NODE));
    temp->next = NULL;
    if(temp==NULL)
    {
        printf("NO memory available\n");
        exit(0);
    }
    return temp;
}

NODE insert_front(NODE head,int data)
{
    NODE new_node;
    new_node = getnode();
    new_node->data = data;
    new_node->next = head;
    head=new_node;
    return new_node;
}
void display(NODE head)
{
    NODE temp;
    if(head==NULL)
    {
        printf("List is Empty\n");
        exit(0);
    }
    temp = head;
    printf("The Contents of the list is as below:\n");
    while(temp->next != NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
NODE insert_last(NODE head,int data)
{
    NODE new_node,cur;
    new_node = getnode();
    new_node->data = data;
    new_node->next = NULL;
    if(head == NULL)
    {
        return new_node;
    }
    cur = head;
    while(cur->next!=NULL)
    {
        cur = cur->next;
    }
    cur->next = new_node;
    return head;
}
NODE insert_position(NODE head,int data,int pos)
{
    int count=0;
    NODE new_node,cur,prev;
    new_node = getnode();
    new_node->data = data;
    new_node->next = NULL;
    if(head == NULL && pos==1)
    {
        return new_node;
    }
    if(head == NULL)
    {
        printf("Invalid Position\n");
        return head;
    }
    if(pos==1)
    {
        new_node->next=head;
	return new_node;
    }
    count = 1;
    prev = NULL;
    cur = head;
    while(cur->next!= NULL && count!=pos)
    {
        prev = cur;
        cur = cur->next;
        count++;
    }
    if(count==pos)
    {
        prev->next = new_node;
        new_node->next =cur;
        return head;

    }

}
NODE delete_front(NODE head)
{
    NODE temp;
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    temp = head;
    head = head->next;
    printf("First Node deleted is:%d\n",temp->data);
    free(temp);
    return head;

}
void delete_last(NODE head)
{
    NODE cur,prev;
    if(head == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    cur = head;
    while(cur->next!=NULL)
    {
        prev=cur;
        cur = cur->next;
    }
    printf("Last Node deleted is:%d",cur->data);//prev->next=NULL;
    free(cur);
    prev->next=NULL;
    //return head;

}
NODE delete_position(NODE head,int pos)
{
    int count=0;
    NODE new_node,cur,prev;
    if(head == NULL && pos<=0)
    {
        printf("Invalid Position\n");
        return NULL;
    }
    if(pos==1)
    {
        cur = head;
        head = head->next;
        free(cur);
        return head;
    }
    count = 1;
    prev = NULL;
    cur = head;
    while(cur!= NULL)
    {
        if(count==pos)
            break;
        prev = cur;
        cur = cur->next;
        count++;
    }
    if(count!=pos)
    {
        printf("Invalid count Position\n");
        return head;
    }
    prev->next = cur->next;
    free(cur);
    return head;
}
void search(NODE head,int key)
{
    NODE cur;
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
