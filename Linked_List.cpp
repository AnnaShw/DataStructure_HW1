#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
typedef struct List list;
struct List {
	int data;
	list* next;
};

list* BuildNode(int num1)
{
	list *node = (list*)malloc(sizeof(list));
	node->data = num1;
	node->next = NULL;
	return node;
}

list* BuildList()
{
	list *head = NULL, *temp = head;
	int num;
	printf("Enter numbers for list, -1 for end: ");
	scanf("%d ", &num);
	while (num != -1)
	{
		if (head == NULL)
		{
			head = BuildNode(num);
			temp = head;
		}
		else
		{
			temp->next = BuildNode(num);
			temp = temp->next;
		}
		scanf("%d", &num);
	}
		return head;
}

void PrintList(list *head)
{
	list *temp = head;
	printf("\nThe list is: ");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

list* addToHead(list* head, int num1)
{
	list *new_elem = BuildNode(num1);
	new_elem->next = head;
	return new_elem;
}

list* addToTail(list *head, int num1)
{
	list *temp, *new_elem;
	new_elem = BuildNode(num1);
	if (head == NULL)
		return new_elem;
	for (temp = head; temp->next != NULL; temp = temp->next);
	temp->next = new_elem;
	return head;
}

list* addToIndex(list* head, int num1, int index)
{
	list *temp, *new_elem;
	new_elem = BuildNode(num1);
	int i;
	if (head == NULL || index == 1)
	{
		new_elem->next = head;
		return new_elem;
	}
	for (i = 1, temp = head; temp->next != NULL && i < index - 1; temp = temp->next, i++);
	new_elem->next = temp->next;
	temp->next = new_elem;
	return head;
}

void SelectionSort(list* head)
{
	list* i;
	list* j = (list*)malloc(sizeof(list));
	list* min = (list*)malloc(sizeof(list));
	list* temp = (list*)malloc(sizeof(list));
	i = head;
	for (; i; i=i->next)
	{
		min = i;
		for (j = i->next; j; j = j->next)
			if ((j->data) < (min->data))
				min = j;
		SWAP(i->data, min->data, temp->data);
		
	}
}
list* FreeList(list *head)
{
	list *temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	return NULL;
}

list* Delete(list* head, int value)
{
	list *previous=head, *current=head->next;
	if (head == NULL)
		return head;
	if (head->data == value)
	{
		list *temp = head;
		head = head->next;
		free(temp);
		return head;
	}
	while (previous!=NULL)
	{
		if (previous->data == value)
			break;
		current = previous;
		previous = previous->next;
	}
	if (previous != NULL)
		current->next = previous->next;
	free(previous);
	return head;
}