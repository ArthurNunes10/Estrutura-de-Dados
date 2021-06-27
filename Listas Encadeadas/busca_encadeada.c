//BUSCA LINEAR EM LISTA ENCADEADA

#include <stdio.h>
#include<stdlib.h>
#include<locale.h>

struct node
{
	int data;
	struct node * link;
};

struct node * head;

void add(int data) //adiciona elemento no final da lista
{
	struct node * temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;

	if (head == NULL)
	{
		head = temp;
		return;
	}

	struct node * aux = head;
	while(aux->link != NULL)
	{
		aux = aux->link;
	}      

	aux->link = temp;

}

void Busca_Sequencial(int data)
{
	struct node * temp3 = head;
	int n=1;

	while(temp3->link != NULL)
	{
		if (temp3->data == data)
		{
			printf("Elemento encontrado na posição %d\n.",n);
			return;
		}
		n++;
		temp3 = temp3->link;
	}  

	printf("Elemento não encontrado!\n");

}

void Print()
{
	struct node * temp1 = head;

	printf("A lista é: ");
	while(temp1 != NULL)
	{
		printf("%d ",temp1->data);
		temp1 = temp1->link;
	}
	printf("\n");
}



int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "");
	head = NULL;

	printf("Insira a quantidade de elementos:\n");

	int n, i, x;
	scanf("%d",&n);

	for (int i = 1; i <= n; ++i)
	{
		printf("Insira o %dº elemento:\n", i);
		scanf("%d",&x);
		add(x);
		Print();
	}

	printf("\nInsira um elemento para procura:\n");
	scanf("%d",&x);

	Busca_Sequencial(x);


	
	return 0;
}