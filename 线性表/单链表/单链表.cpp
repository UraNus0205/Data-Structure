#include <iostream>
#include<cstdlib>
#include<stdio.h>
using namespace std;

typedef int ElemType;


/*
struct LNode{
	ElemTyoe data;
	struct LNode *next;
};
typedef struct LNode LNode;//强调结点
tyoedef struct LNode *LinkList;//强调链表
*/

typedef struct LNode {
	ElemType data;//每个节点存放一个数据元素
	struct LNode* next;
}LNode,*LinkList;

bool InitList1(LinkList& L);//初始化一个不带头节点的单链表
bool InitList2(LinkList& L);//初始化一个带头结点的单链表
bool ListInsert1(LinkList& L, int i, ElemType e);//按位序插入(带头结点)
bool ListInsert2(LinkList& L, int i, ElemType e);//按位序插入(不带头结点)
bool InsertNextNode(LNode* p, ElemType e);//后插操作,在p节点后插入元素e
bool InsertPriorNode1(LNode* p, ElemType e);//前插操作,在p节点之前插入元素e
bool InsertPriorNode2(LNode* p, LNode* s);//前插操作,在p节点之前插入节点s
bool ListDelete(LinkList& L, int i, ElemType& e);//带头节点的按位序删除节点
bool DeleteNode(LNode* p);//删除指定结点p
LNode* GetElem(LinkList L, int i);//带头节点按位查找,查询第i个结点
LNode* LocateElem(LinkList L, ElemType e);//带头节点按值查找，找到数据域等于e的结点
int Length(LinkList L);
bool Empty(LinkList L);
LinkList List_TailInsert(LinkList& L);//带头节点尾插法建立单链表
LinkList List_HeadInsert(LinkList& L);//带头节点头插法建立单链表



int main()
{
	LinkList L;
	InitList2(L);
	List_HeadInsert(L);
	cout << "链表长度为：" << Length(L) << endl;
	return 0;
}

LNode* GetElem(LinkList L, int i)//带头节点按位查找,查询第i个结点
{
	int j = 0;
	LNode* p = L;
	if (i < 0)
	{
		printf("查询失败\n");
		return NULL;
	}
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	printf("查询成功\n");
	return p;
}

LNode* LocateElem(LinkList L, ElemType e)//带头节点按值查找，找到数据域等于e的结点
{
	LNode* p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	printf("查找完毕\n");
	return p;
}


bool InitList1(LinkList& L)//初始化一个不带头节点的单链表
{
	L = NULL;
	printf("链表创建成功(不带头结点)\n");
	return true;
}

bool InitList2(LinkList& L)//初始化一个带头结点的单链表
{
	L = (LNode*)malloc(sizeof(LNode));//分配一个头结点
	if (L == NULL)//内存不足，分配失败
	{
		printf("内存不足，分配失败\n");
		return false;
	}
	L->next = NULL;
	printf("链表创建成功(带头结点)\n");
	return true;
}

bool InsertNextNode(LNode* p, ElemType e)//后插操作,在p节点后插入元素e
{
	if (p == NULL)
	{
		printf("节点错误\n");
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
	{
		printf("内存不足\n");
		return false;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	printf("元素%d已成功插入\n", e);
	return true;
}


bool ListInsert1(LinkList& L, int i, ElemType e)//按位序插入(带头结点)
{
	LNode* p = GetElem(L, i - 1);
	return InsertNextNode(p, e);
}

bool ListInsert2(LinkList& L, int i, ElemType e)//按位序插入(不带头结点)
{
	if (i < 1)
	{
		printf("i值不合法\n");
		return false;
	}
	if (i == 1)
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s;
		printf("插入成功\n");
		return true;
	}
	int j = 1;
	LNode* p = L;
	if (i < 0)
	{
		printf("查询失败\n");
		return NULL;
	}
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	return InsertNextNode(p, e);
}


bool InsertPriorNode1(LNode* p, ElemType e)//前插操作,在p节点之前插入元素e
{
	if (p == NULL)
	{
		printf("节点错误\n");
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
	{
		printf("内存不足\n");
		return false;
	}
	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;
	printf("元素%d已成功插入\n", e);
	return true;
}

bool InsertPriorNode2(LNode* p, LNode* s)//前插操作,在p节点之前插入节点s
{
	if (p == NULL || s == NULL)
	{
		printf("节点错误\n");
		return false;
	}

	s->next = p->next;
	p->next = s;
	ElemType temp = p->data;
	p->data = s->data;
	s->data = temp;
	printf("节点s已成功插入\n");
	return true;
}

bool ListDelete(LinkList& L, int i, ElemType& e)//带头节点的按位序删除节点
{
	LNode* p = GetElem(L, i - 1);
	if (p == NULL)
	{
		printf("i值不合法\n");
		return false;
	}
	if (p->next == NULL)
	{
		printf("无该节点\n");
	}
	LNode* q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	printf("第%d个元素%d删除成功\n", i, e);
	return true;
}

bool DeleteNode(LNode* p)//删除指定结点p
{
	if (p == NULL)
	{
		printf("节点为空\n");
		return false;
	}
	p->data = p->next->data;//若p为最后一个节点，则会出错
	p->next = p->next->next;
	printf("结点q删除成功\n");
	return true;
}


int Length(LinkList L)
{
	int len = 0;
	LNode* p = L;
	while (p->next != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}

bool Empty(LinkList L)//判断链表是否为空
{
	return (L == NULL);
}

LinkList List_TailInsert(LinkList& L)//带头节点尾插法建立单链表
{
	ElemType x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode* s, * r = L;
	cin >> x;
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		cin >> x;
	}
	L->next = NULL;
	printf("尾插法建立单链表完毕\n");
	return L;
}

LinkList List_HeadInsert(LinkList& L)//带头节点头插法建立单链表
{
	ElemType x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode* s, * r = L;
	L->next = NULL;
	cin >> x;
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = r->next;
		r->next = s;
		cin >> x;
	}
	printf("头插法建立单链表完毕\n");
	return L;
}



