
//INSERINDO NÓS EM QUALQUER LUGAR DA LISTA
#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node * link;
};

struct node * head;

void Print()
{
	struct node * temp = head;
	printf("A lista é:");
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->link;
	}
	printf("\n");
}

void Insert (int data, int n)
{
	struct node * temp1 = (struct node *)malloc(sizeof(struct node*));
	temp1->data = data;
	temp1->link = NULL;

	if (n == 1)
	{
		temp1->link = head;
		head = temp1;
		return;
	}

	struct node * temp2 = head;

	for (int i = 0; i < n-2; ++i)
	{
		temp2 = temp2->link;
	}

	temp1->link = temp2->link;
	temp2->link = temp1;
}


int main(int argc, char const *argv[])
{
	head = NULL;
	Insert(2,1);
	Insert(3,2);
	Insert(4,1);
	Insert(5,2);
	Print();
	return 0;
}