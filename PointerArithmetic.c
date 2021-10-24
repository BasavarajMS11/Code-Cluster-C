#include<stdio.h>  

int main(){  
    int number=50;        
    int *p;//pointer to int      
    p=&number;//stores the address of number variable   

    //Increment     
    printf("Address of p variable is %u \n",p);        
    p=p+1;        
    printf("After increment: Address of p variable is %u \n",p); //p get incremented by 4 bytes.

    //Decrement
    printf("Address of p variable is %u \n",p);        
    p=p-1;       
    printf("After decrement: Address of p variable is %u \n",p); //p point to the immidiate previous location

    //Addition
    printf("Address of p variable is %u \n",p);        
    p=p+3;   //adding 3 to pointer variable    
    printf("After adding 3: Address of p variable is %u \n",p);

    //Subtraction
    printf("Address of p variable is %u \n",p);        
    p=p-3; //subtracting 3 from pointer variable    
    printf("After subtracting 3: Address of p variable is %u \n",p);  

    //Pointer Subtraction
    int i = 100;   
    int *q = &i;  
    int *temp;  
    temp = q;   
    q = q + 3;  
    printf("Pointer Subtraction: %d - %d = %d",q, temp, q-temp); 


    return 0;  
}    