#include<stdio.h>
#include<stdlib.h>

typedef int Datatype;
typedef struct node           //循环链表存储结构
{
	Datatype data;       //数据域
	struct node* next;        //指针域

}CNODE;
/*创建*/
CNODE* Createcirlink()
{
	CNODE* h = NULL, * p = NULL, * s = NULL;
	p = h = (CNODE*)malloc(sizeof(CNODE));
	h->next = NULL;             //指针域置为空
	int len, i = 1;
	printf("请输入链表大小:");
	scanf_s("%d", &len);
	for (; i <= len; i++)
	{
		s = (CNODE*)malloc(sizeof(CNODE));
		printf("请输入第%d个元素:", i);
		scanf_s("%d", &s->data);
		s->next = NULL;
		p->next = s;                 //传地址
		p = s;                       //指针p向后移动
	}
	p->next = h;            //尾结点指向头结点
	return h;
}
/*遍历*/
void Traversecirlink(CNODE* h)
{
	CNODE* p;
	p = h->next;
	printf("遍历为:");
	while (p != h)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
/*求循环表长*/
int Length(CNODE* h)
{
	CNODE* p;
	p = h->next;           //头结点不存数据 指向第一个结点
	int num = 0;
	while (p != h)
	{
		p = p->next;
		num++;
	}
	return (num);
}
/*查找*/
void Findelement(CNODE* h)
{
	CNODE* p;
	p = h->next;
	int num = 1, e, i;

	printf("请输入想要查找元素的位置:");
	scanf_s("%d", &i);
	while (p != h && num < i)
	{
		p = p->next;
		num++;
	}
	if (p == h)
	{
		printf("Error！您搜索的元素不在服务区内!");
		exit(-1);
	}
	else
		printf("查找成功!\n该元素为:%d", p->data);
}
/*插入*/
void Insertelement(CNODE* h)
{
	CNODE* p, * s;
	p = h->next;
	int a, j = 0, i = 0;
	int* len;

	a = Length(h);
	len = &a;
	printf("请输入插入元素的位置:");
	scanf_s("%d", &i);

	if (i > * len || i < 1)
	{
		printf("数据溢出,请扩充容量!");
		exit(-1);
	}
	while (p != h && j < i - 1)
	{
		p = p->next;
		j++;
	}

	int value;
	printf("请输入插入的元素:");
	scanf_s("%d", &value);

	s = (CNODE*)malloc(sizeof(CNODE));      //创建新结点
	s->data = value;                  //插入
	s->next = p->next;           //连接
	p->next = s;
	*len = *len + 1;        //链表长度+1
	printf("操作成功!");
}
/*删除*/
void Deleteelement(CNODE* h)
{
	CNODE* p, * q = NULL;
	p = h;
	int value, flag = 0;

	printf("请输入想要删除的元素:");
	scanf_s("%d", &value);
	while (p->next != h && p->data != value)
	{
		q = p;
		p = p->next;
	}
	if (p->data == value)
	{
		q->next = p->next;
		printf("删除后:\n");
		Traversecirlink(h);
		free(p);
		flag = 1;
	}
	if (!flag)
		printf("Error!您搜索的元素不在服务区！");
	return (h);
}

/*修改*/
int Alter(CNODE* h)
{
	CNODE* p;
	p = h;
	int value, flag = 0, n = 0;

	printf("请输入想要修改的元素:");
	scanf_s("%d", &value);
	while (p->next != h && p->data != value)
		p = p->next;
	if (p->data == value)
	{
		printf("修改为:");
		scanf_s("%d", &n);
		p->data = n;
		printf("修改成功!\n");
		flag = 1;
	}
	if (!flag)
		printf("Error!您想要修改的元素不在服务区！");
	return (h);
}

int main()
{
	int j, choice;                  //定义整型变量j，choice 
	CNODE* f = 0;           //初始化   

	CNODE* cirlist;
	printf("即将创建循环链表!\n");
	cirlist = Createcirlink();                //调用CreateLink函数
	printf("循环链表创建完成!\n");
	system("pause");//暂停
	system("cls");//清屏

	printf("选择你需要的操作：\n");
	printf("1.遍历 2.增加 3.删除 4.查找 5.修改 6.退出\n");

	while (~scanf_s("%d", &choice))		          //输入选择的操作
	{
		switch (choice)
		{
		case 1:
		{
			Traversecirlink(cirlist);               //调用
			break;
		}
		case 2:
		{
			Insertelement(cirlist);                //调用
			break;
		}
		case 3:
		{
			Deleteelement(cirlist);              //调用deleteelment函数 
			break;
		}
		case 4:
		{
			Findelement(cirlist);                //调用Findelement函数 在list中 
			break;
		}
		case 5:
		{
			Alter(cirlist);                      //调用Alter函数
			break;
		}
		case 6:
			printf("谢谢使用\n");
			exit(0);
			break;
		default:
			printf("输入错误!请重新输入\n");
			break;
		}
		system("pause");                 //暂停 
		system("cls");					//清屏 
		printf("选择你需要的操作：\n");
		printf("1.遍历 2.增加 3.删除 4.查找 5.修改 6.退出\n");

	}
	return 0;
}