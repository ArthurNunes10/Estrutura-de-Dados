#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 1000
typedef struct node node;
typedef struct hash_table hash_table;

struct node{
	int key;
	node* next;
};

struct hash_table{
	node *table[MAX_SIZE];
};

hash_table * create_hash_table(int size)
{
	hash_table* new_hash_table = (hash_table*) malloc(sizeof(hash_table));

	for (int i = 0; i < size; ++i)
	{
		new_hash_table -> table[i] = NULL;
	}
	return new_hash_table;
}

void put(hash_table *ht, int key, int size)
{
	int h = key % size;

	if (ht->table[h]!=NULL)
	{
		node* new_node = (node*) malloc(sizeof(node));
		new_node->key = key;
		new_node->next = NULL;
		
		node* temp = ht->table[h];
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}

		temp->next = new_node;
	}
	else if (ht->table[h]==NULL)
	{
		node* new_node = (node*) malloc(sizeof(node));
		new_node->key = key;
		new_node->next = NULL;
		ht->table[h] = new_node;
	}

}

/*int get (hash_table *ht, int key)
{
	int h = key % 11;
	while(ht->table[h] != NULL){
		if (ht->table[h]->key == key)
		{
			return ht->table[h]->key;
		}

		h = (h + 1) % 11;
	}
	return -100;
}

void delete(hash_table *ht, int key)
{
	int h = key % 11;
	while(ht->table[h] != NULL){
		if (ht->table[h]->key == key)
		{
			ht->table[h]->key = -1;
		}

		h = (h + 1) % 11;
	}
}
*/
void print_hash_table(hash_table *ht, int size)
{
	int i;
	
	for (int i = 0; i < size; ++i)
	{
		if (ht->table[i]==NULL)
		{
			printf("%d -> \\ \n",i);
		}
		else
		{
			node*temp = ht->table[i];
			printf("%d -> ",i);
			while(temp!=NULL)
			{		
				printf("%d -> ",temp->key);
				temp = temp->next;
			}
			printf("\\ \n");
			
		}
	}
}

int main(int argc, char const *argv[])
{
	
	int i,j,n, qnt, key, size_hash_table;

	scanf("%d",&n);//recebe a quantidade de testes

	for (i = 0; i < n; i++)
	{
		scanf("%d",&size_hash_table); //armazena o tamanho da tab hash
		scanf("%d",&qnt);//armazena a qnt de keys que serao adicionadas
		
		hash_table *ht = create_hash_table(size_hash_table);
		for (j = 0; j < qnt; ++j)
		{
			scanf("%d",&key);
			put(ht,key,size_hash_table);
		}
		print_hash_table(ht,size_hash_table);
		free(ht);
	}
	return 0;
}