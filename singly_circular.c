#include<stdio.h>
#include<stdlib.h>
#define NODEALLOC (struct node*)malloc(sizeof(struct node))
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE * create(NODE *list)
{
	int i,n;
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
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
			newnode->next=list;
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
NODE * insertbeg(NODE *list,int num)
{
	NODE *newnode,*temp;
	newnode=NODEALLOC;
	newnode->data=num;
	newnode->next=list;
	for(temp=list;temp->next!=list;temp=temp->next);
	temp->next=newnode;
	list=newnode;
	return list;
}
NODE * insertmid(NODE *list,int num,int pos)
{
	NODE *newnode,*temp;
	newnode=NODEALLOC;
	newnode->data=num;
	int i;
	for(i=1,temp=list;i<(pos-1)&&temp->next!=NULL;i++,temp=temp->next);
	newnode->next=temp->next;
	temp->next=newnode;
	return list;
}
int main()
{
	NODE *list=NULL;
	int ch,num,pos;
	do
	{
		printf("\n1-create \n2-disp \n3-insertbeg \n4-insertmid");
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
					list=insertbeg(list,num);
					break;
			case 4:printf("Enter number: ");
					scanf("%d",&num);
					printf("Enter pos: ");
					scanf("%d",&pos);
					list=insertmid(list,num,pos);
					break;
			default:printf("Invalid choice...");
		}
	}while(ch<5);
}

