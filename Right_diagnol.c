#include<stdio.h>
int main()
{
        int n1,n2;
        printf("Enter the element in row ");
        scanf("%d",&n1);
        printf("Enter the element in column ");
        scanf("%d",&n2);
        int a[n1][n2],i,j;
        printf("enter the array \n");
        for(i=0;i<n1;i++)
        {
                for(j=0;j<n2;j++)
                        scanf("%d",&a[i][j]);
        }
        int r=sizeof a/sizeof a[0];
        int c=sizeof a[0]/sizeof a[0][0];
	int sum1=0;
	int sum2=0;
	int sum3=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if((i==0)&&(j==0))
		         	sum1=sum1+a[i][j];
		        if((i==r-1)&&(j==c-1))
				sum2=sum2+a[i][j];
		}
	}
	printf("%d\n",sum1+sum2);
}

