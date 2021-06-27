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
	temp->link = top;
	top = temp;
}

void pop()
{
	top = top->link;
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
		if ((string[i] == '{') || (string[i] == '(') || (string[i] == '['))
		{	
			push(&string[i]);
		}

		else if ((string[i] == '}') || (string[i] == ')') || (string[i] == ']'))
		{
			if (empty())
			{	
				printf("No\n");
				break;
			}

			else if(!comparador(&string[i]))
			{
				printf("No\n");
				break;
			}

			pop();
		}

		if (i == size-1)
		{
			if (empty()) 
			{
				printf("Yes\n");
			}
 	
 			else
 			{
 				printf("No\n");
 			}
		}
	}
	
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