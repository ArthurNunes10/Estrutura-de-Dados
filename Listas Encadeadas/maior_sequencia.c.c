#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int data;
	struct node * link;
};

struct node* add(struct node* head, int data)
{
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;

	if (head == NULL)
	{
		head = temp;
	}

	else
	{
		struct node* temp2 = head;

		while(temp2->link != NULL)
		{
			temp2 = temp2->link;
		}

		temp2->link = temp;
	}

	return head;
}

void Maior_Sequencia(struct node* head)
{
	struct node* temp = head;

	int contador = 0, qnt_maior=0, posicao = 0, final=0, aux_final=0, inicio=0, aux_inicio=0;

	while(temp != NULL)
	{
		if (temp->data == 0)
		{
			if(contador == 0)
			{
				inicio = posicao;
			}
			contador++;
			final = posicao;

			if (temp->link == NULL)
			{
				if ((contador!=0)&&(qnt_maior<contador))
				{
					qnt_maior = contador;
					aux_inicio = inicio;
					aux_final = final;
				}
			}
		}

		else 
		{
			if ((contador!=0)&&(qnt_maior<contador))
			{
				qnt_maior = contador;
				aux_inicio = inicio;
				aux_final = final;
			}
			contador = 0;

		}
		temp=temp->link;
		posicao++;
	}
	if (aux_final==aux_inicio)
	{
		printf("0 0\n");
	}

	else
	{
		printf("%d %d\n",aux_inicio, aux_final);
	}
	
}

int main(int argc, char const *argv[])
{
	char string[1000], aux[1000];
	int i, item;

	scanf("%s",string);

	while (strcmp(string,"0")!=0)
	{
		struct node* head = NULL;
		for(i=0; i<strlen(string); i++)
		{
			aux[0] = string[i];
			item = atoi(aux);
			head = add(head,item);
		}
		Maior_Sequencia(head);
		scanf("%s",string);
	}
	return 0;
}