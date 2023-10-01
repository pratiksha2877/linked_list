#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next, *prev;
};
typedef struct node NODE;
NODE * create(NODE *list)
{
	NODE *temp,*newnode;
	int n,i;
	printf("Enter limit : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(NODE*)malloc(sizeof(NODE));
		printf("Enter value : ");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(list==NULL)
		{
			list=newnode;
			temp=newnode;	
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;		
		}	
	}
	return list;
}
void disp(NODE *list)
{
	NODE *temp;
	for(temp=list;temp!=NULL;temp=temp->next)
	{
		printf("%d\t",temp->data);
	}
}
NODE * insertbeg(NODE *list,int num)
{
	NODE *newnode;
	newnode=(NODE *)malloc(sizeof(NODE));
	newnode->data=num;
	newnode->next=list;
	list->prev=newnode;
	list=newnode;
	return list;
}
NODE * insertend(NODE *list ,int num)
{
	NODE *newnode,*temp;
	newnode=(NODE *)malloc(sizeof(NODE));
	newnode->data=num;
	newnode->next=NULL;
	for(temp=list;temp->next!=NULL;temp=temp->next);
	temp->next=newnode;
	newnode->prev=temp;
	return list;
}

