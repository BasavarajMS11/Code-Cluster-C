/*
const int *p        -> Pointer to cnstant integer
int * const p       -> Constant pointer to non constant integer
const int * const p -> Constant pointer to constant integer
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a =10, b =20;
	
	//1. const int *p : Pointer can be changed but value pointed by pointer cannot be
    printf("\n1. const int *p : Pointer can be changed but value pointed by pointer cannot be\n");
    const int *ptr = &a;
	printf( "value pointed by ptr: %d\n", *ptr);
    printf( "Address ptr is pointing to: %d\n\n", ptr);
	ptr = &b;
    //*ptr = b; //illegal 
	printf( "value pointed by ptr: %d\n", *ptr);
    printf( "Address ptr is pointing to: %d\n", ptr);


    //2. int * const p : Pointer cannot be changed but value pointed by pointer can be
    printf("\n2. int * const p : Pointer cannot be changed but value pointed by pointer can be\n");
    int *const ptr1 = &a;
    printf( "Value pointed by ptr1: %d\n", *ptr1);
    printf( "Address ptr1 is pointing to: %d\n\n", ptr1);
 
    //ptr = &b; //illegal
 
    // changing the value
    *ptr1 = b;
    printf( "Value pointed by ptr1: %d\n", *ptr1);
    printf( "Address ptr1 is pointing to: %d\n", ptr1);

    //3. const int * const p : Neither pointer nor value pointed by pointer can be changed
    a =10, b =20;
    printf("\n3. const int * const p : Neither pointer nor value pointed by pointer can be changed\n");
    const int *const ptr2 = &a;
     
    printf( "Value pointed by ptr2: %d\n", *ptr2);
    printf( "Address ptr2 is pointing to: %d\n\n", ptr2);
 
    // ptr = &b; //illegal statement
    //*ptr = b; //illegal statement
    
    return 0;

}
