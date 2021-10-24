// Program to calculate the sum of n numbers entered by the user

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n,n1,n2, i, *ptr, sum = 0;
    
    //maloc
    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    ptr = (int*)malloc(n * sizeof(int));
    if(ptr == NULL){
        printf("Memory not allocated.");
        exit(0);
    }

    printf("\nEnter elements: ");
    for(i = 0; i < n; ++i){
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    printf("Sum = %d", sum);
    free(ptr);

    //calloc
    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    ptr = (int*) calloc(n, sizeof(int));
    if(ptr == NULL){
        printf("Memory not allocated.");
        exit(0);
    }

    printf("\nEnter elements: ");
    for(i = 0; i < n; ++i) {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    printf("Sum = %d", sum);
    free(ptr);

    //relloc
    printf("\nEnter size: ");
    scanf("%d", &n1);

    //allocate using malloc
    ptr = (int*) malloc(n1 * sizeof(int));

    printf("Addresses of previously allocated memory:\n");
    for(i = 0; i < n1; ++i)
        printf("%pc\n",ptr + i);

    printf("\nEnter the new size: ");
    scanf("%d", &n2);

    //rellocating the memory
    ptr = realloc(ptr, n2 * sizeof(int));

    printf("Addresses of newly allocated memory:\n");
    for(i = 0; i < n2; ++i)
        printf("%pc\n", ptr + i);
  
    free(ptr);


    return 0;
}
