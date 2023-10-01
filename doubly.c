#include"doubly.h"
int main()
{
	int ch,num;
	NODE *list=NULL;
	do
	{
		printf("\n1-create \n2-disp \n3-insertbeg \n4-insertend");
		printf("\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:list=create(list);
					break;
			case 2:disp(list);
					break;
			case 3:printf("Enter num : ");
					scanf("%d",&num);
					list=insertbeg(list,num);
					break;
			case 4:printf("Enter num : ");
					scanf("%d",&num);
					list=insertend(list,num);
					break;
			default:printf("Case not match");
		}
	}while(ch<4);
}
