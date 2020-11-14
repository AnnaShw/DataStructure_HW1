#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"Linked_List.h"

int main()
{
	list* head = NULL;
	int num, index;
	head = BuildList();
	PrintList(head);
	printf("size:%d", SizeOfList(head));

	printf("\nEnter a number for new head node: ");
	scanf("%d", &num);
	head = addToHead(head, num);
	PrintList(head);
	printf("size:%d", SizeOfList(head));

	printf("\nEnter a number for new tail node: ");
	scanf("%d", &num);
	head = addToTail(head, num);
	PrintList(head);
	printf("size:%d", SizeOfList(head));


	printf("\nEnter a number and an index for new node: ");
	scanf("%d%d", &num, &index);
	head = addToIndex(head, num, index);
	PrintList(head);

	//Targilim 3
	SearchForValue(head);
	SearchForValue(head);


	printf("\nSorted List: ");
	SelectionSort(head);
	PrintList(head);

	//Trgilim 2
	AddInRightOrder(head);
	PrintList(head);
	printf("size:%d", SizeOfList(head));
	
	//Targilim 4
	printf("\nReversed List: ");
	ReverseList(&head);
	PrintList(head);


	printf("\nEnter a value for delete: ");
	scanf("%d", &num);
	head = Delete(head, num);
	PrintList(head);
	printf("size:%d", SizeOfList(head));
	
	
	//Targilim 5
	int sum = SumOfData(head);
	printf("\nSum of list is {%d}", sum);


	//Targilim 6
	int mul = MultyEvenIndex(head);
	printf("\nProduct of even index values is {%d}", mul);

	head = FreeList(head);

	return 0;
}