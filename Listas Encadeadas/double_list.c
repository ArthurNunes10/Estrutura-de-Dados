#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

struct node* head;

struct node* create_node(int x) //cria um novo no e add o elemento,e retorna o adress do no
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data = x;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

void Insert_Head(int x)//insere novo no na cabeça, obs: a cabeça no inicio da lista
{
	struct node* new_node = create_node(x);
	if (head==NULL)
	{
		head = new_node;
		return;
	}

	head->prev = new_node;
	new_node->next = head;
	head = new_node;
}

void Insert_End(int x)//insere novo no final, obs: o head no final da lista
{
	struct node* new_node = create_node(x);
	if (head==NULL)
	{
		head = new_node;
		return;
	}

	struct node* temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}

	temp->next = new_node;
	new_node->prev = temp;
}

void print()//Usado para listas com cabeça no final. Imprime do inicio ao final
{
	struct node* temp = head;
	printf("Forward: ");
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void reverse_print()//iUsado em listas com cabeça na frente. Imprime de tras pra frente
{
	struct node* temp = head;
	if (temp == NULL) return;
	
	while(temp->next != NULL)
	{
		temp = temp->next;
	}

	printf("Reverse: ");

	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->prev;
	}

	printf("\n");
}


void delete(int data) //Usado para listas com cabeça no final. Deleta o no
{
	struct node* temp = head;
	int flag = 0;
	while(temp->data != data)
	{
		flag = 1;
		temp = temp->next;
	}

	if (flag == 0)
	{
		head = temp->next;
		free(temp);
		return;
	}
	temp->prev->next = temp->next;
	free(temp);
}

int main(int argc, char const *argv[])
{
	head = NULL;
	printf("Adicionando no final da lista:\n");
	Insert_End(2);
	Insert_End(4); 
	Insert_End(6); 
	print();
	reverse_print();
	delete(6);
	print();
	printf("\nAdicionando no inicio da lista:\n");
	head = NULL;
	Insert_Head(2); 
	Insert_Head(4); 
	Insert_Head(6); 
	print();
	reverse_print();
	delete(4);
	print();
	return 0;
}