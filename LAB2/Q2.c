#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main() {
 pid_t p = fork();
 if(p==-1){
 perror("fork");
 exit(1);
 }
 printf("%d\n",p);
 if(p==0) printf("I am a child\n");
 if(p>0) printf("I am Parent\n");
 return 0;
}