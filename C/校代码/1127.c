#include<stdio.h>
int main()
{
	__int64 a,b,c;
	while(scanf("%X%X",&a,&b)!=EOF)
	{
		c=a+b;
		if(c<0)c=-c,printf("-%X\n",c);
		else printf("%X\n",c);
	}
	return 0;
} 