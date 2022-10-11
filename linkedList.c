#include "linkedList.h"

typedef struct Node Node;
struct Node {
	Node * next;
	void * data;
};

struct List {
	Node * head;
	Node * tail;
	int size;
};

/* Helper function, creates a "Node" given the data and pointer to next Node.
COMPLEXITY: O(1) */
Node * makeNode(Node * next, void * data) 
{
	Node * node = malloc(sizeof(Node));
	if(node == NULL) 
	{
		return NULL;
	}
	else 
	{
		*node = (Node){ next, data };
	}

	return node;
}

/* Initializes a List struct and returns it. Should be called before subsequent functions.
 COMPLEXITY: O(1) */
List * initList()
{
	List * newList = malloc(sizeof(List));

	if(newList == NULL) 
	{
		return newList;
	}
	else 
	{
		*(newList) = (List){NULL, NULL, 0};
	}

	return newList;
}
/* Returns the size of a List.
 COMPLEXITY: O(1) */
int getSize(List *list)
{
	return list->size;
}
/* Returns the object at a certain index of the list. 
Returns NULL and gives an error message if there is an error.
 COMPLEXITY: O(n) */
void * getAtIndex(List *list, int index)
{
	if(index >= getSize(list))
	{
		printf("Error, invalid index!\n");
		return NULL;
	}
	Node * temp = list->head;
	for(int i = 0; i < index; i++)
	{	
		temp = temp->next;
	}
	return temp->data;
}
/* Frees a list and all the allocated "Nodes" within it. Does not free the user's memory.
 COMPLEXITY: O(n) */
void freeList(List *list)
{
	Node * p = list->head;
	Node * temp = p;

	while(p != NULL)
	{
		temp = p;
		p = p->next;
		free(temp);
	}

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	free(list);
	return;
}

/* Inserts the given object at the head of the list. Returns 1 on success, else 0.
 COMPLEXITY: O(1) */
int insertAtHead(List *list, void *object)
{
	if(object == NULL || list == NULL) 
	{
		return 0;
	}
	Node * insertion = makeNode(list->head, object);
	list->head = insertion;
	if(getSize(list) == 0)
	{
		list->tail = insertion;
	}

	(list->size)++;
	return 0;
}
/* Returns the object at the tail of the list (does not change the list)
 COMPLEXITY: O(1) */
void * getTail(List *list)
{
	return list->tail->data;
}

/* Removes and returns the object at the tail of the list.
COMPLEXITY: O(n) */
void * removeTail(List *list)
{
	if(getSize(list) == 0)
	{
		printf("Error, the list has no values in it\n");
		return NULL;
	}

	Node * temp = list->head;
	Node * removedNode = list->tail;
	void * object = removedNode->data;

	if(getSize(list) == 1)
	{
		free(removedNode);
		list->head = NULL;
		list->tail = NULL;
		list->size--;
		return object;
	}

	for(int i = 0; i < getSize(list) - 2; i++)
	{
		temp = temp->next;
	}
	
	list->tail = temp;
	if(getSize(list)==2)
	{
		list->head = temp;
	}

	list->size--;
	list->tail->next = NULL;
	free(removedNode);
	
	return object;
}