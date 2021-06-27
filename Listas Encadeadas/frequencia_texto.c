#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char caracter[1];
	int frequencia;
	struct node * link;
};

struct node* head;

void add(char *caracter, int indice, int frequencia)
{
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	int flag=0;

	if (head!=NULL)
	{
		struct node* temp1 = head;

		while(temp1 != NULL)
		{
			if(caracter[indice]==temp1->caracter[0])
			{
				flag = 1;
				break;
			}
			
			temp1=temp1->link;
		}

		if (flag==0)
		{
			temp->caracter[0] = caracter[indice];
			temp->frequencia = frequencia;
			temp->link = NULL;

			struct node* temp2 = head;

			while(temp2->link != NULL)
			{
				temp2 = temp2->link;
			}

			temp2->link = temp;
		}
	}

	else
	{
		temp->caracter[0] = caracter[indice];
		temp->frequencia = frequencia;
		temp->link = NULL;
		head = temp;
		
	}
}

void Print()
{
	struct node* temp = head;

	while(temp!=NULL)
	{
		printf("%s ",temp->caracter);
		printf("%d\n",temp->frequencia);
		temp=temp->link;
	}
	printf("\n");
}


int main(int argc, char const *argv[])
{
	head = NULL;
	char string[257], string_aux[257];
	int i,j,aux1,aux2, frequencia=0;
	

	//scanf("%s",string);
	gets(string);


	for (j = strlen(string)-1; j>=0; j--)
	{
		for (i = 0; i < j; ++i)
		{
			aux1 = string[i];
			aux2 = string[i+1];
			if (aux1<aux2)
			{
				string_aux[i] = string[i];
				string[i] = string[i+1];
				string[i+1] = string_aux[i];
				
			}
		}
		
	}
	

	

	for (i = 0; i < strlen(string); ++i)
	{
		for (j = 0; j < strlen(string); ++j)
		{
			if (string[i] == string[j])
			{
				frequencia++;
			}
		}
		
		add(string, i, frequencia);
		frequencia = 0;

	}

	Print();
	return 0;
}