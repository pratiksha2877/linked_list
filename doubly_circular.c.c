#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next,*prev;
}NODE;
#define NODEALLOC (NODE *)malloc(sizeof(NODE))
NODE *create (NODE *list)
{
	int n,i;
	NODE *newnode,*temp;
	printf("Enter limit: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=NODEALLOC;
		printf("Enter value: ");
		scanf("%d",&newnode->data);
		if(list==NULL)
		{
			list=temp=newnode;
			newnode->next=list;
			list->prev=newnode;
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
			newnode->next=list;
			list->prev=newnode;
		}
	}
	return list;
}
void disp(NODE *list)
{
	NODE *temp=list;
	do
	{
		printf("\t%d",temp->data);
		temp=temp->next;
	}while(temp!=list);
}
NODE *insert(NODE *list,int num,int pos)
{
	int i;
	NODE *newnode,*temp;
	newnode=NODEALLOC;
	newnode->data=num;
	if(pos==1)
	{
		for(temp=list;temp->next!=list;temp=temp->next);
		newnode->next=list;
		list->prev=newnode;
		list=newnode;
		temp->next=list;
		list->prev=temp;
	}
	else
	{
		for(i=1,temp=list;i<(pos-1)&&temp->next!=list;i++,temp=temp->next);
		newnode->next=temp->next;
		temp->next->prev=newnode;
		temp->next=newnode;
		newnode->prev=temp;
	}
	return list;
}
NODE *del(NODE *list,int pos)
{
	NODE *temp,*temp1;
	int i;
	if(pos==1)
	{
		for(temp=list;temp->next!=list;temp=temp->next);
		temp1=list;
		list=list->next;
		temp->next=list;
		list->prev=temp;
		free(temp1);
	}
	else
	{
		for(i=1,temp=list;i<(pos-1)&&temp->next!=list;i++,temp=temp->next);
		temp1=temp->next;
		temp->next=temp1->next;
		temp1->next->prev=temp;
		free(temp1);
	}
	return list;
}
void cnt(NODE *list)
{
	int cnt=0;
	NODE *temp=list;
	do
	{
		cnt++;
		temp=temp->next;
	}while(temp!=list);
	printf("Total nodes=%d",cnt);
}
int main()
{
	int ch,num,pos;
	NODE *list=NULL;
	do
	{
		printf("\n1-create \n2-disp \n3-insert \n4-count_nodes \n5-large_node:");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:list=create(list);
					break;
			case 2:disp(list);
					break;
			case 3:printf("Enter number: ");
					scanf("%d",&num);
					printf("Enter position: ");
					scanf("%d",&pos);
					list=insert(list,num,pos);
					break;
			case 4:printf("Enter position: ");
					scanf("%d",&pos);
					list=del(list,pos);
					break;
			case 5:cnt(list);
					break;
		}
	}while(ch<6);
}
