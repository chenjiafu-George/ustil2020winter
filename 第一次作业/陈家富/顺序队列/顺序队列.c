#include<stdio.h>
#include<stdlib.h>
#define MAXIMUM 100

typedef int Datatype;

/*创建队列*/
void Createsqueue(Datatype* squeue)
{
	int value, len;
	printf("请输入队列大小:");
	scanf_s("%d", &len);
	for (int count = 0; count < len; count++)
	{
		printf("队列的第%d个元素:", count + 1);
		scanf_s("%d", &value);
		squeue[count] = value;
	}
	printf("创建成功!\n");
}
/*遍历*/
void Traversesqueue(Datatype* squeue)
{
	int count = 0, len;
	len = Lengthsqueue(squeue);
	printf("队列为:");
	for (; count < len; count++)
		printf("%d ", squeue[count]);
	printf("\n");
}
/*查找*/
int Findsqueue(Datatype* squeue)
{
	int count = 0, len, x;
	len = Lengthsqueue(squeue);    //求队列大小
	printf("请输入查找的元素:");
	scanf_s("%d", &x);
	while (squeue[count] != x && count < len)   //判断数组中是否能找到
		count++;
	if (count == len)					//未找到
		printf("查找失败!队列中无此元素!\n");
	else							    //返回元素的相对位置
		printf("查找成功!\n在队列中的位置为:%d", count + 1);
}
/*修改*/
void Altersqueue(Datatype* squeue)
{
	int count = 0, len, x, value;
	len = Lengthsqueue(squeue);    //求队列大小

	printf("请输入修改的元素:");
	scanf_s("%d", &x);
	printf("请输入想要修改为:");
	scanf_s("%d", &value);

	while (squeue[count] != x && count < len)   //判断数组中是否能找到
		count++;
	if (count == len)					//未找到
		printf("数组中无此元素,无法修改!\n");
	else							    //返回元素的相对位置
	{
		squeue[count] = value;
		printf("修改成功!\n");
	}
}
/*增加*/
void Insertsqueue(Datatype* squeue)
{
	int a, count, x, i;
	int* len;

	a = Lengthsqueue(squeue);
	len = &a;
	printf("请输入插入元素的位置:");
	scanf_s("%d", &i);
	printf("请输入插入的元素:");
	scanf_s("%d", &x);

	if (i > * len || i < 0)
		printf("数据溢出,无法增加,请扩充容量!");
	if (i == *len)
		squeue[i] = x;
	else
	{
		for (count = *len - 1; count >= i; count--)
			squeue[count + 1] = squeue[count];
		squeue[i] = x;
	}
	*len = *len + 1;
	printf("插入成功!\n");
}
/*删除*/
void Deletesqueue(Datatype* squeue)
{
	int Loc, count = 0, x, a;
	printf("请输入想要删除的元素:");
	scanf_s("%d", &x);
	int* len;

	a = Lengthsqueue(squeue);
	len = &a;
	while (squeue[count] != x && count < *len)
		count++;
	if (count == *len)
		printf("队列中没有此元素!\n");
	else
	{
		Loc = count;			//找到，记录它在队列的位置
		for (count = Loc; count < *len; count++)
			squeue[count] = squeue[count + 1];
		*len = *len - 1;
		printf("已删除!在原队列第%d位\n", Loc + 1);
	}
}
/*队列长度*/
int Lengthsqueue(Datatype* squeue)
{
	int i = 0, length = 0;
	while (squeue[i] != 0)
	{
		length++;
		i++;
	}
	return (length);
}

int main()
{
	Datatype squeue[MAXIMUM] = { 0 };
	int input;
	printf("即将创建队列!\n");
	Createsqueue(squeue);                //调用CreateLink函数
	printf("队列创建完成!\n");
	system("pause");//暂停
	system("cls");//清屏

	printf("选择你需要的操作：\n");
	printf("1.遍历 2.增加 3.删除 4.查找 5.修改 6.退出\n");
	while (1)
	{
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			Traversesqueue(squeue);
			break;
		case 2:
			Insertsqueue(squeue);
			break;
		case 3:
			Deletesqueue(squeue);
			break;
		case 4:
			Findsqueue(squeue);
			break;
		case 5:
			Altersqueue(squeue);
			break;
		case 6:
			printf("谢谢使用\n");
			exit(0);
			break;
		default:
			printf("input error!\n");
			break;
		}
		system("pause");                 //暂停 
		system("cls");					//清屏 
		printf("选择你需要的操作：\n");
		printf("1.遍历 2.增加 3.删除 4.查找 5.修改 6.退出\n");
	}
	return 0;
}