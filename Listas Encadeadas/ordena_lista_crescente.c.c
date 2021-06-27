#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* link;
};

struct node* head;

void add(int data)
{
	struct node * temp = (struct node*) malloc(sizeof(struct node));

	temp->data = data;
	temp->link = NULL;

	if (head == NULL)
	{
		head = temp;
		return;
	}

	struct node * temp2 = head;

	while(temp2->link != NULL)
	{
		temp2=temp2->link;
	}

	temp2->link = temp;
}

void swap(struct node * a, struct node * b)
{
	int aux;
	
    aux	 = b->data;
	b->data = a->data;
	a->data = aux;
}

void bubble_sort()
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

void Print()
{
	struct node * temp = head;

	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp=temp->link;
	}
}

int main(int argc, char const *argv[])
{
	head = NULL;

	int item;

	while(scanf("%d",&item) != EOF)
	{
		add(item);
	}

	bubble_sort();
	Print();


	return 0;
}