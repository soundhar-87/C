#include<stdio.h>
int main()
{
	int s1[3][3],s2[3][3],s3[3][3],i,j,sum,g,k;
	printf("Enter the first matrix\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			scanf("%d",&s1[i][j]);
	}
	printf("Enter the second matrix\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			scanf("%d",&s2[i][j]);
	}
	int r=sizeof s1/sizeof s1[0];
	int c=sizeof s1[0]/sizeof s1[0][0];
	printf("Multiplication of two matrix is \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			sum=0;
			for(k=0,g=0;k<r;k++,g++)
			{
	                 sum=sum+s1[i][k]*s2[g][j];
			 s3[i][j]=sum;
			 }
			printf("%d ",s3[i][j]);
		}
		printf("\n");
	}
}


