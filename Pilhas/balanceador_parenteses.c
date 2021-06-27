#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node node;
typedef struct stack stack;

struct node
{
	char element[10000];
	node* link;
};

node* top = NULL;

void push (char *element)
{
	node* temp = (node*) malloc(sizeof(node));
	temp->element[0] = element[0];
	//printf("%s\n",temp->element);
	temp->link = top;
	top = temp;
}

void pop()
{
	top = top->link;
	//printf("pop realizado\n");
}

int empty()
{
	if (top != NULL)
	{
		return 0;
	}

	return 1;
}

int comparador(char *string)
{
	if ((string[0]=='}') && (top->element[0] == '{'))
	{
		return 1;
	}

	else if ((string[0]==')') && (top->element[0] == '('))
	{
		return 1;
	}

	else if ((string[0]==']') && (top->element[0] == '['))
	{
		return 1;
	}

	return 0;
}

void balanceador(char * string)
{
	int size = strlen(string);
	int i;

	for (i = 0; i < size; ++i)
	{
		//printf("E de abertura?\n");
		if ((string[i] == '{') || (string[i] == '(') || (string[i] == '['))
		{	//printf("sim\n");
			push(&string[i]);
		}

		else if ((string[i] == '}') || (string[i] == ')') || (string[i] == ']'))
		{
			//printf("nao, a lista está vazia?\n");
			if (empty())
			{	
				//printf("esta vazia, logo nao esta balanceado\n");
				printf("No\n");
				break;
			}
			//printf("nao\n");
			//printf("o par correspondente esta na lista?\n");

			if(!comparador(&string[i]))
			{
				//printf("nao, logo nao esta balanceado\n");
				printf("No\n");
				break;
			}
			//printf("sim\n");

			pop();
		}

		
		
		if (i == size-1)
		{
			//printf("terminada a ultima iteracao do for, a lista esta vazia?\n");
			if (empty()) 
			{
				//printf("Sim, esta vazia\n");
				printf("Yes\n");
			}
 	
 			else
 			{
 				//printf("nao, nao esta vazia\n");
 				printf("No\n");
 			}
		}
	}

	//printf("fim da execucao\n");
	top = NULL;
}

int main(int argc, char const *argv[])
{
	char string[10000];
	int n, i;
	
	scanf("%d",&n);
	getchar();
	
	for (i = 0; i < n; i++)
	{
		
		if (!scanf("%[^\n]",string))
		{
			printf("Yes\n");
		}
		else
		{
			balanceador(string);
		}

		getchar();
	}

	

	return 0;
}