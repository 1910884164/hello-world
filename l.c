#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>   
#include <unistd.h>

unsigned int value1, value2, count;
pthread_mutex_t  mutex1,mutex2;
void *function(void *arg);


void  *function(void *arg)
{
 pthread_mutex_lock(&mutex2);
 printf("new thread get mutex2\n"); 
 sleep(1);
 pthread_mutex_lock(&mutex1); 
 printf("new thread get mutex1\n"); 
 
 
 pthread_mutex_unlock(&mutex1);
 printf("new thread release mutex1\n");
 pthread_mutex_unlock(&mutex2); 
 printf("new thread release mutex2\n");
    return  NULL;
 }  

int main(int argc,  char *argv[])
{
 pthread_t  a_thread;
         
 if (pthread_mutex_init(&mutex1, NULL) < 0)
 {
  perror("fail to mutex_init");
  exit(-1);
 }
  if (pthread_mutex_init(&mutex2, NULL) < 0)
 {
  perror("fail to mutex_init");
  exit(-1);
 }              
 if (pthread_create(&a_thread, NULL, function, NULL) < 0)
 {   
  perror("fail to pthread_create");     
  exit(-1);
 }
    while ( 1 )
    {
        pthread_mutex_lock(&mutex1);
  printf("main thread get mutex1\n");
  sleep(1);
        pthread_mutex_lock(&mutex2);  
  printf("main thread get mutex2\n");
        pthread_mutex_unlock(&mutex2);
  printf("main thread release mutex2\n");
        pthread_mutex_unlock(&mutex1);
  printf("main thread release mutex1\n");
    }
    return 0;
 }             
