#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct st
{
	int roll;
	char s[20];
	struct st*next;
}st;
void add_begin(st**);
void add_end(st**);
void rev_print(st*);
void rev_data(st**);
void rev_link(st**);
void add_middle(st**);
void delete_node(st**,int);
void delete_all_node(st**);
void print(st*);
int count(st*);
int main()
{
	int num;
	st*hptr=0;
	char op;
	do
	{
		//add_begin(&hptr);
		//add_end(&hptr);
		add_middle(&hptr);
		printf("enter the details again enter y or n\n");
	       scanf(" %c",&op);
	}while(op=='y');
	print(hptr);
	printf("reverse print details\n");
	rev_print(hptr);
	rev_link(&hptr);
	print(hptr);
	rev_data(&hptr);
	print(hptr);
	printf("enter the roll number to delete\n");
	scanf("%d",&num);
	delete_node(&hptr,num);
	print(hptr);
	delete_all_node(&hptr);
	print(hptr);
}
void add_begin(st**ptr)
{
	st*temp=(st*)malloc(sizeof(st));
	printf("Enter the details\n");
	scanf("%d%s",&temp->roll,temp->s);
	temp->next=*ptr;
	*ptr=temp;
}
void add_end(st**ptr)
{
	st*temp=(st*)malloc(sizeof(st));
	printf("Enter the details\n");
	scanf("%d%s",&temp->roll,temp->s);
	if(*ptr==0)
	{
		temp->next=*ptr;
		*ptr=temp;
	}
	else
	{
		st*last=*ptr;
		while(last->next!=0)
			last=last->next;
		temp->next=last->next;
		last->next=temp;
	}
}
void print(st*ptr)
{
	if(ptr==0)
	{
		printf("details are not found\n");
	        return;
	}	
	while(ptr!=0)
	{
		printf("%d %s\n",ptr->roll,ptr->s);
		ptr=ptr->next;
	}
}
void rev_print(st*ptr)
{
	if(ptr!=0)
	{
		rev_print(ptr->next);
		printf("%d %s\n",ptr->roll,ptr->s);
	}
}
void rev_link(st**ptr)
{
	int i,c=count(*ptr);
	st*temp=*ptr;
	st**p=(st**)malloc(c*sizeof(st*));
	for(i=0;i<c;i++)
	{
		p[i]=temp;
		temp=temp->next;
	}
	p[0]->next=0;
	for(i=1;i<c;i++)
		p[i]->next=p[i-1];
	*ptr=p[c-1];
	
	printf("After reverse link the details\n");
}
int count(st*ptr)
{
	int c=0;
	while(ptr!=0)
	{
		++c;
		ptr=ptr->next;
	}
	return c;
}
void rev_data(st**ptr)
{
	st*temp=*ptr;
	int i,j,c=count(*ptr);
	int size=sizeof(st)-8;
	st temp1;
	st**p=(st**)malloc(c*sizeof(st*));
	for(i=0;i<c;i++)
	{
		p[i]=temp;
		temp=temp->next;
	}
	for(i=0,j=c-1;i<j;i++,j--)
	{
		memcpy(&temp1,p[i],size);
		memcpy(p[i],p[j],size);
		memcpy(p[j],&temp1,size);
	}
	printf("After reversing the data\n");
}
void add_middle(st**ptr)
{
	st*temp=(st*)malloc(sizeof(st));
	printf("Enter the details\n");
	scanf("%d%s",&temp->roll,temp->s);
	if((*ptr==0)||(temp->roll<(*ptr)->roll))
	{
		temp->next=*ptr;
		*ptr=temp;
	}
	else
	{
		st*last=*ptr;
		while((last->next!=0)&&(last->next->roll<temp->roll))
			last=last->next;
		temp->next=last->next;
		last->next=temp;
	}
}
void delete_node(st**ptr,int n)
{
	st*prev,*temp=*ptr;
	while(temp!=0)
	{
		if(temp->roll==n)
		{
			if(temp==*ptr)
			{
				*ptr=temp->next;
			}
			else
			{
				prev->next=temp->next;
			}
			free(temp);
			temp=NULL;
			return;
		}
		else
		{
			prev=temp;
			temp=temp->next;
		}
	}
	printf("enter the valid roll number\n");
}
void delete_all_node(st**ptr)
{
	st*temp;
	while(*ptr!=0)
	{
		temp=*ptr;
		*ptr=(*ptr)->next;
		free(temp);
	}
}	
		
