//FAZ INTERSEÇÃO DE DUAS LISTAS ENCADEADAS
#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node * link;
};

struct node * add(struct node* head, int data)
{
	struct node * temp = (struct node*) malloc(sizeof(struct node));

	temp->data = data;
	temp->link = NULL;

	if (head == NULL)
	{
		head = temp;
	}

	else
	{
		struct node * temp2 = head;

		while(temp2->link != NULL)
		{
			temp2=temp2->link;
		}

		temp2->link = temp;
	}

	return head;
}

void Print(struct node* head)
{
	struct node * temp = head;
	
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
}

void swap(struct node * a, struct node * b)
{
	int aux;
	
    aux	 = b->data;
	b->data = a->data;
	a->data = aux;
}

void bubble_sort(struct node * head)
{
	struct node * temp = head;
	struct node * a = head;
	struct node * b = temp->link;
	struct node * aux = head;

	while(aux != NULL)
	{
		while(b != NULL)
		{
			if((a->data)>(b->data))
			{
				swap(a, b);
			}
			a=a->link;
			b=b->link;
		}
		a = temp;
		b = a->link;
		aux=aux->link;
	}
}

struct node * Intersercao (struct node* head1, struct node * head2, struct node* head3)
{
		//considerando que as listas 1 e 2 já estão ordenadas em ordem crescente !!
	struct node* temp1 = head1; //temp1 aponta para cabeça da lista 1
	struct node* temp2 = head2; // temp2 aponta para cabeça da lista 2
	struct node * prox1 = temp1->link;
	struct node * prox2 = temp2->link;

	while(temp1 != NULL)
	{
		while(temp2 != NULL)
		{
			if (temp1->data == temp2->data)
			{
				head3 = add(head3, temp2->data);
			}

			temp2 = temp2->link;
		}
		
		temp1=temp1->link;
		temp2=head2;
	}
	return head3;
}



int main(int argc, char const *argv[])
{
	struct node* head1 = NULL; //cabeça da lista 1
	struct node* head2 = NULL; //cabeça da lista 2
	struct node* head3 = NULL; //estrutura que receberá o retorno da função interseção, ou seja, será a cabeça da lista 3

	int item, i;

	for (i=1; i<=10; ++i)
	{
		if (i<=5)
		{
			scanf("%d",&item);
			head1 = add(head1, item);
		}

		else
		{
			scanf("%d",&item);
			head2 = add(head2, item);
		}
	}

	bubble_sort(head1); //ordena a lista 1
	bubble_sort(head2); //ordena a lista 2

	printf("Lista1: ");
	Print(head1);
	printf("\n");
	printf("Lista2: ");
	Print(head2);
	printf("\n");

	head3 = Intersercao(head1, head2, head3); //recebe o endereço da lista da interseção

	//impressão dos resultados
	if(head3 != NULL) 
	{
		bubble_sort(head3);
		printf("Interseção: \n");
		Print (head3);
	}

	else
	{
		printf("VAZIO");
	}
	
	return 0;
}