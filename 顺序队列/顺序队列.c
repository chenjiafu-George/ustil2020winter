#include<stdio.h>
#include<stdlib.h>
#define MAXIMUM 100

typedef int Datatype;

/*��������*/
void Createsqueue(Datatype* squeue)
{
	int value, len;
	printf("��������д�С:");
	scanf_s("%d", &len);
	for (int count = 0; count < len; count++)
	{
		printf("���еĵ�%d��Ԫ��:", count + 1);
		scanf_s("%d", &value);
		squeue[count] = value;
	}
	printf("�����ɹ�!\n");
}
/*����*/
void Traversesqueue(Datatype* squeue)
{
	int count = 0, len;
	len = Lengthsqueue(squeue);
	printf("����Ϊ:");
	for (; count < len; count++)
		printf("%d ", squeue[count]);
	printf("\n");
}
/*����*/
int Findsqueue(Datatype* squeue)
{
	int count = 0, len, x;
	len = Lengthsqueue(squeue);    //����д�С
	printf("��������ҵ�Ԫ��:");
	scanf_s("%d", &x);
	while (squeue[count] != x && count < len)   //�ж��������Ƿ����ҵ�
		count++;
	if (count == len)					//δ�ҵ�
		printf("����ʧ��!�������޴�Ԫ��!\n");
	else							    //����Ԫ�ص����λ��
		printf("���ҳɹ�!\n�ڶ����е�λ��Ϊ:%d", count + 1);
}
/*�޸�*/
void Altersqueue(Datatype* squeue)
{
	int count = 0, len, x, value;
	len = Lengthsqueue(squeue);    //����д�С

	printf("�������޸ĵ�Ԫ��:");
	scanf_s("%d", &x);
	printf("��������Ҫ�޸�Ϊ:");
	scanf_s("%d", &value);

	while (squeue[count] != x && count < len)   //�ж��������Ƿ����ҵ�
		count++;
	if (count == len)					//δ�ҵ�
		printf("�������޴�Ԫ��,�޷��޸�!\n");
	else							    //����Ԫ�ص����λ��
	{
		squeue[count] = value;
		printf("�޸ĳɹ�!\n");
	}
}
/*����*/
void Insertsqueue(Datatype* squeue)
{
	int a, count, x, i;
	int* len;

	a = Lengthsqueue(squeue);
	len = &a;
	printf("���������Ԫ�ص�λ��:");
	scanf_s("%d", &i);
	printf("����������Ԫ��:");
	scanf_s("%d", &x);

	if (i > * len || i < 0)
		printf("�������,�޷�����,����������!");
	if (i == *len)
		squeue[i] = x;
	else
	{
		for (count = *len - 1; count >= i; count--)
			squeue[count + 1] = squeue[count];
		squeue[i] = x;
	}
	*len = *len + 1;
	printf("����ɹ�!\n");
}
/*ɾ��*/
void Deletesqueue(Datatype* squeue)
{
	int Loc, count = 0, x, a;
	printf("��������Ҫɾ����Ԫ��:");
	scanf_s("%d", &x);
	int* len;

	a = Lengthsqueue(squeue);
	len = &a;
	while (squeue[count] != x && count < *len)
		count++;
	if (count == *len)
		printf("������û�д�Ԫ��!\n");
	else
	{
		Loc = count;			//�ҵ�����¼���ڶ��е�λ��
		for (count = Loc; count < *len; count++)
			squeue[count] = squeue[count + 1];
		*len = *len - 1;
		printf("��ɾ��!��ԭ���е�%dλ\n", Loc + 1);
	}
}
/*���г���*/
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
	printf("������������!\n");
	Createsqueue(squeue);                //����CreateLink����
	printf("���д������!\n");
	system("pause");//��ͣ
	system("cls");//����

	printf("ѡ������Ҫ�Ĳ�����\n");
	printf("1.���� 2.���� 3.ɾ�� 4.���� 5.�޸� 6.�˳�\n");
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
			printf("ллʹ��\n");
			exit(0);
			break;
		default:
			printf("input error!\n");
			break;
		}
		system("pause");                 //��ͣ 
		system("cls");					//���� 
		printf("ѡ������Ҫ�Ĳ�����\n");
		printf("1.���� 2.���� 3.ɾ�� 4.���� 5.�޸� 6.�˳�\n");
	}
	return 0;
}