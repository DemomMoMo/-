#define _CRT_SECURE_NO_WARNINGS 1
#include"head.h"

void begin()
{
	printf("#########################################################\n");
	printf("#########      ��add           ��del         ############\n");
	printf("#########      ��search        ��modify      ############\n");
	printf("#########      ��show          ��sort        ############\n");
	printf("#########      ��exit                        ############\n");
	printf("#########################################################\n");
}

enum
{
	exit,
	add,
	del,
	search,
	modify,
	show,
	sort,
};

int main()
{
	struct list ps;
	Zero(&ps);
	begin();
	int cos = 1;
	while (cos!=0){
		printf("����������Ҫ��������ֱ��\n");
		scanf("%d", &cos);
		switch (cos){
		case add:
			Add(&ps);
			break;
		case del:
			Del(&ps);
			break;
		case search:
			Search(&ps);
			break;
		case modify:
			Modify(&ps);
			break;
		case show:
			Show(&ps);
			break;
		case exit:
			break;
		default:
			printf("δ��ʶ������������\n");
		}
	}
	return 0;

}