#include "DoublyLinkedList.h"
void SimpleTest()
{
	node *a=NULL;
	DLLInit(&a);

	DLLPushBack(a, 1);
	DLLPushFront(a, 2);
	DLLPushFront(a, 3);
	DLLPushFront(a, 4);
	DLLPushFront(a, 5);
	DLLPushFront(a, 6);
	DLLPushBack(a, 0);
	DLLPushBack(a, -1);
	printf("After pushing:\n");
	DLLPrint(a);
	DLLPopFront(a);
	DLLPrint(a);
	DLLPopFront(a);
	DLLPrint(a);
	DLLPopBack(a);
	node* find = DLLFind(a, 4);
	DLLInsertAfter(find, 100);
	
	DLLPrint(a);
	node* find2 = DLLFind(a, 1);
	DLLErase(find2);
	DLLPrint(a);

}

int main()
{
	SimpleTest();
	return 0;
}