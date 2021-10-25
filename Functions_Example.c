#include<stdio.h>

/*Function declaration*/
int product(int a,int b);
/*End of Function declaration*/

int main(){
    int x=2,y=3;
    int result=product(x,y);
    /*Function Call*/
    printf("Product : %d",result);
}

/*Function Definition*/
int product(int a,int b)		
{   //function body
	int c;
	c=a*b;
	return c;
}
/*End of Function declaration*/

