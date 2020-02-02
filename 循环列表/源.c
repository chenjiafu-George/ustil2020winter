#include<stdio.h>
#include<stdlib.h>

typedef int Datatype;
typedef struct node           //ѭ������洢�ṹ
{
	Datatype data;       //������
	struct node* next;        //ָ����

}CNODE;
/*����*/
CNODE* Createcirlink()
{
	CNODE* h = NULL, * p = NULL, * s = NULL;
	p = h = (CNODE*)malloc(sizeof(CNODE));
	h->next = NULL;             //ָ������Ϊ��
	int len, i = 1;
	printf("�����������С:");
	scanf_s("%d", &len);
	for (; i <= len; i++)
	{
		s = (CNODE*)malloc(sizeof(CNODE));
		printf("�������%d��Ԫ��:", i);
		scanf_s("%d", &s->data);
		s->next = NULL;
		p->next = s;                 //����ַ
		p = s;                       //ָ��p����ƶ�
	}
	p->next = h;            //β���ָ��ͷ���
	return h;
}
/*����*/
void Traversecirlink(CNODE* h)
{
	CNODE* p;
	p = h->next;
	printf("����Ϊ:");
	while (p != h)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
/*��ѭ����*/
int Length(CNODE* h)
{
	CNODE* p;
	p = h->next;           //ͷ��㲻������ ָ���һ�����
	int num = 0;
	while (p != h)
	{
		p = p->next;
		num++;
	}
	return (num);
}
/*����*/
void Findelement(CNODE* h)
{
	CNODE* p;
	p = h->next;
	int num = 1, e, i;

	printf("��������Ҫ����Ԫ�ص�λ��:");
	scanf_s("%d", &i);
	while (p != h && num < i)
	{
		p = p->next;
		num++;
	}
	if (p == h)
	{
		printf("Error����������Ԫ�ز��ڷ�������!");
		exit(-1);
	}
	else
		printf("���ҳɹ�!\n��Ԫ��Ϊ:%d", p->data);
}
/*����*/
void Insertelement(CNODE* h)
{
	CNODE* p, * s;
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
	while (p != h && j < i - 1)
	{
		p = p->next;
		j++;
	}

	int value;
	printf("����������Ԫ��:");
	scanf_s("%d", &value);

	s = (CNODE*)malloc(sizeof(CNODE));      //�����½��
	s->data = value;                  //����
	s->next = p->next;           //����
	p->next = s;
	*len = *len + 1;        //������+1
	printf("�����ɹ�!");
}
/*ɾ��*/
void Deleteelement(CNODE* h)
{
	CNODE* p, * q = NULL;
	p = h;
	int value, flag = 0;

	printf("��������Ҫɾ����Ԫ��:");
	scanf_s("%d", &value);
	while (p->next != h && p->data != value)
	{
		q = p;
		p = p->next;
	}
	if (p->data == value)
	{
		q->next = p->next;
		printf("ɾ����:\n");
		Traversecirlink(h);
		free(p);
		flag = 1;
	}
	if (!flag)
		printf("Error!��������Ԫ�ز��ڷ�������");
	return (h);
}

/*�޸�*/
int Alter(CNODE* h)
{
	CNODE* p;
	p = h;
	int value, flag = 0, n = 0;

	printf("��������Ҫ�޸ĵ�Ԫ��:");
	scanf_s("%d", &value);
	while (p->next != h && p->data != value)
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
	CNODE* f = 0;           //��ʼ��   

	CNODE* cirlist;
	printf("��������ѭ������!\n");
	cirlist = Createcirlink();                //����CreateLink����
	printf("ѭ�����������!\n");
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
			Traversecirlink(cirlist);               //����
			break;
		}
		case 2:
		{
			Insertelement(cirlist);                //����
			break;
		}
		case 3:
		{
			Deleteelement(cirlist);              //����deleteelment���� 
			break;
		}
		case 4:
		{
			Findelement(cirlist);                //����Findelement���� ��list�� 
			break;
		}
		case 5:
		{
			Alter(cirlist);                      //����Alter����
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