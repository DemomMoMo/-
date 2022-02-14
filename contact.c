#define _CRT_SECURE_NO_WARNINGS 1
#include"head.h"

void Zero(struct list* ps)
{
	memset(ps->me,0,sizeof(ps->me));
	ps->size = 0;
}

int check(const struct list*ps, char p[15])
{
	int i;
	for (i = 0; i < ps->size; i++)
	{
		if(strcmp(ps->me[i].name, p)==0)
			return i;
}
	return -1;
}

void Add(struct list* ps)
{
	if (ps->size >= max)
	{
		printf("ͨѶ¼����\n");
		return;
	}
	printf("�����������½�ͨѶ¼���û��������䡢�Ա𡢺���\n");
	scanf("%s", ps->me[ps->size].name);
	scanf("%d", &ps->me[ps->size].age);
	scanf("%s", ps->me[ps->size].gender);
	scanf("%s", ps->me[ps->size].num);
	ps->size++;
	printf("��ӳɹ�\n");
}

void Show(struct list* ps)
{
	int i;
	printf("%-20s\t%-4s\t%-12s\t%-20s\n","����","����","�Ա�" ,"����");
	for (i = 0; i < ps->size; i++)
	{
		printf("%-20s\t%-4d\t%-12s\t%-20s\n", 
			ps->me[i].name,
			ps->me[i].age,
			ps->me[i].gender, 
			ps->me[i].num);
	}
}
void Del(struct list* ps)
{
	char p[15];
	printf("����������ɾ�����û�����\n");
	scanf("%s", &p);
	int ret = check(ps, p);
	if (ret < 0)
		printf("���޴���\n");
	else
	{
		int i;
		for (i = ret; i < ps->size - 1; i++)
		{
			ps->me[i] = ps->me[i + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n ");
	}
}

void Modify(struct list* ps)
{
	char p[15];
	printf("�����������޸ĵ��û�����\n");
	scanf("%s", &p);
	int ret = check(ps, p);
	if (ret < 0)
		printf("���޴���\n");
	else
	{
		printf("�û�%s�޸�ǰ����ϢΪ��\n����%d\n�Ա�%s\n����%s\n", 
			ps->me[ret].name,
			ps->me[ret].age,
			ps->me[ret].gender,
			ps->me[ret].num);
		printf("�����������޸ĺ�ĵ����䡢�Ա𡢺���\n");
		scanf("%d", &ps->me[ret].age);
		scanf("%s", ps->me[ret].gender);
		scanf("%s", ps->me[ret].num);
	}
}

void Search(struct list* ps)
{
	char p[15];
	printf("�����������ѯ���û�����\n");
	scanf("%s", &p);
	int ret = check(ps, p);
	if (ret < 0)
		printf("���޴���\n");
	else
	{
		printf("�û�%s����ϢΪ��\n����%d\n�Ա�%s\n����%s\n",
			ps->me[ret].name,
			ps->me[ret].age,
			ps->me[ret].gender,
			ps->me[ret].num);
	}
}