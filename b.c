#include<stdio.h>
int main(  )
{  

	int a,b,c,d;
	
	a = 0; 
	b = 1; 
	c = 2;
	d = a++ && b++ && --c;
	
	printf("a=%d b=%d c=%d d=%d\n",a,b,c,d);


}
