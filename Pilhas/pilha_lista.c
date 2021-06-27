#include<stdio.h>
#include<stdlib.h>

struct node
{
	int item;
	struct node* next;
};

struct node* top = NULL;

void push(int item)
{
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->item = item;
	temp->next = top;
	top = temp;
}

void pop()
{
	if (top==NULL){
		printf("#ERROR: EMPTY STACK\n");
		return;
	}
	top = top->next;

}

void imprimir()
{
	struct node* temp = top;
	
	while(temp!=NULL)
	{
		printf("%d \n",temp->item);
		temp = temp->next;
	}
	printf("\n");
}

int top_stack()
{
	if (top!=NULL)
	{
		struct node* temp = top;
		return temp->item;
	}
}

int empty()
{
	if (top == NULL)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

int main(int argc, char const *argv[])
{
	push(2); imprimir();
	push(5); imprimir();
	push(6); imprimir();
	push(3); imprimir();
	push(7); imprimir();
	
	int x = top_stack();
	printf("Top: %d\n", x);
	pop();
	imprimir();
	
	return 0;
}