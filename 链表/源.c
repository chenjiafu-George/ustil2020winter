#include<stdio.h>
#include<stdlib.h>

typedef int Datatype;
typedef struct
{
	Datatype data;
	struct NODE* next;
}NODE;
/*创建*/
NODE* CreateLink()
{
	NODE* h = NULL, * p = NULL, * s = NULL;
	p = h = (NODE*)malloc(sizeof(NODE));
	h->next = NULL;             //指针域置为空
	int len, i = 1;
	printf("请输入链表大小:");
	scanf_s("%d", &len);
	for (; i <= len; i++)
	{
		s = (NODE*)malloc(sizeof(NODE));
		printf("请输入第%d个元素:", i);
		scanf_s("%d", &s->data);
		s->next = NULL;
		p->next = s;                 //传地址
		p = s;                       //指针p向后移动
	}
	return h;
}
/*遍历*/
void Traversesqueue(NODE* h)
{
	NODE* p;
	p = h->next;
	printf("遍历为:");
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
/*求表长*/
int Length(NODE* h)
{
	NODE* p;
	p = h->next;           //头结点不存数据 指向第一个结点
	int num = 0;
	while (p != NULL)
	{
		p = p->next;
		num++;
	}
	return (num);
}
/*查找*/
int Findelement(NODE* h)
{
	NODE* p;
	p = h->next;         //p指向第一个结点
	int i = 0, len, count = 1;       //count 为计数器

	printf("请输入想要查找元素的位置:");
	scanf_s("%d", &i);

	len = Length(h);
	if (i > len || i < 1)
	{
		printf("查找失败! 数组中无此元素。\n");
		return (-1);
	}
	while (p != NULL && count < i)
	{
		p = p->next;
		count++;
	}
	printf("查找成功!该元素为:%d\n", p->data);
	return (0);
}
/*增加*/
void Insertelement(NODE* h)
{
	NODE* p, * s;
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
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}

	int value;
	printf("请输入插入的元素:");
	scanf_s("%d", &value);

	s = (NODE*)malloc(sizeof(NODE));      //创建新结点
	s->data = value;                  //插入
	s->next = p->next;           //连接
	p->next = s;
	*len = *len + 1;        //链表长度+1
	printf("操作成功!");
}
/*删除*/
int Deleteelement(NODE* h)
{
	NODE* p, * q = NULL;
	p = h;
	int value, flag = 0;

	printf("请输入想要删除的元素:");
	scanf_s("%d", &value);
	while (p->next != NULL && p->data != value)
	{
		q = p;
		p = p->next;
	}
	if (p->data == value)
	{
		q->next = p->next;
		printf("删除后:\n");
		Traversesqueue(h);
		free(p);
		flag = 1;
	}
	if (!flag)
		printf("Error!您搜索的元素不在服务区！");
	return (h);
}
/*修改*/
int Alter(NODE* h)
{
	NODE* p;
	p = h;
	int value, flag = 0, n = 0;

	printf("请输入想要修改的元素:");
	scanf_s("%d", &value);
	while (p->next != NULL && p->data != value)
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
	NODE* f = 0;           //初始化   

	NODE* list;
	printf("即将创建链表!\n");
	list = CreateLink();                //调用CreateLink函数
	printf("链表创建完成!\n");
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
			Traversesqueue(list);               //调用
			break;
		}
		case 2:
		{
			Insertelement(list);                //调用
			break;
		}
		case 3:
		{
			Deleteelement(list);              //调用deleteelment函数 
			break;
		}
		case 4:
		{
			Findelement(list);                //调用Findelement函数 在list中 
			break;
		}
		case 5:
		{
			Alter(list);                      //调用Alter函数
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