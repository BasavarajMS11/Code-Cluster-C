#include<stdio.h> 

int main(){  
    int number=50;      
    int *p;//pointer to int    
    int **p2;//pointer to pointer        
    p=&number;//stores the address of number variable      
    p2=&p;    

    printf("Address of number variable is %x \n\n",&number);      
    printf("Address of p variable is %x \n\n",p);      
    printf("Value of *p variable is %d \n\n",*p);      
    printf("Address of p2 variable is %x \n\n",p2);      
    printf("Value of **p2 variable is %d \n\n",*p);      
    return 0;  
}  