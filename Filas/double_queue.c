#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct _deque deque_t;
typedef struct _node   node_t;

//Guarda um ponteiro pro node anterior, para o proximo node e o valor guardado
struct _node {
	node_t *prev;
	node_t *next;
 	int    value;
};

//Guarda um ponteiro para o primeiro node, um ponteiro para o ultimo node, e o tamanho do deque
struct _deque {
  	node_t *front;
  	node_t  *rear;
  	int      size;
};

//Cria um node que guarda os valores que são enfileirados no deque
node_t*  node_new     (int value)
{
  node_t * new_node = (node_t*) malloc(sizeof(node_t));
  new_node->value = value;
  new_node->prev = NULL;
  new_node->next = NULL;
  return new_node;
}

//Cria um deque dinamicamente e retorna seu endereço de memoria
deque_t* construct    ()
{
  deque_t* new_deque = (deque_t*) malloc(sizeof(deque_t));
  new_deque->front = NULL;
  new_deque->rear = NULL;
  new_deque->size = 0;
  return new_deque;
}
//Libera a memória do conteúdo e do próprio deque
void     destruct     (deque_t *deque)
{
  if (deque->size != 0) //caso a lista nao esteja vazia
  {
    if (deque->front != NULL)//caso deque->front seja diferente de null
    {
      while(deque->front != NULL)
      {
        node_t* temp = deque->front;
        deque->front = temp->next;
        free(temp);
      }
      free(deque);
      return;
    }
  }
}

//Retorna o tamanho do deque
int      size         (deque_t *deque)
{
  return deque->size;
}
//Retorna verdadeiro se o deque esta vazio, caso contrário, retorna falso
bool     empty        (deque_t *deque)
{
  if (deque->size == 0)
  {
    return true;
  }
  return false;
}

//Retorna o valor da frente da lista, retorna int_min quando a lista estiver vazia
int      front        (deque_t *deque)
{
  if (!empty(deque))
  {
    return deque->front->value;
  }
  return INT_MIN;
}
//Retorna o valor do fim da lista, retorna int_min quando a lista estiver vazia
int      rear         (deque_t *deque)
{
  if (!empty(deque))
  {
    return deque->rear->value;
  }
  return INT_MIN;
}

//Cria um nó que guarda um valor e o adiciona ao fim do deque
void     enqueue_rear (deque_t *deque, int value)
{
  node_t *new_node = node_new(value);

  if (deque->rear == NULL)
  {
    deque->rear = new_node;
    deque->size++;
    if (deque->front == NULL)
    {
      deque->front = new_node;
    }
    return;
  }

  deque->rear->next = new_node;
  new_node->prev = deque->rear;
  deque->rear = new_node;
  deque->size++;
  if (deque->front == NULL)
    {
      deque->front = new_node;
    }
}
//Cria um nó que guarda um valor e o adiciona ao inicio do deque
void     enqueue_front(deque_t *deque, int value)
{
  node_t *new_node = node_new(value);

  if (deque->front == NULL)
  {
    deque->front = new_node;
    deque->size++;
    if (deque->rear == NULL)
    {
      deque->rear = new_node;
    }
    return;
  }
  deque->front->prev = new_node;
  new_node->next = deque->front;
  deque->front = new_node;
  deque->size++;

  if (deque->rear == NULL)
    {
      deque->rear = new_node;
    }

}
//Retira o valor do final caso não esteja vazia
void     dequeue_rear (deque_t *deque)
{
  if (!empty(deque))
  {
    node_t * temp = deque->rear;
    deque->rear = temp->prev;
    deque->rear->next = temp->next;
    free(temp);
  }
}
//Retira o valor da frente caso não esteja vazia
void     dequeue_front(deque_t *deque)
{
  if (!empty(deque))
  {
    node_t * temp = deque->front;
    deque->front = temp->next;
    deque->front->prev = temp->prev;
    free(temp);
  }
}
//Limpa o conteudo do deque(deixa ele vazio)
void     erase        (deque_t *deque)
{
  if (!empty(deque))
  {
    if (deque->front != NULL)//caso deque->front seja diferente de null
    {
      
      while(deque->front != NULL)
      {
        node_t* temp = deque->front;
        deque->front = temp->next;
        free(temp);
      }

      deque->rear = NULL;
      return;
    }
  }
}

//Imprime o deque em uma unica linha, com os elementos separados por um espaço,
//terminando com um \n, lembrando de respeitar os conceitos de fila.
void     print        (deque_t *deque)
{
  if (deque->front != NULL)
  {
    node_t * temp = deque->front;
    printf("%d",temp->value);
    while(temp!=NULL)
    {
      temp = temp->next;
      if (temp!=NULL)
      {
        printf(" %d",temp->value);
      }
    }
    printf("\n");
  }
}

int main() {
  int i, num;
    scanf("%d", &num);
  
    deque_t* deque = construct();
  
    int vector[num];
    for(i = 0; i < num; ++i)
        scanf("%d", &vector[i]);
  
    for(i = 0; i < num; ++i)
        enqueue_rear(deque, vector[i]);
  
  printf("%d\n", front(deque));
    printf("%d\n", rear (deque));
  
    if(!empty(deque))
      printf("The size of the deque %d\n", size(deque));
    else
        printf("The deque is empty\n");
    
    scanf("%d", &num);

    for(i = 0; i < num; ++i)
       enqueue_front(deque, i);

    print(deque);
    dequeue_front(deque);
    print(deque);
    dequeue_rear (deque);
    print(deque);
    erase(deque);

    for(i = 0; i < 3; ++i)
      enqueue_rear(deque, i);
      
    print(deque);
    destruct(deque);
       
  return 0;
}
//Insira o código aqui