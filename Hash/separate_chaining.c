#include<stdio.h>
#include<stdlib.h>

typedef struct node node;
typedef struct hash_table hash_table;

struct node{
	int key;
	node* next;
};

struct hash_table{
	node *table[max_size_table];
};

hash_table * create_hash_table()
{
	hash_table* new_hash_table = (hash_table*) malloc(sizeof(hash_table));

	for (int i = 0; i < max_size_table; ++i)
	{
		new_hash_table -> table[i] = NULL;
	}
	return new_hash_table;
}

void put(hash_table *ht, int key)
{
	int h = key % max_size_table;

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

int get (hash_table *ht, int key)
{
	int h = key % max_size_table;
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

void print_hash_table(hash_table *ht)
{
	int i;
	
	for (int i = 0; i < max_size_table; ++i)
	{
		if (ht->table[i]==NULL)
		{
			printf("NULL\n");
		}
		else
		{
			node*temp = ht->table[i];
			while(temp!=NULL)
			{
				printf("%d ",temp->key);
				temp = temp->next;
			}
			printf("\n");
			
		}
	}
}

int main(int argc, char const *argv[])
{
	hash_table *ht = create_hash_table();

	put(ht,1000);
	put(ht,2100);
	put(ht,2000);
	put(ht,3000);
	put(ht,4000);
	put(ht,4000);

	print_hash_table(ht);
	return 0;
}