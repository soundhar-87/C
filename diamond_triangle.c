#include<stdio.h>
#include<math.h>
int main()
{
	int num,x,n,n1,l,i,j,s;
	printf("enter the number ");
	scanf("%d",&num);
	n=2;
	n1=1;
	for(i=-num;i<=num;i++)
	{
		if(i<0)
			l=-i;
		else
			l=i;
		for(s=0;s<l;s++)
			printf(" ");
		for(j=0;j<(num-l)+1;j++)
		{
			if(i==0)
			{
				printf("*   ");
			n1=1;
	        	}
			else if(i<0)
			{
				x=pow(n,n1);
				printf("%d   ",x);
				n1++;
			}
			else if(i>0)
 			{
				x=pow(n,n1);
				printf("%d   ",x);
				n1++;
			}
		}
		printf("\n");
	}
}
