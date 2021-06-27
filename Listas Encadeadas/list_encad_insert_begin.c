//INSERINDO ELEMENTOS NO INICIO DA LISTA

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node* head;

void Insert(int x)
{
	struct node * temp = (struct node *) malloc(sizeof(struct node));
	temp -> data = x;
	temp -> link = head;
	head = temp;
}
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

int main(int argc, char const *argv[])
{
	head = NULL;
	printf("Insira a quantidade de elementos:\n");
	int i,n,x;
	scanf("%d",&n);

	for (int i = 0; i < n; ++i)
	{
		printf("Digite o número:\n");
		scanf("%d",&x);
		Insert(x);
		Print();
	}
	
	return 0;
}