#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct student)

struct student
{
	int num;		//ѧ��
	char name[20];	//����
	char sex[3];	//�Ա�
	int age;		//����
	char sch[7];	//��ѧ��
	struct student *next;	//ָ����һ������ָ��
}stu2 = { 10002,"С��","Ů",18,"һ�Ƚ�",NULL }, stu1 = { 10001,"С��","��",19,"���Ƚ�",&stu2 }, *head = &stu1;

int main()
{
	void menu();
	menu();
	printf("\n�����ѳɹ��˳�����ӭʹ�ã�\n");
	return 0;
}

void back()	//���ز˵����˳�
{
	void menu();
	char c;
	printf("\n�����ɹ����Ƿ񷵻����˵����������� y ���� n��\n");
	while (1)
	{
		c = getchar();
		if (c == '\n')continue;
		else if (c == 'y') { system("cls"); menu(); break; }
		else if (c == 'n')break;
		else printf("Please enter y(es) or n(o)!\n");
	}
}

void fun1()	//���Ҹ�����Ϣ
{
	struct student *p;
	int a;
	register int i;
	printf("����������ѧ��(����0�˳�):");
	scanf("%d", &a);
	while (a != 0)
	{
		for (p = head; p != NULL; p = p->next)
		{
			if (p->num == a)break;
		}
		if (p == NULL)
		{
			printf("\n�û���Ϣ�����ڣ�����������ѧ��(����0�˳�):");
			scanf("%d", &a);
		}
		else
		{
			printf("������������Ϣ:\n");
			for (i = 0; i < 46; i++)printf("*");
			printf("\nѧ��\t����\t\t�Ա�\t����\t��ѧ��\n");
			for (i = 0; i < 46; i++)printf("-");
			printf("\n%d\t%s\t\t%s\t%d\t%s\n", p->num, p->name, p->sex, p->age, p->sch);
			for (i = 0; i < 46; i++)printf("*");
			break;
		}
	}
	back();
}

void fun2()	//��Ӹ�����Ϣ
{
	struct student *p1, *p2;
	register int i;
	p1 = (struct student *)malloc(LEN);
	for (i = 0; i < 82; i++)printf("*");
	printf("\n*��ֱ���������ѧ�ţ��������Ա�����ͽ�ѧ����(û����д\"��\")������\"0\"�˳�¼��*\n");
	for (i = 0; i < 82; i++)printf("*");
	printf("\nѧ��\t����\t\t�Ա�\t����\t��ѧ��\n");
	for (i = 0; i < 46; i++)printf("-"); printf("\n");
	scanf("%d", &p1->num);
	if (p1->num != 0)
	{
		scanf("%s%s%d%s", p1->name, &p1->sex, &p1->age, p1->sch);
		if (head == NULL)
		{
			p2 = head = p1;
			p2->next = NULL;
		}
		else
		{
			for (p2 = head; p2->next != NULL; p2 = p2->next);
			p2->next = p1;
			p2 = p1;
			p2->next = NULL;
		}
	}
	back();
}

void fun3()	//ɾ��������Ϣ
{
	struct student *p,*p1,*p2;
	int a;
	printf("����������ѧ��(����0�˳�):");
	scanf("%d", &a);
	while (a != 0)
	{
		for (p = head, p1 = p; p != NULL; p1 = p, p = p->next)
		{
			if (p->num == a)
			{
				p2 = p->next;
				break;
			}
		}
		if (p == NULL)
		{
			printf("\n�û���Ϣ�����ڣ�����������ѧ��(����0�˳�):");
			scanf("%d", &a);
		}
		else if (p1 == p)
		{
			head = p->next;
			break;
		}
		else
		{
			p1->next = p2;
			break;
		}
	}
	back();
}

void fun4()	//�޸ĸ�����Ϣ
{
	struct student *p;
	int a,b;
	register int i;
	printf("����������ѧ��(����0�˳�):");
	scanf("%d", &a);
	while (a != 0)
	{
		for (p = head; p != NULL; p = p->next)
		{
			if (p->num == a)break;
		}
		if (p == NULL)
		{
			printf("\n�û���Ϣ�����ڣ�����������ѧ��(����0�˳�):");
			scanf("%d", &a);
		}
		else
		{
			printf("������������Ϣ:\n");
			for (i = 0; i < 46; i++)printf("*");
			printf("\nѧ��\t����\t\t�Ա�\t����\t��ѧ��\n");
			for (i = 0; i < 46; i++)printf("-");
			printf("\n%d\t%s\t\t%s\t%d\t%s\n", p->num, p->name, p->sex, p->age, p->sch);
			for (i = 0; i < 46; i++)printf("*");
			printf("\n\n");
			for (i = 0; i < 46; i++)printf("*");
			printf("\n\t   +----------------------+\n");
			printf("\t   |     ��Ϣ�޸Ĳ˵�     |\n");
			printf("\t   +----------------------+\n");
			printf("\t   |     [1]----ѧ��      |\n");
			printf("\t   |     [2]----����      |\n");
			printf("\t   |     [3]----�Ա�      |\n");
			printf("\t   |     [4]----����      |\n");
			printf("\t   |     [5]----��ѧ��    |\n");
			printf("\t   |     [0]----�˳�      |\n");
			printf("\t   +----------------------+\n");
			for (i = 0; i < 46; i++)printf("*");
			printf("\n����������ѡ��:");
			scanf("%d", &b);
			while (b < 0 || b > 5)
			{
				printf("\n�������������ѡ��:");
				scanf("%d", &b);
			}
			while (b)
			{
				printf("\n�������޸ĺ������Ϣ:");
				switch (b)
				{
				case 1:scanf("%d", &p->num); break;
				case 2:scanf("%s", p->name); break;
				case 3:scanf("%s", p->sex); break;
				case 4:scanf("%d", &p->age); break;
				case 5:scanf("%s", p->sch); break;
				}
				printf("�޸ĳɹ����޸ĺ����Ϣ���£�\n");
				for (i = 0; i < 46; i++)printf("*");
				printf("\nѧ��\t����\t\t�Ա�\t����\t��ѧ��\n");
				for (i = 0; i < 46; i++)printf("-");
				printf("\n%d\t%s\t\t%s\t%d\t%s\n", p->num, p->name, p->sex, p->age, p->sch);
				for (i = 0; i < 46; i++)printf("*");
				break;
			}
			break;
		}
	}
	back();
}

void fun5()	//���ѧ����Ϣ
{
	register int i;
	struct student *p;
	printf("ѧ����Ϣһ��:\n");
	for (i = 0; i < 46; i++)printf("*");
	printf("\nѧ��\t����\t\t�Ա�\t����\t��ѧ��\n");
	for (i = 0; i < 46; i++)printf("-"); printf("\n");
	for (p = head; p != NULL; p = p->next)
	{
		printf("%d\t%s\t\t%s\t%d\t%s\n", p->num, p->name, p->sex, p->age, p->sch);
	}
	for (i = 0; i < 46; i++)printf("*");
	back();
}

void fun6()	//����Ϣ�����������ļ�
{
	FILE *fp;
	struct student *p;
	if ((fp = fopen("stu.dat", "wb")) == NULL)
	{
		printf("����:�޷����ļ���\n");
		return;
	}
	for (p = head; p != NULL; p = p->next)
	{
		if(fwrite(p, LEN, 1, fp)!=1) printf("����ʧ�ܣ�\n");
	}
	fclose(fp);
	back();
}

void fun7()	//�ӱ����ļ���ȡ��Ϣ
{
	FILE *fp;
	struct student *p, *p1;
	if ((fp = fopen("stu.dat", "rb")) == NULL)
	{
		printf("����:�޷����ļ���\n");
		exit(0);
	}
	for (p = head; p != NULL; p = p->next)
	{
		fread(p, LEN, 1, fp);
		if (p->next != NULL)
		{
			p1 = (struct student *)malloc(LEN);
			p->next = p1;
		}
	}
	fclose(fp);
	back();
}

void fun8()	//�鿴��ѧ����Ϣ
{	
	struct student *p;
	char str1[50]="һ�Ƚ�:";
	char str2[50]="���Ƚ�:";
	char str3[50]="���Ƚ�:";
	for (p = head; p != NULL; p = p->next)
	{
		if (!strcmp(p->sch, "һ�Ƚ�")) { strcat(str1, p->name); strcat(str1, "  "); }
		if (!strcmp(p->sch, "���Ƚ�")) { strcat(str2, p->name); strcat(str2, "  "); }
		if (!strcmp(p->sch, "���Ƚ�")) { strcat(str3, p->name); strcat(str3, "  "); }
	}
	printf("%s\n%s\n%s\n", str1, str2, str3);
	back();
}

void menu()	//�˵�
{
	int a;
	register int i;
	for (i = 0; i < 48; i++)printf("*");
	printf("\n\t+------------------------------+\n");
	printf("\t|            ���˵�            |\n");
	printf("\t+------------------------------+\n");
	printf("\t|    [1]----����ѧ����Ϣ       |\n");
	printf("\t|    [2]----���ѧ����Ϣ       |\n");
	printf("\t|    [3]----ɾ��ѧ����Ϣ       |\n");
	printf("\t|    [4]----�޸�ѧ����Ϣ       |\n");
	printf("\t|    [5]----���ѧ����Ϣ       |\n");
	printf("\t|    [6]----����������         |\n");
	printf("\t|    [7]----�ӱ��ص���         |\n");
	printf("\t|    [8]----�鿴��ѧ����Ϣ     |\n");
	printf("\t|    [0]----�˳�ϵͳ           |\n");
	printf("\t+------------------------------+\n");
	for (i = 0; i < 48; i++)printf("*");
	printf("\n��ѡ��:");
	scanf("%d", &a);
	while (a < 0 || a > 8)
	{
		printf("�������\n������ѡ��:");
		scanf("%d", &a);
	}
	switch (a)
	{
	case 1: system("cls"); fun1(); break;
	case 2: system("cls"); fun2(); break;
	case 3: system("cls"); fun3(); break;
	case 4: system("cls"); fun4(); break;
	case 5: system("cls"); fun5(); break;
	case 6: system("cls"); fun6(); break;
	case 7: system("cls"); fun7(); break;
	case 8: system("cls"); fun8(); break;
	case 0: break;
	default:printf("���棡�벻Ҫ�����ַ���\n");
	}
}