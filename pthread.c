#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>

char message[32]="hello world";
void *thread_func(void *arg);

int main( )
{  
	pthread_t a_thread;
	void *result;
	if(pthread_create(&a_thread,NULL,thread_func,NULL)!=0){  
		printf( "fail to pthread_create ");
		exit(-1);
	}
	printf("start\n");
	pthread_join(a_thread,&result);
	printf("result is %s\n ",result);
	printf("message is %s\n ",message);
	return 0;
}
void *thread_func(void *arg)
{  
	sleep(1);
	strcpy(message,"marked by thread");
	pthread_exit("thank you for waiting for me "  );

}
