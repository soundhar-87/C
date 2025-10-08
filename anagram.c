#include<stdio.h>
#include<string.h>
char* remove_splchr(char*);
int length(char *,char *);
char* lower_case(char*);
int sort_str(char*,char*);
int main()
{
	char s1[100],s2[100];
	printf("Enter the first string ");
	scanf("%[^\n]",s1);
	printf("Enter the second  string ");
	scanf(" %[^\n]",s2);
	remove_splchr(s1);
	remove_splchr(s2);
	int len=length(s1,s2);
	if(len==1)
	{
		lower_case(s1);
		lower_case(s2);
		int cm=sort_str(s1,s2);
		if(cm==1)
			printf("The given two words are anagarm\n");
		else
			printf("The given two words are not anagarm......\n");
	}
	else
		printf("The give two words are not anagram\n");
}
char* remove_splchr(char*p)
{
	int i,j;
	for(int i=0;p[i];i++)
	{
	if(!((p[i]>='a'&&p[i]<='z')||(p[i]>='A'&&p[i]<='Z')))
		{
                        for(int j=i;p[j];j++)
			{
				p[j]=p[j+1];
			}
			i--;
		}
	}
}
int length(char *p,char *q)
{
	if(strlen(p)==strlen(q))
		return 1;
	else
		return 0;

}
char* lower_case(char*p)
{
	int i,j;
	for(i=0;p[i];i++)
	{
		if(p[i]>='A'&&p[i]<='Z')
			p[i]=p[i]+32;
		else
			continue;
	}
	return p;
}
int sort_str(char *p,char *q)
{
	int i,j,temp;
	for(i=0;p[i];i++)
	{
		for(j=i+1;p[j];j++)
		{
		if(p[i]>p[j])
		{
			temp=p[j];
			p[j]=p[i];
			p[i]=temp;
		}
		}
	}
		//printf("%s\n",p);
	for(i=0;q[i];i++)
	{
		for(j=i+1;q[j];j++)
		{
		if(q[i]>q[j])
		{
			temp=q[j];
			q[j]=q[i];
			q[i]=temp;
		}
		}
	}
		//printf("%s\n",q);
	if((strcmp(p,q))==0)
		return 1;
        else
                return 0;
}
	else
		return 0;
}

