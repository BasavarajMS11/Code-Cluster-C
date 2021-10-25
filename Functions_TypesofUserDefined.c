#include<stdio.h>
//Type1  
void sum();  

//Type2
int sum2();

//Type3
void sum3(int a, int b);

//Type 4
int sum4(int, int); 


void main()  
{  
    int n1,n2,result;
    printf("\nSum of two numbers:");  
    sum(); //Type1


    result = sum2(); //Type2 
    printf("\nThe sum is %d",result);  

      
    printf("\nSum of two numbers:");  
    printf("\nEnter two numbers:");  
    scanf("%d %d",&n1,&n2);  
    sum3(n1,n2);  //Type3

    printf("\nCalculate the sum of two numbers:");  
    printf("\nEnter two numbers:");  
    scanf("%d %d",&n1,&n2);  
    result = sum4(n1,n2);  
    printf("\nThe sum is : %d",result);


} 

//Type1
void sum()  
{  
    int a,b;   
    printf("\nEnter two numbers");  
    scanf("%d %d",&a,&b);   
    printf("The sum is %d",a+b);  
} 

//Type 2
int sum2()  
{  
    int a,b;   
    printf("\nEnter two numbers");  
    scanf("%d %d",&a,&b);  
    return a+b;   
}  

//Type 3
void sum3(int a, int b)  
{  
    printf("\nThe sum is %d",a+b);      
}  

//Type 4
int sum4(int a, int b)  
{  
    return a+b;  
}  