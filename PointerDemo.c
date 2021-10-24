#include<stdio.h>

int main(){
    
   int* pc, c;
   
   c = 10;
   printf("Address of c: %p\n", &c);
   printf("Value of c: %d\n\n", c);  // 10
   
   pc = &c;
   printf("Address of pointer pc: %p\n", pc);
   printf("Content of pointer pc: %d\n\n", *pc); // 10
   
   c = 11;
   printf("Address of pointer pc: %p\n", pc);
   printf("Content of pointer pc: %d\n\n", *pc); // 11
   
   *pc = 20;
   printf("Address of c: %p\n", &c);
   printf("Value of c: %d\n\n", c); // 20
   return 0;
}