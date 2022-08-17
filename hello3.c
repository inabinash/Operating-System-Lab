#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

#include<unistd.h>


int main()
{
        int p_id= fork();
	if(p_id==0)
		printf("I am a child process\n");
	else printf("I am a parent process\n");

	printf("Current process ID is %d \n" , getpid());
	printf("Parent process ID is %d \n " , getppid());

        printf("Value of p_id is : %d\n" , p_id);

	return 0 ;
}



