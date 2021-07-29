#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* array;
};


struct Queue* createQueue(unsigned capacity)
{
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}


int isFull(struct Queue* queue)
{
	return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue)
{
	return (queue->size == 0);
}


void enqueue(struct Queue* queue, int item)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	printf("%d enqueued to queue\n", item);
}


int dequeue(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1)
				% queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

int front(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

int rear(struct Queue* queue)
{
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

// Driver program to test above functions./
int main()
{
	struct Queue* queue = createQueue(1000);

	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);

	printf("%d dequeued from queue\n\n",
		dequeue(queue));

	printf("Front item is %d\n", front(queue));
	printf("Rear item is %d\n", rear(queue));

	/*int choice,item,pos;
	while(1)
	{
		printf("\n1-Insert element(Enqueue)\n2-Delete Element(Dequeue) Forward\n3-Insert Rear\n4-Delete front\n5-Delete Rear\n6-Insert at Position\n7-Display Backward\n8-Delete at Position\n");
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
	}*/

	return 0;
}

