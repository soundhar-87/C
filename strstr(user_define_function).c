#include<stdio.h>
char* my_strstr(char*,char*);
int main()
{
	char s[20],c[20];
	printf("Enter the string ");
	scanf("%s",s);
	printf("Enter the compare string ");
	scanf("%s",c);
	char*p=my_strstr(s,c);
	if(p==NULL)
		printf("not matched\n");
	else
		printf("%s",p);
}
char* my_strstr(char*p,char*q)
{
	int i,j;
	for(i=0;p[i];i++)
	{
		if(p[i]==q[0])
		{
			for(j=1;q[j];j++)
			{
				if(q[j]!=p[i+j])
					break;
			}
			if(q[j]=='\0')
				return p+i;
		}
	}
	return NULL;
}

