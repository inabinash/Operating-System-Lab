#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

#include<unistd.h>
#include <pthread.h>
#include <sys/wait.h>

int c =-1;
int main()
{       int a= 5, b= 3;
	
        int p_id= fork();
	if(p_id==0)
	{
               
		printf("I am a child process\n");
		printf("Addition Done\n");
		c= a+b;
	}
	else {
                waitpid(p_id , 0 , 0);
	       	printf("I am a parent process\n");
		printf("Value of c : %d\n", c);
	}


	

	return 0 ;
}






