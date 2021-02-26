#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

char buf[32];
sem_t sem;
void *function(void *arg);
int main()
{ 
	pthread_t a_thread;
	if(sem_init(&sem,0,0)<0){  
	perror("sem_init");
	exit(-1);
	}
	if(pthread_create(&a_thread,NULL,function,NULL)!=0){  
	printf("fail to pthread_create");
	exit(-1);
	}
	do {  
	 fgets(buf,32,stdin);
	 sem_post(&sem);
	}while(strncmp(buf,"quit",4)!=0);
	return 0;
}
void *function(void *arg)
{  
	while(1)
		{  
			sem_wait(&sem);
		
			printf("you enter %ld characters\n",strlen(buf));
		}



}
