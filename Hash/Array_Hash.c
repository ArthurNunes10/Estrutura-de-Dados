#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct element element; //estrutura que guarda os elementos
typedef struct hash_table hash_table;// pilha de ponteiros

struct element{ 
	int key;
	char value[200];
};

struct hash_table{ 
	element *table[200];
};
//cria uma pilha de ponteiros e a retorna
hash_table * create_hash_table() 
{
	hash_table* new_hash_table = (hash_table*) malloc(sizeof(hash_table));

	int i;

	for (int i = 0; i < 200; ++i)
	{
		new_hash_table -> table[i] = NULL;
	}
	return new_hash_table;
}
//recebe uma tabela hash, chave e elemento, e adiciona elemento
void put(hash_table *ht, int key, char *value)
{
	int h = key % 200;

	while(ht->table[h] != NULL)
	{
		if (ht->table[h]->key == key)
		{
			strcpy(ht->table[h]->value, value);
			break;
		}
		h = (h+1) % 200;
	}

	if (ht->table[h] == NULL)
	{
		element * new_element = (element*) malloc(sizeof(element));
		new_element->key = key;
		strcpy(new_element->value, value);
		ht->table[h] = new_element;
	}
}


//recebe uma string e gera uma chave a partir dos seus valores em ascii
int key_gerador(char *string) 
{
	int decimal[strlen(string)];
	int i,key,soma=0;

	for (i = 0; i < strlen(string); ++i)
	{
		decimal[i] = (int*)string[i];
		//printf("decimal = %d",decimal[i]);
		soma += decimal[i];
	}
		key = soma % 200;
	return key;
}

int calculo(char *string, int posicao_elemento)
{
	int i, posicao_alfa = 0, posicao = 0, valor=0;
	for (i = 0; i < strlen(string); i++)
	{
		posicao_alfa += string[i] - 65;
		posicao+=i;
	}
	valor += posicao_alfa + posicao_elemento*(strlen(string)) + posicao;
	return valor;
}

int main(int argc, char const *argv[])
{
	int i, j, n, linhas, key, valor=0;
	char string[60];
	scanf("%d",&n);

	for (i = 0; i < n; i++)
	{
		hash_table* ht = create_hash_table();
		scanf("%d",&linhas);
		getchar();
		for (j = 0; j < linhas; j++)
		{
			key = j;
			scanf("%[^\n]",string);
			getchar();
			put(ht,key,string);
			valor += calculo(string,key);
		}
		printf("%d\n",valor);
		valor = 0;
		free(ht);

	}
	return 0;
}