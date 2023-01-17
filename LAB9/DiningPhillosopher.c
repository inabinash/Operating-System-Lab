#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define NUM_PHILOSOPHERS 5
#define NUM_CHOPSTICKS 5


pthread_t philosopher[NUM_PHILOSOPHERS];
pthread_mutex_t chopstick[NUM_CHOPSTICKS];

int time =0;
void dine(int n)
{
  printf("\nPhilosopher % d is thinking ", n);
  if(n%2){
      pthread_mutex_lock(&chopstick[n]);
      pthread_mutex_lock(&chopstick[(n + 1) % NUM_CHOPSTICKS]);
      printf("\nPhilosopher % d is eating ", n);
      printf("At time at %d\n", time++);
      sleep(2);
      
      pthread_mutex_unlock(&chopstick[n]);
      pthread_mutex_unlock(&chopstick[(n + 1) % NUM_CHOPSTICKS]);
      printf("\nPhilosopher % d Finished eating ", n);
  }
  else{
    pthread_mutex_lock(&chopstick[(n + 1) % NUM_CHOPSTICKS]);
    pthread_mutex_lock(&chopstick[n]);
    printf("\nPhilosopher % d is eating ", n);
    printf("At time at %d\n", time++);
    sleep(2);
    pthread_mutex_unlock(&chopstick[n]);
    pthread_mutex_unlock(&chopstick[(n + 1) % NUM_CHOPSTICKS]);
    printf("\nPhilosopher % d Finished eating ", n);
  }
  
} 

int main()
{
  
  for (int i = 1; i <= NUM_CHOPSTICKS; i++)
  {
    pthread_mutex_init(&chopstick[i], NULL);
  }
  for (int i = 1; i <= NUM_PHILOSOPHERS; i++)
  {
    pthread_create(&philosopher[i], NULL, (void *)dine, (int *)i);
  }

  
  for (int i = 1; i <= NUM_PHILOSOPHERS; i++)
  {
    pthread_join(philosopher[i], NULL);
  }
  return 0;
}
