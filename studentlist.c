#include<stdio.h>
#include<string.h>
struct st 
{
	int roll;
	char ch[100];
	float marks;
};
void scan(struct st *,int);
void arrengement(struct st*,int);
int main()
{
	int num;
	struct st v[100];
	printf("Enter how many stundent details ");
        scanf("%d",&num);	
	scan(v,num);
	arrengement(v,num);
}
void scan(struct st* p,int num)
{
	int i;
	for(i=0;i<num;i++)
		scanf("%d %s %f",&p[i].roll,p[i].ch,&p[i].marks);
}
void arrengement(struct st* a,int num)
{
	char cm;
	printf("Enter the arrengement like roll number--->r,name--->n,marks--->m ");
	scanf(" %c",&cm);
	int i,j,temp;
	char c[100];
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(cm=='r')
			{
				if(a[i].roll>a[j].roll)
				{
					temp=a[i].roll;
					a[i].roll=a[j].roll;
					a[j].roll=temp;
					strcpy(c,a[i].ch);
					strcpy(a[i].ch,a[j].ch);
					strcpy(a[j].ch,c);
					temp=a[i].marks;
					a[i].marks=a[j].marks;
					a[j].marks=temp;
				}
			}
			else if (cm=='m')
			{
				if(a[i].marks<a[j].marks)
				{
					temp=a[i].marks;
					a[i].marks=a[j].marks;
					a[j].marks=temp;
					strcpy(c,a[i].ch);
					strcpy(a[i].ch,a[j].ch);
					strcpy(a[j].ch,c);
					temp=a[i].roll;
					a[i].roll=a[j].roll;
					a[j].roll=temp;
				}
			}
			else if(cm=='n')
			{
				if(strcmp(a[i].ch,a[j].ch)>0)
				{
					strcpy(c,a[i].ch);
					strcpy(a[i].ch,a[j].ch);
					strcpy(a[j].ch,c);
					temp=a[i].marks;
					a[i].marks=a[j].marks;
					a[j].marks=temp;
					temp=a[i].roll;
					a[i].roll=a[j].roll;
					a[j].roll=temp;
				}
			}
			else
				printf("enter the invalid\n");
		}
	}
			printf("After the arrengement\n");
			for(i=0;i<num;i++)
				printf("%d %s %g\n",a[i].roll,a[i].ch,a[i].marks);
}

