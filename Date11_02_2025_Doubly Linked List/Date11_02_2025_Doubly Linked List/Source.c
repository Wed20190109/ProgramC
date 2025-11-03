#include "DoublyLinkedList.h"
void SimpleTest()
{
	node *a=NULL;
	DLLInit(&a);
	DLLPushBack(a, 1);
	DLLPushFront(a, 2);
	DLLPrint(a);

}

int main()
{
	SimpleTest();
	return 0;
}