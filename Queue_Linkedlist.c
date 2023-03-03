#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
	
};struct node *head;

void enqueue();
void dequeue();
void display();
void main()
{
	printf("\n***** Operations *****\n");
	printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
	int choice=0;
	while(choice!=4)
	{
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:enqueue();break;
			case 2:dequeue();break;
			case 3:display();break;
			case 4:exit(0);
			default:printf("\nYou entered wrong key");
		}
	}
}
void enqueue()
{
	struct node *ptr,*temp;
	int item;
	ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	printf("\nOverflow");
	else
	{
		printf("\nEnter the item:");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL)
		{
			ptr->next=NULL;
			head=ptr;
			printf("\nNode is enqueued");
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->next=NULL;
			printf("\nNode is enqueued");
		}
	}
}
void dequeue()
{
	struct node *temp;
	if(head==NULL)
	printf("\nUnderflow");
	else
	{
		temp=head;
		head=temp->next;
		free(temp);
		printf("\nNode is dequeued");
	}
}
void display()
{
	struct node *temp;
	if(head==NULL)
	printf("\nUnderflow");
	else
	{
		printf("\nQueue of linked list follows as:\n");
		temp=head;
		while(temp!=NULL)
		{
			printf("-->%d",temp->data);
			temp=temp->next;
		}
	}
}
