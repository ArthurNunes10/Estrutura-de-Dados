//VERIFICA SE UMA LISTA B É SUBCONJUNTO DE UMA LISTA A
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * link;
};

struct node * add(int data, struct node * head)
{
	struct node * temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;

	if(head == NULL)
	{
		head = temp;
	}

	else
	{
		struct node * temp2 = head;
		
		while(temp2->link != NULL)
		{
			temp2 = temp2->link;
		}

		temp2->link = temp;
	}

	return head;
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

void Subconjunto(struct node * head1, struct node * head2, int t2)
{
	struct node * temp1 = head1;
	struct node * temp2 = head2;
	struct node * prox = temp1->link;
	int contador = 0;

	while(temp1 != NULL)
	{
		while((temp1->data) == (prox->data))
		{
			temp1=temp1->link;
		}

		while(temp2 != NULL)
		{
			if (temp1->data == temp2->data)
			{
				contador++;
			}

			temp2 = temp2->link;
		}
		
		temp1=temp1->link;
		temp2=head2;
	}

	if(contador == t2)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
}

int main(int argc, char const *argv[])
{
	struct node * head1 = NULL;
	struct node * head2 = NULL;

	int tamanho, i, data;

	scanf("%d",&tamanho);

	for (i = 0; i < tamanho; ++i)
	{
		scanf("%d",&data);
		head1 = add(data, head1);
		bubble_sort(head1);
	}

	scanf("%d",&tamanho);
	
	for (i = 0; i < tamanho; ++i)
	{
		scanf("%d",&data);
		head2 = add(data, head2);
	}

	Subconjunto(head1, head2, tamanho);

	return 0;
}