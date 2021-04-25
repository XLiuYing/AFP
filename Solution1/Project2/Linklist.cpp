// Linklist.cpp : 定义控制台应用程序的入口点。

#include <stdio.h>
#include <malloc.h>

typedef char ElemType;
typedef struct LNode {
	ElemType data; //数据域
	struct LNode* next; //指向后继结点
}LinkNode; // 声明单链表结点类型

		   /*------------------------尾插法建立单链表---------------------------*/
static void create_list_rear(LinkNode*& L, ElemType a[], int n)// 指针的引用
{
	LinkNode* s, * r;

	L = (LinkNode*)malloc(sizeof(LinkNode)); // 创建头结点
	L->next = NULL;
	r = L; // r始终指向尾结点，开始时指向头结点

	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode)); // 创建新结点s
		s->data = a[i];
		r->next = s; // 将结点s插入r结点之后
		r = s;
	}
	r->next = NULL; // 尾结点next域置为NULL
}

/*------------------------输出线性表---------------------------*/
static void display_list(LinkNode* L)
{
	LinkNode* p = L->next; // p指向首结点

	while (p != NULL)
	{
		printf("%c ", p->data); // p不为NULL,输出p结点的数据域
		p = p->next;// p移向下一个结点
	}
	printf("\n");
}

/*------------------------销毁线性表---------------------------*/
static void destroy_list(LinkNode*& L)
{
	LinkNode* pre = L, * p = pre->next;

	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next; // pre、p 同步后移一个结点
	}
	free(pre); // 此时p为NULL,pre指向尾结点,释放它
}

static void reverse_list(LinkNode* p, LinkNode*& L)
{
	if (p->next == NULL) // 以p为首结点指针的单链表只有一个结点时
	{
		L->next = p; // p结点变为尾结点
		return;
	}
	reverse_list(p->next, L);
	p->next->next = p; // 将结点链接在尾结点之后
	p->next = NULL; // 尾结点next域置为NULL
}

int main()
{
	LinkNode* L;
	char a[] = "12345678";
	int n = 8;

	create_list_rear(L, a, n);
	printf("L:");
	display_list(L);
	printf("逆置L\n");
	reverse_list(L->next, L);
	printf("L:");
	display_list(L);
	destroy_list(L);

	return 0;
}