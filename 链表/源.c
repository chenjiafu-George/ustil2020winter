#include<stdio.h>
#include<stdlib.h>

typedef int Datatype;
typedef struct
{
	Datatype data;
	struct NODE* next;
}NODE;
/*����*/
NODE* CreateLink()
{
	NODE* h = NULL, * p = NULL, * s = NULL;
	p = h = (NODE*)malloc(sizeof(NODE));
	h->next = NULL;             //ָ������Ϊ��
	int len, i = 1;
	printf("�����������С:");
	scanf_s("%d", &len);
	for (; i <= len; i++)
	{
		s = (NODE*)malloc(sizeof(NODE));
		printf("�������%d��Ԫ��:", i);
		scanf_s("%d", &s->data);
		s->next = NULL;
		p->next = s;                 //����ַ
		p = s;                       //ָ��p����ƶ�
	}
	return h;
}
/*����*/
void Traversesqueue(NODE* h)
{
	NODE* p;
	p = h->next;
	printf("����Ϊ:");
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
/*���*/
int Length(NODE* h)
{
	NODE* p;
	p = h->next;           //ͷ��㲻������ ָ���һ�����
	int num = 0;
	while (p != NULL)
	{
		p = p->next;
		num++;
	}
	return (num);
}
/*����*/
int Findelement(NODE* h)
{
	NODE* p;
	p = h->next;         //pָ���һ�����
	int i = 0, len, count = 1;       //count Ϊ������

	printf("��������Ҫ����Ԫ�ص�λ��:");
	scanf_s("%d", &i);

	len = Length(h);
	if (i > len || i < 1)
	{
		printf("����ʧ��! �������޴�Ԫ�ء�\n");
		return (-1);
	}
	while (p != NULL && count < i)
	{
		p = p->next;
		count++;
	}
	printf("���ҳɹ�!��Ԫ��Ϊ:%d\n", p->data);
	return (0);
}
/*����*/
void Insertelement(NODE* h)
{
	NODE* p, * s;
	p = h->next;
	int a, j = 0, i = 0;
	int* len;

	a = Length(h);
	len = &a;
	printf("���������Ԫ�ص�λ��:");
	scanf_s("%d", &i);

	if (i > * len || i < 1)
	{
		printf("�������,����������!");
		exit(-1);
	}
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}

	int value;
	printf("����������Ԫ��:");
	scanf_s("%d", &value);

	s = (NODE*)malloc(sizeof(NODE));      //�����½��
	s->data = value;                  //����
	s->next = p->next;           //����
	p->next = s;
	*len = *len + 1;        //������+1
	printf("�����ɹ�!");
}
/*ɾ��*/
int Deleteelement(NODE* h)
{
	NODE* p, * q = NULL;
	p = h;
	int value, flag = 0;

	printf("��������Ҫɾ����Ԫ��:");
	scanf_s("%d", &value);
	while (p->next != NULL && p->data != value)
	{
		q = p;
		p = p->next;
	}
	if (p->data == value)
	{
		q->next = p->next;
		printf("ɾ����:\n");
		Traversesqueue(h);
		free(p);
		flag = 1;
	}
	if (!flag)
		printf("Error!��������Ԫ�ز��ڷ�������");
	return (h);
}
/*�޸�*/
int Alter(NODE* h)
{
	NODE* p;
	p = h;
	int value, flag = 0, n = 0;

	printf("��������Ҫ�޸ĵ�Ԫ��:");
	scanf_s("%d", &value);
	while (p->next != NULL && p->data != value)
		p = p->next;
	if (p->data == value)
	{
		printf("�޸�Ϊ:");
		scanf_s("%d", &n);
		p->data = n;
		printf("�޸ĳɹ�!\n");
		flag = 1;
	}
	if (!flag)
		printf("Error!����Ҫ�޸ĵ�Ԫ�ز��ڷ�������");
	return (h);
}

int main()
{
	int j, choice;                  //�������ͱ���j��choice 
	NODE* f = 0;           //��ʼ��   

	NODE* list;
	printf("������������!\n");
	list = CreateLink();                //����CreateLink����
	printf("���������!\n");
	system("pause");//��ͣ
	system("cls");//����

	printf("ѡ������Ҫ�Ĳ�����\n");
	printf("1.���� 2.���� 3.ɾ�� 4.���� 5.�޸� 6.�˳�\n");

	while (~scanf_s("%d", &choice))		          //����ѡ��Ĳ���
	{
		switch (choice)
		{
		case 1:
		{
			Traversesqueue(list);               //����
			break;
		}
		case 2:
		{
			Insertelement(list);                //����
			break;
		}
		case 3:
		{
			Deleteelement(list);              //����deleteelment���� 
			break;
		}
		case 4:
		{
			Findelement(list);                //����Findelement���� ��list�� 
			break;
		}
		case 5:
		{
			Alter(list);                      //����Alter����
			break;
		}
		case 6:
			printf("ллʹ��\n");
			exit(0);
			break;
		default:
			printf("�������!����������\n");
			break;
		}
		system("pause");                 //��ͣ 
		system("cls");					//���� 
		printf("ѡ������Ҫ�Ĳ�����\n");
		printf("1.���� 2.���� 3.ɾ�� 4.���� 5.�޸� 6.�˳�\n");

	}
	return 0;
}