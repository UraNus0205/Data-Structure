#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct DNode {
	ElemType data;
	struct DNode* prior, * next;
}DNode,*DLinklist;

bool InitDLinkList(DLinklist& L)//带头节点
{
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)
	{
		printf("内存不足，分配失败");
		return false;
	}
	L->prior = NULL;
	L->next = NULL;
	return true;
}

bool Empty(DLinklist L)
{
	return (L->next == NULL);
}

bool InsertNextDNode(DNode* p, DNode* s)//将节点*s插入到节点*p之后
{
	if (p == NULL || s == NULL)
		return false;
	s->next = p->next;
	if(p->next!=NULL)
		p->next->prior = s;
	s->prior = p;
	p->next = s;
}

bool DeleteNextDNode(DNode* p)//删除p节点的后继节点
{
	if (p == NULL) return false;
	DNode* q = p->next;
	if (q == NULL) return false;//p没有后继
	p->next = q->next;
	if (q->next != NULL)
		q->next->prior = p;
	free(q);
	return true;
}

void DestroyList(DLinklist& L)
{
	while (L->next != NULL)
	{
		DeleteNextDNode(L);
	}
	free(L);
	L = NULL;
}

int main()
{
	return 0;
}


