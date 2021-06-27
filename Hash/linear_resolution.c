#include<stdio.h>
#include<stdlib.h>

typedef struct element element;
typedef struct hash_table hash_table;

struct element{
	int key;	
	char value;
};

struct hash_table{
	element *table[50];
};

hash_table * create_hash_table()
{
	hash_table* new_hash_table = (hash_table*) malloc(sizeof(hash_table));

	int i;

	for (int i = 0; i < 50; ++i)
	{
		new_hash_table -> table[i] = NULL;
	}
	return new_hash_table;
}

void put(hash_table *ht, int key, char *value)
{
	int h = value % 50;

	while(ht->table[h] != NULL)
	{
		if (ht->table[h]->key == key)
		{
			ht->table[h]->value = value;
			break;
		}
		h = (h+1) % 50;
	}

	if (ht->table[h] == NULL)
	{
		element * new_element = (element*) malloc(sizeof(element));
		new_element->key = key;
		new_element->value = value;
		ht->table[h] = new_element;
	}
}

int get (hash_table *ht, int key)
{
	int h = key % 50;
	while(ht->table[h] != NULL){
		if (ht->table[h]->key == key)
		{
			return ht->table[h]->value;
		}

		h = (h + 1) % 50;
	}
	return -100;
}

void delete(hash_table *ht, int key)
{
	int h = key % 50;
	while(ht->table[h] != NULL){
		if (ht->table[h]->key == key)
		{
			ht->table[h]->key = -1;
		}

		h = (h + 1) % 50;
	}
}

void print_hash_table(hash_table *ht)
{
	int i;
	
	for (int i = 0; i < 50; ++i)
	{
		if (ht->table[i]==NULL)
		{
			printf("NULL\n");
		}
		else
		{
			printf("%d\n",ht->table[i]->key);
		}
	}
}

int main(int argc, char const *argv[])
{
	hash_table *ht = create_hash_table();

	put(ht, 3, 1000);
	put(ht, 14, 2000);
	put(ht, 15, 3000);
	put(ht, 92, 4000);

	print_hash_table(ht);
	return 0;
}