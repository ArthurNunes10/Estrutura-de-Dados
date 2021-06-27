//INSERINDO ELEMENTOS NO FINAL DA LISTA

#include<stdio.h>
#include<stdlib.h>


struct node //estrutura do nó: no[data][link]
{
	int data; //armazena dados
	struct node * link; // armazena o endereço do próximo bloco
};

struct node * A; // armazena o endereço do bloco principal

int main(int argc, char const *argv[])
{
	A=NULL;
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->data = 2; // (*temp).data =2;
	temp->link = NULL; // (*temp).link = NULL
	A = temp;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = 4;
	temp->link = NULL;

	struct node *temp1 = A;
	
	while(temp1->link != NULL)
	{
		temp1 = temp1->link;
		
	}

	temp1->link = temp;
	

	return 0;
}