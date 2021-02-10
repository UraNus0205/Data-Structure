#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*Linklist;

bool InitList(Linklist& L)
{
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
		return false;
	L->next = L;
	return true;
}

bool Empty(Linklist L)
{
	return (L->next == L);
}

bool isTail(Linklist L, LNode* p)//判断节点p是否为循环单链表的表尾结点
{
	if (p->next == L)
		return true;
	else
		return false;
}
int main()
{
	return 0;
}

