#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node * create(struct node *list)
{
	int n,i;
	struct node *newnode,*temp;
	printf("Enter limit : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter number : ");
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
			temp=newnode;
		}	
	}
	return list;
}
struct node * disp(struct node *list)
{
	struct node *temp;
	for(temp=list;temp!=NULL;temp=temp->next)
	{
		printf("%d\t",temp->data);
	}
}
struct node * insertbeg(struct node *list,int num)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=list;
	list=newnode;
	return list;
}
struct node * insertend(struct node *list,int num)
{
	struct node *newnode,*temp;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=NULL;
	for(temp=list;temp->next!=NULL;temp=temp->next);
	temp->next=newnode;
	return list;
}
struct node * insertmid(struct node *list,int num,int pos)
{
	int i;
	struct node *temp,*newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	for(i=1,temp=list; i<(pos-1)&&temp->next!=NULL; i++,temp=temp->next);
	newnode->next=temp->next;
	temp->next=newnode;
	return list;	
}
struct node * delbeg(struct node *list)
{
	struct node *temp;
	temp=list;
	list=list->next;
	free(temp);
	return list;
}
struct node * delend(struct node *list)
{
	struct node *temp,*temp1;
	for(temp=list; temp->next->next!=NULL; temp=temp->next);
	temp1=temp->next;
	temp->next=NULL;
	free(temp1);
	return list;
}
struct node * delmid(struct node *list, int pos)
{
	struct node *temp,*temp1;
	int i;
	for(i=1,temp=list; i<(pos-1)&&temp->next!=NULL; i++,temp=temp->next);
	temp1=temp->next;
	temp->next=temp1->next;
	free(temp1);
	return(list);
}
int main()
{
	struct node *list=NULL;
	int ch,num,pos;
	do
	{
		printf("\n1-create \n2-disp \n3-insertbeg \n4-insertend");
		printf("\n5-insertmid \n6-delbeg \n7-delend \n8-delmid");
		printf("\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:list=create(list);
					break;
			case 2:disp(list);
					break;
			case 3:printf("Enter number : ");
					scanf("%d",&num);
					list=insertbeg(list,num);
					break;
			case 4:printf("Enter number : ");
					scanf("%d",&num);
					list=insertend(list,num);
					break;
			case 5:printf("Enter number : ");
					scanf("%d",&num);
					printf("Enter position : ");
					scanf("%d",&pos);
					list=insertmid(list,num,pos);
					break;
			case 6:list=delbeg(list);
					break;
			case 7:list=delend(list);
					break;
			case 8:printf("Enter position : ");
					scanf("%d",&pos);
					list=delmid(list,pos);
					break;
		}
	}while(ch<9);	
}
