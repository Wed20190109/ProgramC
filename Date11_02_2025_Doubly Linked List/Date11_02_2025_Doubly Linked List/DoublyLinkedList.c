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
	node* tail = head->prev;
	/*newnode->prev = tail;
		newnode->next = head;
	tail->next = newnode;
	newnode -> prev = tail;*///It is wrong to write like this
	tail->next = newnode;
	newnode->prev = tail;
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
	while (cur!= head)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

node* DLLFind(node*head,DataType tofind)
{
	assert(head != NULL);
	node* cur = head->next;
	while (cur != head)
	{
		if (cur->data == tofind)
		{
			printf("Found %d\n", tofind);
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void DLLInsertAfter(node*pos,DataType toinsert)//若要插入的位置在最末尾，不能直接套用尾插
{
	node* newnode = CreateNode(toinsert);
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;
}

void DLLErase(node* pos)
{
	assert(pos != NULL);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;

}
void DLLDestroy(node*head)
{
	node* cur = head->next;
	while (cur != head)
	{
		node* next = cur->next;
		free(cur);
		cur = next;
	}
	free(head);
	head = NULL;
}