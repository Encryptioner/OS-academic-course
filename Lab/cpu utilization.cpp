#include<unistd.h>
#include<stdio.h>

int main(void)
{
    #pragma omp parallel
    {
        volatile unsigned x=0,y=1;
        while(x++ || y++);//{printf("hello\n");}
    }
    return 0;
}
