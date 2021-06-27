#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char data[1000];
	struct node *link;
};

struct node* top = NULL;

void Push(char *data)
{
	struct node* temp = (struct node*) malloc(sizeof(struct node));

	strcpy(temp->data, data);
	//temp->data = data;

	temp->link = top;
	top = temp;
}

void top_list()
{
	if(top!=NULL)
	{
		printf("%s\n",top->data);
		top = top->link;
	}

	else
	{
		printf("EMPTY STACK\n");
	}
}

void Print()
{
	struct node* temp = top;

	while(temp!=NULL)
	{
		printf("%s\n",temp->data);
		temp = temp->link;
	}
}

int main(int argc, char const *argv[])
{
	char string[5], string_inteiros[1000];
	int item;

	while(scanf("%[^\n]",string)!=EOF)
	{
		getchar();
		
		if (!strcmp(string,"PUSH"))
		{
			scanf("%[^\n]",string_inteiros);
			getchar();
			Push(string_inteiros);
		}

		else
		{
			top_list();
		}
	}

	return 0;
}
