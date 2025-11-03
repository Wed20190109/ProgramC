#include "DoublyLinkedList.h"

node* CreateNode(DataType x)
{
	node* newnode = (node*)malloc(sizeof(node));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;//Return the 
}

void *DLLInit(node**head)//哨兵位初始化，在这里创建
{
	*head = CreateNode(-1);
	(*head)->next = *head; 
	(*head)->prev = *head;
}

void* DLLPushBack(node* head, DataType toinsert)
{
	node* newnode = CreateNode(toinsert);

	node* cur = head;
	while (cur->next != cur)
	{
		cur = cur->next;
	}
	cur->next = newnode;
	newnode->prev = cur;
	newnode->next = head;
	head->prev = newnode;

}

void* DLLPopBack(node* head)
{
	assert(head != NULL && head->next != NULL);
	node* tail = head->prev;
	head->prev = tail->prev;
	tail->prev->next = head;
	free(tail);
	tail = NULL;
}

void* DLLPushFront(node* head, DataType toinsert)//在哨兵位前插入相当于尾插
{
	node* newnode = CreateNode(toinsert);
	newnode->next = head->next;
	newnode->prev = head;
	head->next->prev = newnode;
	head->next = newnode;
}

void* DLLPopFront(node* head)
{
	assert(head != NULL);
	node* first = head->next;
	first->next->prev = head;
	head->next = first->next;
	free(first);
	first = NULL;
}
void DLLPrint(node* head)
{
	assert(head != NULL);
	node* cur = head->next;
	while (cur->next != head)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}