//	INVERTENDO A LISTA DE MODO ITERATIVO
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * link;
};



struct node * Insert (struct node * head, int data)
{
	struct node * temp = (struct node *) malloc(sizeof(struct node *));
	temp->data = data;
	temp-> link = NULL;

	if (head == NULL)
		{
			head = temp;
		}	

	else
	{
		struct node * temp1 = head;
		while(temp1->link != NULL)
		{
			temp1 = temp1->link;
		}
			temp1->link = temp;
	}
	return head;
}

void Print(struct node * head)
{
	while(head != NULL)
	{
		printf("%d ",head->data);
		head = head->link;
	}
	printf("\n");
}

struct node * Reverse(struct node * head)
{
	struct node * link, *prev, *current;
	current = head;
	prev = NULL;

	while(current != NULL)
	{
		link = current->link;
		current->link = prev;
		prev = current;
		current = link;
	}

	head = prev;

	return head;
}
int main(int argc, char const *argv[])
{
	struct node * head = NULL;
	
	head = Insert (head, 2);
	head = Insert (head, 4);
	head = Insert (head, 6);
	head = Insert (head, 8);

	Print(head);

	head = Reverse(head);
	Print(head);

	return 0;
}