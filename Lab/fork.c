#include<unistd.h>
#include<stdio.h>

int main()
{

int cnt=0;
pid_t pid=fork();

if(pid==0)
{
for(int i=0;i<5;i++)
{
printf("Child Process %d\n",cnt++);
}
}

else if(pid>0)
{
for(int i=0;i<5;i++)
{
printf("Parent Process %d\n",cnt++);
}
}

else
{
printf("Failed\n");
return 1;
}

return 0;
}
