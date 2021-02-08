#include <iostream>
#include <cstdlib>
using namespace std;
typedef int ElemType;
const int MaxSize1 = 100;
const int InitSize = 10;//动态顺序表的默认最大长度

typedef struct {//静态分配
	ElemType data[MaxSize1];
	int length;
}SqList;
typedef struct {//动态分配
	ElemType* data;
	int length;
	int MaxSize2;
}SeqList;

void InitList1(SqList& L);
bool ListInsert1(SqList& L, int i, ElemType e);//在第i个位置插入元素e
bool ListDelete1(SqList& L, int i, ElemType& e);//删除第i个位置的元素存入e中
ElemType GetElem1(SqList L, int i);//按位查找操作，返回第i个位置的元素
int LocateElem1(SqList L, ElemType e);//按值查找操作，在L中查找第一个元素值等于e的元素，返回其位序

void InitList2(SeqList& L);//初始化动态顺序表
void IncreaseSize2(SeqList& L, int len);//增加动态数组的长度
ElemType GetElem2(SeqList L, int i);//按位查找操作，返回第i个位置的元素
int LocateElem2(SeqList L, ElemType e);//按值查找操作，在L中查找第一个元素值等于e的元素，返回其位序




int main()
{
	SqList L1;
	SeqList L2;
	InitList1(L1);
	InitList2(L2);

	ListInsert1(L1, 1, 5);
	ListInsert1(L1, 1, 6);
	ListInsert1(L1, 2, 7);
	ListInsert1(L1, 2, 8);
	for (int i = 1; i <= L1.length; i++)//6875
	{
		printf("%d\n", GetElem1(L1, i));
	}
	int e;
	ListDelete1(L1, 1, e);
	printf("e=%d\n", e);
	int value = 5;
	int index = LocateElem1(L1, value);
	printf("%d的位序为：%d\n", value, index);
	return 0;
}


void InitList1(SqList &L)//初始化静态顺序表
{
	for (int i = 0; i < L.length; i++)
		L.data[i] = 0;
	L.length = 0;
}

 bool ListInsert1(SqList& L, int i, ElemType e)//在第i个位置插入元素e
{
	 if (i<1 || i>L.length + 1)
	 {
		 printf("插入位置错误\n");
		 return false;
	 }
	 if (i >= MaxSize1)
	 {
		 printf("存储空间已满\n");
		 return false;
	 }
	 for (int j = L.length; j >= i; j--)
	 {
		 L.data[j] = L.data[j - 1];
	 }
	 L.data[i - 1] = e;
	 L.length++;
	 printf("插入元素%d成功，此时表长为：%d\n", e, L.length);
	 return true;
}

bool ListDelete1(SqList &L, int i, ElemType &e)//删除第i个位置的元素存入e中
{
	if (i<1 || i>L.length)
	{
		printf("删除位置错误\n");
	}
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	printf("删除%d元素成功，此时表长为：%d\n", e, L.length);
	return true;
}

ElemType GetElem1(SqList L, int i)//按位查找操作，返回第i个位置的元素
{
	return L.data[i - 1];
}

int LocateElem1(SqList L, ElemType e)//按值查找操作，在L中查找第一个元素值等于e的元素，返回其位序
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			printf("查找元素%d成功\n", e);
			return i + 1;
		}
	}
	printf("查找元素%d失败\n", e);
	return 0;//查找失败
}

void InitList2(SeqList& L)//初始化动态顺序表
{
	L.data = (ElemType*)malloc(InitSize * sizeof(ElemType));
	if (!L.data)
	{
		printf("初始化失败\n");
		exit(0);
	}
	printf("初始化动态顺序表成功\n");
	L.length = 0;
	L.MaxSize2 = InitSize;
}

void IncreaseSize2(SeqList& L, int len)//增加动态数组的长度
{
	int* p = L.data;
	L.data = (ElemType*)malloc((L.MaxSize2 + len) * sizeof(ElemType));
	for (int i = 0; i < L.length; i++)
	{
		L.data[i] = p[i];
	}
	L.MaxSize2 = L.MaxSize2 + len;
	free(p);
}

ElemType GetElem2(SeqList L, int i)//按位查找操作，返回第i个位置的元素
{
	return L.data[i - 1];
}

int LocateElem2(SeqList L, ElemType e)//按值查找操作，在L中查找第一个元素值等于e的元素，返回其位序
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			printf("查找元素%d成功\n",e);
			return i + 1;
		}
	}
	printf("查找元素%d失败\n",e);
	return 0;//查找失败
}

