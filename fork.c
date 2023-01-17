// C program to illustrate
// pipe system call in C
#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#define MSGSIZE 16
char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";

int main()
{
	char inbuf[10][MSGSIZE];
	int p[2], i;

	if (pipe(p) < 0)
		exit(1);

	/* continued */
	/* write pipe */
printf("%X" , msg1);
	write(p[1], msg1, MSGSIZE);
	//write(p[1], msg2, MSGSIZE);
	//write(p[1], msg3, MSGSIZE);
read(p[0], inbuf[0], MSGSIZE);
close(p[1]);
//printf("%s\n", inbuf);
read(p[0], inbuf[1], MSGSIZE);
//printf("%s\n", inbuf);

for(int i=0;i<2;i++) printf("%s\n" , inbuf[i]);

	
	return 0;
}
