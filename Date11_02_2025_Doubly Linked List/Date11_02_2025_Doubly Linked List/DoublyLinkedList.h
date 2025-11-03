#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct NODE {
	DataType data;
	struct NODE* prev;
	struct NODE* next;
}node;


node* CreateNode(DataType x);
void* DLLInit(node** head);
void DLLPrint(node* head);
void* DLLPushFront(node* head, DataType toinsert);
void* DLLPopFront(node* head);
void* DLLPushBack(node* head, DataType toinsert);
void* DLLPopBack(node* head);

