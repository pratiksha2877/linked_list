#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{
	int data;
	struct node *next;
}NODE;
NODE * create(NODE *list)
{
	NODE *newnode,*temp;
	int n,i;
	printf("Enter limit : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(NODE *)malloc(sizeof(NODE));
		printf("Enter value:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(list==NULL)	// first time list null asel tr
		{
			list=newnode;
			temp=newnode;
		}
		else	//list null nsel tr
		{
			temp->next=newnode;
			temp=newnode;
		}
	}
	return list;
}
void display(NODE *list)
{
	NODE *temp;
	for(temp=list; temp!=NULL; temp=temp->next)
	{
		printf("%d\t",temp->data);
	}
}
NODE * insert(NODE *list,int num,int pos)
{
	NODE *newnode,*temp;
	int i;
	newnode=(NODE *)malloc(sizeof(NODE));
	newnode->data=num;
	if(pos==1)
	{
		newnode->next=list;
		list=newnode;
	}
	else
	{
		for(i=1,temp=list; i<(pos-1)&&temp->next!=NULL; i++,temp=temp->next);
		newnode->next=temp->next;
		temp->next=newnode;
	}
	return list;
}
NODE * delete_node(NODE *list,int pos)
{
	NODE *temp,*temp1;
	int i;
	if(pos==1)
	{
		temp=list;
		list=list->next;
		free(temp);
	}
	else
	{
		for(i=1,temp=list; i<(pos-1)&&temp->next->next!=NULL; i++,temp=temp->next);
		temp1=temp->next;
		temp->next=temp1->next;
	}
	return list;
}
NODE * search(NODE *list, int num)
{
	NODE *temp;
	int flag=0;
	for(temp=list;temp!=NULL;temp=temp->next)
	{
		if(temp->data==num)
		return temp;	
	}
	return temp;
}
