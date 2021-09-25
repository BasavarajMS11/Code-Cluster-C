#include<stdio.h>

void fun(int n){
    if(n>0)
    {
        fun(n-1);
        printf("%d ",n);
    }
}

int main(){
    int x=5;
    fun(x);
    return 0;
}
