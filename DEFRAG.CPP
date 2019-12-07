#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 10


struct node
{
	int data;
	struct node *next;
};
void Create(struct node **start,struct node **end);
void Insert(struct node **start,struct node **end,int no);
void Display(struct node *start,struct node *end);
void Delete(struct node **start,struct node **end,int pos);
void Defragment(struct node **start,struct node **end);
int count=1;
int ct=0;
struct node *ptr=NULL;
int main()
{
	struct node *first=NULL;
	struct node *last=NULL;
	int ch,n,pos;
	Create(&first,&last);
	ptr=first;
       //	int ch,n,pos;
	while(1)
	{
		printf("\n 1.enter data ");
		printf("\n 2.delete data");
		printf("\n 3.exit");
		printf("\n 4.frgment");
		printf("\n 5.dispaly");
		printf("\n enter ur choice");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:if(ct>=MAX)
				{
					printf("\n buffer is full");
				}
				else
				{
				ct++;
				printf("\n enter the data");
				scanf("%d",&n);
				Insert(&first,&last,n);
				}
			       break;

			case 2:printf("\n which position u want to delete");
			       scanf("%d",&pos);
			       Delete(&first,&last,pos);
			       break;
			case 3:exit(1);
				break;

			case 4:Defragment(&first,&last);
				break;
			case 5:Display(first,last);
				break;
			default:printf("\n wrong choice");
		}
	}
	return 0;
}
void Create(struct node**start,struct node **end)
{
	struct node *newnode=NULL;
	while(count<=MAX)
	{
		newnode=(struct node *) malloc (sizeof(struct node));
		if(newnode==NULL)
		{
			printf("Memory not allocted");
			return;
		}
		newnode->data=-1;
		if(*start==NULL)
		{
			*start=newnode;
			*end=newnode;
			(*end)->next=*start;
		}
		else
		{
			(*end)->next=newnode;
			*end=newnode;
			(*end)->next=*start;
		}
		count++;
	}
}
void Insert(struct node **start,struct node **end,int no)
{
	while((ptr->data)!=-1)
	{
		ptr=ptr->next;
	}
	ptr->data=no;
}
void Delete(struct node **start,struct node **end,int pos)
{
	struct node *temp=(*start);
	int cnt=1;
	if((pos<=10) && (pos>=1))
	{
		while(pos>cnt)
		{
			temp=temp->next;
			cnt++;
		}
		if(temp->data==-1)
		{
			printf("no data");
			return;
		}
		temp->data=-1;
		ct--;
	}
	else
		printf("invalid position");
}
void Display(struct node *start,struct node *end)
{
	if(start==NULL)
	{
		printf("\n list is empty");
		return;
	}
	do
	{
		printf("\t %d",start->data);
		start=start->next;
	}while(start!=(end->next));
}
/*void Defragment(struct node **start,struct node **end)
{
	struct node *a=*start;
	struct node *b=NULL;
	struct node *c=NULL;
	while(a->data==-1)
	{
		a=a->next;
	}
	b=a->next;
	c=a->next;
	while(b->data==-1)
	{
		b=b->next;
	}
	a->next=b;
	b->next=(*start);
	(*start)->next=c;
	c->next=a;
	(*start)=a;
	(*end)=c;
}*/

void Defragment(struct node **start,struct node **end)
{
	int flag=0;
	struct node *a=*start;
	struct node *b=NULL;
	struct node *c=NULL,*newnode=NULL;
	int cn=0;
	do
	{

	while(a->data==-1)
	{
		if(a->next == *start)
		{
		flag=1;
		break;
		}
		a=a->next;
		cn++;
	}
	if(flag==1)
		break;
	b=a->next;
	c=a->next;
	while(b->data==-1)
	{
		if(b->next == *start)
		{
			flag=1;
			break;
		}
		b=b->next;
		cn++;
	}
	if(flag==1)
		break;
	a->next=b;
	a=a->next;
//	cn++;
	}while(1);
//	printf("\n count =%d",cn);
	/*
	b->next=(*start);
	(*start)->next=c;
	c->next=a;
	(*start)=a;
	(*end)=c;*/
	a=(*start)->next;
	cn=0;
	while(a!=(*end)->next)
		{
		cn++;
		a=a->next;
		}
//	printf("\n Count =%d",cn++);
	//struct node *newnode=NULL;
	while(cn<MAX)
	{
		newnode=(struct node *) malloc (sizeof(struct node));
		if(newnode==NULL)
		{
			printf("Memory not allocted");
			return;
		}
		newnode->data=-1;
		if(*start==NULL)
		{
			*start=newnode;
			*end=newnode;
			(*end)->next=*start;
		}
		else
		{
			(*end)->next=newnode;
			*end=newnode;
			(*end)->next=*start;
		}
		cn++;
	}
}

