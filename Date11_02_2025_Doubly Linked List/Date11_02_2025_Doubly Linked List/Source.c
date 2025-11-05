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


/*牛客网约瑟夫环问题代码
typedef struct Node{
int val;
 struct Node*next;
}node;

node * createnode(int x)
{
node * newnode=(node*)malloc( sizeof(node));
if(newnode==NULL)
{
	perror("malloc");
	exit(0);
}
newnode->val=x;
newnode->next=NULL;
return newnode;
}

node *createcircle(int n)
{
	node * head=createnode(1);
	node*tail=head;
	for(int i=2;i<=n;i++)
	{
		tail->next=createnode(i);
		tail=tail->next;
	}
	tail->next=head;
	return tail;
}

int ysf(int n, int m ) {
	// write code here


node*prev=createcircle(n);
node *cur=prev->next;
int count=1;
while(cur->next!=cur)
{
	if(count==m)
	{
	   prev->next=cur->next;
		free(cur);
	 cur=prev->next;
	 count=1;
	}
	else
	{
prev=cur;
cur=cur->next;
count++;
	}
}
return cur->val;
}
*/