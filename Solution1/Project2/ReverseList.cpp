

/*------------------------逆置带头结点的单链表L---------------------------*/
/**
*   算法思路
*   reverse_list(p, L)算法的思路是:
*       逆置以p为首结点指针的单链表(不带头结点)，逆置后p指向尾结点,它是"大问题"；
*   reverse_list(p->next, L)是"小问题"，用于逆置以p->next为首结点指针的单链表，逆
*       置后p->next指向尾结点。
*   递归模型如下:
*   1、reverse_list(p, L) => L->next = p   以p为首结点指针的单链表只有一个结点时
*   2、reverse_list(p, L) => reverse_list(p->next, L) 其他情况
*   p->next->next = p;(将结点链接在尾结点之后)
*   p->next = NULL;(尾结点next域置为NULL)
*/
