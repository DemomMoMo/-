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
	if (ps->size >= Max)
	{
		printf("通讯录已满\n");
		return;
	}
	printf("请依次输入新建通讯录的用户名、年龄、性别、号码\n");
	char p[15];
	scanf("%s", &p);
	int ret = check(ps, p);
	if (ret >= 0)
	{
		printf("此人已在通讯录中\n");
		return;
	}
	strcpy(ps->me[ps->size].name, p);
	scanf("%d", &ps->me[ps->size].age);
	scanf("%s", ps->me[ps->size].gender);
	scanf("%s", ps->me[ps->size].num);
	ps->size++;
	printf("添加成功\n");
}

void Show(struct list* ps)
{
	int i;
	printf("%-8s\t%-4s\t%-12s\t%-20s\n","姓名","年龄","性别" ,"号码");
	for (i = 0; i < ps->size; i++)
	{
		printf("%-8s\t%-4d\t%-12s\t%-20s\n", 
			ps->me[i].name,
			ps->me[i].age,
			ps->me[i].gender, 
			ps->me[i].num);
	}
}
void Del(struct list* ps)
{
	char p[15];
	printf("请输入你想删除的用户姓名\n");
	scanf("%s", &p);
	int ret = check(ps, p);
	if (ret < 0)
		printf("查无此人\n");
	else
	{
		int i;
		for (i = ret; i < ps->size - 1; i++)
		{
			ps->me[i] = ps->me[i + 1];
		}
		ps->size--;
		printf("删除成功\n ");
	}
}

void Modify(struct list* ps)
{
	char p[15];
	printf("请输入你想修改的用户姓名\n");
	scanf("%s", &p);
	int ret = check(ps, p);
	if (ret < 0)
		printf("查无此人\n");
	else
	{
		printf("用户%s修改前的信息为：\n年龄%d\n性别%s\n号码%s\n", 
			ps->me[ret].name,
			ps->me[ret].age,
			ps->me[ret].gender,
			ps->me[ret].num);
		printf("请依次输入修改后的的年龄、性别、号码\n");
		scanf("%d", &ps->me[ret].age);
		scanf("%s", ps->me[ret].gender);
		scanf("%s", ps->me[ret].num);
	}
}

void Search(struct list* ps)
{
	char p[15];
	printf("请输入你想查询的用户姓名\n");
	scanf("%s", &p);
	int ret = check(ps, p);
	if (ret < 0)
		printf("查无此人\n");
	else
	{
		printf("用户%s的信息为：\n年龄%d\n性别%s\n号码%s\n",
			ps->me[ret].name,
			ps->me[ret].age,
			ps->me[ret].gender,
			ps->me[ret].num);
	}
}

int my_name(const void *a, const void*b)
{
	int ret = strcmp(((struct list*)a)->me->name, ((struct list*)b)->me->name);
	return ret;
}

int my_age(const void *a, const void*b)
{
	return ((struct list*)a)->me->age-((struct list*)b)->me->age;
}

int my_gender(const void *a, const void*b)
{
	int ret = strcmp(((struct list*)a)->me->gender, ((struct list*)b)->me->gender);
	return ret;
}

int my_num(const void *a, const void*b)
{
	int ret = strcmp(((struct list*)a)->me->num, ((struct list*)b)->me->num);
	return ret;
}

void Sort(struct list* ps)
{
	int(*hum[4])(const void *, const void*) = { my_name, my_age, my_gender, my_num };
	printf("请输入与你所想要的排序方式对应的数字\n");
	printf("①name     ②age     ③gender     ④num\n");
	int j;
	scanf("%d",&j);
	switch (j)
	{
	case 1:
	case 2:
	case 3:		
	case 4:
		qsort(ps->me,ps->size, sizeof(ps->me[0]) , hum[j-1]);
		break;
	default:
		printf("未能识别\n");
		break;
	}
}
}
