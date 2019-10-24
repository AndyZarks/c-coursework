#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct student)

struct student
{
	int num;		//学号
	char name[20];	//姓名
	char sex[3];	//性别
	int age;		//年龄
	char sch[7];	//奖学金
	struct student *next;	//指向下一个结点的指针
}stu2 = { 10002,"小丽","女",18,"一等奖",NULL }, stu1 = { 10001,"小明","男",19,"二等奖",&stu2 }, *head = &stu1;

int main()
{
	void menu();
	menu();
	printf("\n程序已成功退出！欢迎使用！\n");
	return 0;
}

void back()	//返回菜单或退出
{
	void menu();
	char c;
	printf("\n操作成功！是否返回主菜单？（请输入 y 或者 n）\n");
	while (1)
	{
		c = getchar();
		if (c == '\n')continue;
		else if (c == 'y') { system("cls"); menu(); break; }
		else if (c == 'n')break;
		else printf("Please enter y(es) or n(o)!\n");
	}
}

void fun1()	//查找个人信息
{
	struct student *p;
	int a;
	register int i;
	printf("请输入您的学号(输入0退出):");
	scanf("%d", &a);
	while (a != 0)
	{
		for (p = head; p != NULL; p = p->next)
		{
			if (p->num == a)break;
		}
		if (p == NULL)
		{
			printf("\n用户信息不存在！请重新输入学号(输入0退出):");
			scanf("%d", &a);
		}
		else
		{
			printf("以下是您的信息:\n");
			for (i = 0; i < 46; i++)printf("*");
			printf("\n学号\t姓名\t\t性别\t年龄\t奖学金\n");
			for (i = 0; i < 46; i++)printf("-");
			printf("\n%d\t%s\t\t%s\t%d\t%s\n", p->num, p->name, p->sex, p->age, p->sch);
			for (i = 0; i < 46; i++)printf("*");
			break;
		}
	}
	back();
}

void fun2()	//添加个人信息
{
	struct student *p1, *p2;
	register int i;
	p1 = (struct student *)malloc(LEN);
	for (i = 0; i < 82; i++)printf("*");
	printf("\n*请分别输入您的学号，姓名，性别，年龄和奖学金金额(没有则写\"无\")。输入\"0\"退出录入*\n");
	for (i = 0; i < 82; i++)printf("*");
	printf("\n学号\t姓名\t\t性别\t年龄\t奖学金\n");
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

void fun3()	//删除个人信息
{
	struct student *p,*p1,*p2;
	int a;
	printf("请输入您的学号(输入0退出):");
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
			printf("\n用户信息不存在！请重新输入学号(输入0退出):");
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

void fun4()	//修改个人信息
{
	struct student *p;
	int a,b;
	register int i;
	printf("请输入您的学号(输入0退出):");
	scanf("%d", &a);
	while (a != 0)
	{
		for (p = head; p != NULL; p = p->next)
		{
			if (p->num == a)break;
		}
		if (p == NULL)
		{
			printf("\n用户信息不存在！请重新输入学号(输入0退出):");
			scanf("%d", &a);
		}
		else
		{
			printf("以下是您的信息:\n");
			for (i = 0; i < 46; i++)printf("*");
			printf("\n学号\t姓名\t\t性别\t年龄\t奖学金\n");
			for (i = 0; i < 46; i++)printf("-");
			printf("\n%d\t%s\t\t%s\t%d\t%s\n", p->num, p->name, p->sex, p->age, p->sch);
			for (i = 0; i < 46; i++)printf("*");
			printf("\n\n");
			for (i = 0; i < 46; i++)printf("*");
			printf("\n\t   +----------------------+\n");
			printf("\t   |     信息修改菜单     |\n");
			printf("\t   +----------------------+\n");
			printf("\t   |     [1]----学号      |\n");
			printf("\t   |     [2]----姓名      |\n");
			printf("\t   |     [3]----性别      |\n");
			printf("\t   |     [4]----年龄      |\n");
			printf("\t   |     [5]----奖学金    |\n");
			printf("\t   |     [0]----退出      |\n");
			printf("\t   +----------------------+\n");
			for (i = 0; i < 46; i++)printf("*");
			printf("\n请输入您的选择:");
			scanf("%d", &b);
			while (b < 0 || b > 5)
			{
				printf("\n输入错误！请重新选择:");
				scanf("%d", &b);
			}
			while (b)
			{
				printf("\n请输入修改后的新信息:");
				switch (b)
				{
				case 1:scanf("%d", &p->num); break;
				case 2:scanf("%s", p->name); break;
				case 3:scanf("%s", p->sex); break;
				case 4:scanf("%d", &p->age); break;
				case 5:scanf("%s", p->sch); break;
				}
				printf("修改成功！修改后的信息如下！\n");
				for (i = 0; i < 46; i++)printf("*");
				printf("\n学号\t姓名\t\t性别\t年龄\t奖学金\n");
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

void fun5()	//浏览学生信息
{
	register int i;
	struct student *p;
	printf("学生信息一览:\n");
	for (i = 0; i < 46; i++)printf("*");
	printf("\n学号\t姓名\t\t性别\t年龄\t奖学金\n");
	for (i = 0; i < 46; i++)printf("-"); printf("\n");
	for (p = head; p != NULL; p = p->next)
	{
		printf("%d\t%s\t\t%s\t%d\t%s\n", p->num, p->name, p->sex, p->age, p->sch);
	}
	for (i = 0; i < 46; i++)printf("*");
	back();
}

void fun6()	//将信息保存至本地文件
{
	FILE *fp;
	struct student *p;
	if ((fp = fopen("stu.dat", "wb")) == NULL)
	{
		printf("错误:无法打开文件！\n");
		return;
	}
	for (p = head; p != NULL; p = p->next)
	{
		if(fwrite(p, LEN, 1, fp)!=1) printf("保存失败！\n");
	}
	fclose(fp);
	back();
}

void fun7()	//从本地文件读取信息
{
	FILE *fp;
	struct student *p, *p1;
	if ((fp = fopen("stu.dat", "rb")) == NULL)
	{
		printf("错误:无法打开文件！\n");
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

void fun8()	//查看奖学金信息
{	
	struct student *p;
	char str1[50]="一等奖:";
	char str2[50]="二等奖:";
	char str3[50]="三等奖:";
	for (p = head; p != NULL; p = p->next)
	{
		if (!strcmp(p->sch, "一等奖")) { strcat(str1, p->name); strcat(str1, "  "); }
		if (!strcmp(p->sch, "二等奖")) { strcat(str2, p->name); strcat(str2, "  "); }
		if (!strcmp(p->sch, "三等奖")) { strcat(str3, p->name); strcat(str3, "  "); }
	}
	printf("%s\n%s\n%s\n", str1, str2, str3);
	back();
}

void menu()	//菜单
{
	int a;
	register int i;
	for (i = 0; i < 48; i++)printf("*");
	printf("\n\t+------------------------------+\n");
	printf("\t|            主菜单            |\n");
	printf("\t+------------------------------+\n");
	printf("\t|    [1]----查找学生信息       |\n");
	printf("\t|    [2]----添加学生信息       |\n");
	printf("\t|    [3]----删除学生信息       |\n");
	printf("\t|    [4]----修改学生信息       |\n");
	printf("\t|    [5]----浏览学生信息       |\n");
	printf("\t|    [6]----保存至本地         |\n");
	printf("\t|    [7]----从本地导入         |\n");
	printf("\t|    [8]----查看奖学金信息     |\n");
	printf("\t|    [0]----退出系统           |\n");
	printf("\t+------------------------------+\n");
	for (i = 0; i < 48; i++)printf("*");
	printf("\n请选择:");
	scanf("%d", &a);
	while (a < 0 || a > 8)
	{
		printf("输入错误！\n请重新选择:");
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
	default:printf("警告！请不要输入字符！\n");
	}
}