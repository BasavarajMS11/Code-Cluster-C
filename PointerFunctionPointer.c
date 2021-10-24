#include<stdio.h> 

int product(int x,int y){    
    return x*y;  
} 
 
int main (){  
    int result;   
    int (*ptr)(int,int);  
    ptr = &product;  

    int a, b;   
    printf("Enter two numbers: ");  
    scanf("%d %d",&a,&b);  
    result = (*ptr)(a,b);  
    printf("The sum is %d",result);  
}  
