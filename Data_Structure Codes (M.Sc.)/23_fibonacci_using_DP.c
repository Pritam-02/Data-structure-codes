#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n,res,i;
	printf("\n Enter length:");
	scanf("%d",&n);
	res=fibo(n);
	printf("\nThe fibonacci series:");
		
		printf("%d",fibo(n));

	return 0;
}
int fibo(int n)
{
 int i;
 int *p=(int*) calloc(n+1,sizeof(int));
 p[0]=0;
 p[1]=1;
 for(i=2;i<=n;i++)
 {
 	p[i]=p[i-1]+p[i-2];
 	
 }
 return p[n];
}
