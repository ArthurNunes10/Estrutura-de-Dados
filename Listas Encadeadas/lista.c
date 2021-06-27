
ADT
{
	node * create_linked_list();//cria uma cabeça
	node * add(node *head, int item); //adiciona no na cabeça da lista
	node *search(node *head, int item); //retorna no com elemento procurado, caso nao esteja na lista retorna NULL
	int is_empty(node * head); //limpa a lista
	void print_linked_list(node *head); //imprime lista
	void print_linked_list(node *head); //imprime lista recursivamente
	node* remove(node* head, int item) // remove no
	node* ordenacao(node* head) //ordena lista em ordem crescente ou decrescente
	void swap(node* a, node * b); //realiza a troca dos itens de dois nos
	node * intersecao (node* head1, node * head2, node* head3) //faz a intersecao de duas listas
}

typedef struct node node;

struct node
{
	int item;
	node* next;
};

node* create_linked_list()
{
	return NULL;
}

int is_empty(node* head)
{
	return (head == NULL);
}

node* add(node* head, int item)
{
	node* new_node = (node*) malloc(sizeof(node));
	new_node->item = item;
	new_node->next = head;
	head = new_node;
	return head;
}

void print_linked_list(node *head) //print normal
{
	node* temp = head;
	while(temp != NULL)
	{
		printf("%d ",temp->item);
		temp = temp->next;
	}
	printf("\n");
}

void print_linked_list(node* head) //print recursivo
{
	node* temp = head;
	if (!is_empty(temp))
	{
		printf("%d\n",temp->item);
		print_linked_list(temp->next);
	}
}

node* search(node *head, int item)
{
	node* temp = head;
	while(temp != NULL)
	{
		temp = temp->next;
		if ((temp->item) == item)
		{
			return temp;
		}
	}
	return NULL;
}

node* remove(node* head, int item)
{
	node* previous = NULL;
	node* current = head;

	while((current != NULL) && (current->item != item))
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
	{
		return head;
	}

	if (previous == NULL)
	{
		head = current->next;
	}
	else
	{
		previous->next = current->next;
	}
	free(current);
	return head;
}

void swap(node * a,node * b)
{
	int aux;
    aux	 = b->data;
	b->data = a->data;
	a->data = aux;
}

void ordenacao(node * head)
{
	node * temp = head;
	node * a = head;
	node * b = temp->link;
	node * aux = head;

	while(aux != NULL)
	{
		while(b != NULL)
		{
			if((a->data)>(b->data)) //para mudar a forma como a lista sera ordenada, basta mudar o <>
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

node * intersecao (node* head1, node * head2, node* head3)
{
	//considerando que as listas 1 e 2 já estão ordenadas em ordem crescente !!
	node* temp1 = head1; //temp1 aponta para cabeça da lista 1
	node* temp2 = head2; // temp2 aponta para cabeça da lista 2
	node * prox1 = temp1->link;
	node * prox2 = temp2->link;

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
	return head3; //recebe a combinação das listas
}