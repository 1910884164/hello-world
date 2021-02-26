#include<stdio.h>
void fun(char *p ,int n)
{  
	char b[6]="abcde";
	int i;
	for(i=0,p=b;i<n;i++)
		p[i]=b[i];
}
int main()
{  
	char a[6]="ABCDE";
	fun( a,5);
	printf("%s\n",b);
}
