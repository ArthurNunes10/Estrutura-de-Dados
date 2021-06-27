//Excluindo nós da lista

#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node * link;
};

struct node * head;

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

void Print()
{
	struct node * temp3 = head;
	printf("A lista é:");
	while(temp3 != NULL)
	{
		printf("%d ",temp3->data);
		temp3 = temp3->link;
	}
	printf("\n");
}

void Delete(int n )
{
	struct node * temp1 = head;

	if (n ==1)
	{
		head = temp1->link;
		free(temp1);
		return;
	}

	int i;

	for (int i = 0; i < n-2; ++i)
	{
		temp1 = temp1->link;
	}

	struct node * temp2 = temp1->link;
	temp1->link = temp2->link;
	free(temp2);

}
int main(int argc, char const *argv[])
{
	head = NULL;
	Insert(2,1);
	Insert(3,2);
	Insert(4,3);
	Insert(5,4);

	Print();

	int n;

	printf("Digite a posição n para deletar:\n");
	scanf("%d",&n);

	Delete(n);
	Print();

	return 0;
}