#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20//存储空间初始化
typedef int ElementType;
typedef struct LNode* list;
typedef struct LNode {
	ElementType Data[MAXSIZE];
	int last;//last是最后一个元素的下标；
}Sqlist;



list MakeEmpty();//初始化线性表
ElementType FindKth(int K,list L);//根据位序K，返回相应的元素；
int Find(ElementType X,list L);//找到元素所在的位置（第一次出现）
void insert(ElementType X, int i, list L);//根据位序i，在i前插入一个元素
void Delete(int i, list L);//找到位序i的元素并且进行删除操作
int Length(list L);
void Myprintf(list Ptrl);


//建立一个空的顺序表
list MakeEmpty()
{
	list Ptrl;
	Ptrl = (list)malloc(sizeof(Sqlist));
	Ptrl->last = -1;
	return Ptrl;
}

//查找
int Find(ElementType X, list Ptrl)
{
	int i = 0;
	while (i <= Ptrl->last && Ptrl->Data[i] != X)
	{
		i++;
	}
	if (i > Ptrl->last) return -1;
	else return i;
}


ElementType FindKth(int K, list Ptrl)
{
	if (K < 0 && Ptrl->last < K)
	{
		return 0;
	}
	else return Ptrl->Data[K];
}


void insert(ElementType X, int i, list Ptrl)
{
	int j;
	
	if (Ptrl->last == MAXSIZE) {       //判断一下表是否满
		printf("full");
		return;
	}
	if (i<1 || i>Ptrl->last + 2)      //检查是否可被插入
	{
		printf("位置不合法");
		return;
	}
	for (j = Ptrl->last; j >= i - 1; j--)//关于i以及以后的元素全部都往后挪一位
	{
		Ptrl->Data[j + 1] = Ptrl->Data[j];
	}

	Ptrl->Data[i - 1] = X;
	Ptrl->last++;
}


void Delete(int i, list Ptrl)
{
	int j;
	if (i < 1 || i>Ptrl->last) {
		printf("error");
		return;
	}
	for (j = i; j < Ptrl->last; j++) {
		Ptrl->Data[j - 1] = Ptrl->Data[j];
	}
	Ptrl->last--;
	return;
}


void Myprintf(list Ptrl)
{
	if (Ptrl->last == -1) {
		printf("表空");
		return;
	}
	int i = 0;

	while (Ptrl->last != -1)
	{
		printf("\t%d\n", Ptrl->Data[i]);
		i++;
		Ptrl->last--;
	}
}

void write(list Ptrl)
{
	int n;
	printf("请输入你想要填入的数据个数\n");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		if (Ptrl->last == MAXSIZE-1) {
			printf("表已满");
			return;
		}
		printf("请输入你的数据");
		scanf("%d", &Ptrl->Data[i]);
		Ptrl->last++;
	}

}

int main()
{
	list Ptrl = MakeEmpty();


	write(Ptrl);


	//Myprintf(Ptrl);
	int a;
	int K,X;
	printf("请问你需要什么操作：1.查找 2.插入 3.删除");
	scanf("%d", &a);
	switch (a)
	{
	case 1:printf("输入想要查找的序号（下标）");
		scanf("%d", &K);
		printf("%d", FindKth(K, Ptrl)); break;
	case 2:printf("请输入你想要插入第几个的前面");
		scanf("%d", &K);
		printf("请输入你想要插入的元素");
		scanf("%d", &X);
		insert(X, K, Ptrl); break;
	case 3:printf("请输入你想要删除的序号");
		scanf("%d", &K);
		Delete(K, Ptrl);
	default:
		break;
	}

	Myprintf(Ptrl);

	return 0;
}