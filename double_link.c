#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct st
{
	struct st*pre;
	int roll;
	char s[20];
	struct st*next;
}st;
void add_begin(st**);
void add_end(st**);
void add_middle(st**);
void rev_print(st*);
void rev_data(st**);
void rev_node(st**);
void delete_node(st**,int);
void delete_all_node(st**);
void print(st*);
int count(st*);
int main()
{
	st*hptr=0;
	int num;
	char op;
	do
	{
		//add_begin(&hptr);
		add_end(&hptr);
		//add_middle(&hptr);
		printf("Enter the details again enter y or n\n");
		scanf(" %c",&op);
	}while(op=='y');
	print(hptr);
	printf("After reverse\n");
	rev_print(hptr);
	rev_data(&hptr);
	print(hptr);
	rev_node(&hptr);
	print(hptr);
	printf("Enter the rollnumber to delete\n");
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
	temp->pre=0;
	temp->next=*ptr;
	if(*ptr!=0)
		(*ptr)->pre=temp;
	*ptr=temp;
}
void add_end(st**ptr)
{
	st*temp=(st*)malloc(sizeof(st));
	printf("Enter the details\n");
	scanf("%d%s",&temp->roll,temp->s);
	if(*ptr==0)
	{
		temp->pre=0;
		temp->next=*ptr;
		*ptr=temp;
	}
	else
	{
		st*last=*ptr;
		while(last->next!=0)
			last=last->next;
		temp->pre=last;
		temp->next=last->next;
		last->next=temp;
	}
}
void add_middle(st**ptr)
{
	st*temp=(st*)malloc(sizeof(st));
	printf("Enter the details\n");
	scanf("%d%s",&temp->roll,temp->s);
	if((*ptr==0)||(temp->roll<(*ptr)->roll))
	{
		temp->pre=*ptr;
		if(temp->pre!=0)
		{
			temp->pre=(*ptr)->pre;
			(*ptr)->pre=temp;
		}
		temp->next=*ptr;
		*ptr=temp;
	}
	else
	{
		st*last=*ptr;
		while((last->next!=0)&&(temp->roll>last->next->roll))
			last=last->next;
		temp->pre=last;
		temp->next=last->next;
		last->next=temp;
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
	int c=count(*ptr),size=sizeof(st)-16;
	st temp;
	st *p1,*p2;
	p1=*ptr;
	p2=*ptr;
	while(p2->next!=0)
	{
		p2=p2->next;
	}
	for(int i=0;i<c/2;i++)
	{
		memcpy(&temp.roll,&p1->roll,size);
		memcpy(&p1->roll,&p2->roll,size);
		memcpy(&p2->roll,&temp.roll,size);
		p1=p1->next;
		p2=p2->pre;
	}
	printf("After reveres tha data\n");
}
void rev_node(st**ptr)
{
	int c=count(*ptr);
	st *temp;
	for(int i=0;i<c;i++)
	{
		temp=(*ptr)->pre;
		(*ptr)->pre=(*ptr)->next;
		(*ptr)->next=temp;
		*ptr=(*ptr)->pre;
	}
	*ptr=temp->pre;
	printf("After reverse the details\n");
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
				temp->next->pre=(*ptr)->pre;
				*ptr=temp->next;
			}
			else
			{
				if(temp->next==0)
				{
					prev->next=temp->next;
					free(temp);
					temp=NULL;
					return;
				}
				else
				{
				temp->next->pre=prev;
				prev->next=temp->next;
				}
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
	printf("Enter the valid roll number\n");
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
void print(st*ptr)
{
	if(ptr==0)
	{
		printf("No details present\n");
		return;
	}
	while(ptr!=0)
	{
		printf("%d %s\n",ptr->roll,ptr->s);
		ptr=ptr->next;
	}
}
