#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>
#include<sys/stat.h>
#include<sys/types.h>
int open_port(int comport){  
	char str[20];
	int fd = -1;
	if(comport > 0){  
		sprintf(str,"dev/ttyS%d",comport - 1);
		fd = open(str,O_RDWR | O_NOCTTY | O_NDELAY);
		if( -1 ==fd){  
			perror("can't open serial port");
			return -1;
		}
	}
	else
			printf("chuankouhaomust dayu 0!\n");
	return fd;
}
int set_opt( int fd){  
	struct termios options;
	if(tcgetattr(fd,&options)!=0){  
		perror("get com set error");
		return -1;
	}
	cfsetispeed(&options,B9600);
	cfsetispeed(&options,B9600);
	options.c_cflag |= (CLOCAL | CREAD);
	options.c_cflag &= ~PARENB;
	options.c_cflag &= ~CSTOPB;
	options.c_cflag &= ~CSIZE;
	options.c_cflag |= CS8;
	if(tcsetattr(fd,TCSANOW,&options) != 0){  
		perror("com set error");
		return -1;
	}
	return 0;
}

int main( int argc,char** argv){  
	#define BUF_LEN 512
		char buff[BUF_LEN]="";
		int fd,comm_num,nread,run =1;
		if(argc < 2){ 
			printf("chengxustartmust withcom !\n");
			return -1;
		}
		comm_num = atoi(argv[1]);
		if(fd = open_port(comm_num)<0)
				return -1;
		if(set_opt(fd)<0)
				return -1;
		printf("open com%d ok!\n",comm_num );
		while(run){  
			while((nread = read(fd,buff,BUF_LEN))>0){  
				printf("nread =%d,%s\n",nread,buff);
				write(fd,buff,strlen(buff));
				if(strcmp(buff,"exit")==0)
						run = 0;
				memset(buff,0,BUF_LEN);
			}
		}
		close(fd);
		return 0;

}
