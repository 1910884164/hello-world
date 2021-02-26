#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

unsigned int count,value1,value2;
pthread_mutex_t lock;
void *function(void *arg);

int main()
{  
	pthread_t a_thread;
	if( pthread_mutex_init(&lock,NULL)!=0){  
	printf("fail to pthread_mutex_init\n");
	exit(-1);
	}
	if(pthread_create(&a_thread,NULL,function,NULL)!=0){  
		printf("fail to pthread_create" );
		exit(-1);
	}
	while(1){  
		count ++;
		#ifdef _LOCK_
		pthread_mutex_lock(&lock);
		#endif
		value1=count;
		value2=count;
		#ifdef _LOCK
		pthread_mutex_unlock(&lock);
		#endif
	}
	return 0;
}

void *function(void *arg)
{  
	while(1){  
		#ifdef _LOCK_
			pthread_mutex_lock(&lock);
		#endif
			if(value1!=value2){  
				printf("value1=%u,value2=%u\n",value1,value2);
				usleep(100000);
			}
	#ifdef _LOCK_
			pthread_mutex_unlock(&lock);
	#endif
	}
	return NULL;

}
