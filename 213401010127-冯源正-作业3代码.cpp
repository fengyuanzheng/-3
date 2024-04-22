#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

struct student {
	char name[30];//学生姓名
	char dadname[30];//父亲名字
	char mumname[30];//母亲名字
	int year;//出生年
	int month;//出生月
	int day;//出生日
	int hour;//出生时刻-时
	int min;//出生时刻-分
	int bts = 1;//胞胎数
};

struct student stu[100];//利用数据结构中的顺序表实现新生的结构体
struct student name1;//用于升序输出每组学生信息的临时变量

int main() {
	int i = 0;
	int j = 1;
	int k = 0;
	int num = 0;//新生数量
	int m = 1;//统计双胞胎组数
	int n = 1;//统计三胞胎组数
	int a = 0;

	printf("-------------------欢迎使用新生多胞胎自动识别系统！-------------------\n请输入新生数量:");
	scanf("%d", &num);
	printf("请输入新生的个人信息:(依次为学生姓名，父亲名字，母亲名字，出生日期(年，月，日)，出生时刻(时，分))\n");
	for (i = 0; i < num; i++) {
		scanf("%s%s%s%d-%d-%d%d:%d", stu[i].name, stu[i].dadname, stu[i].mumname, &stu[i].year, &stu[i].month, &stu[i].day, &stu[i].hour, &stu[i].min);
	}
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			if (strcmp(stu[i].dadname, stu[j].dadname) == 0 && ((stu[i].hour * 60 + stu[i].min) - \
				(stu[j].hour * 60 + stu[j].min) < 5) && stu[i].day == stu[j].day && strcmp(stu[i].name, stu[j].name) != 0) {//判断是几胞胎
				 stu[i].bts++;//胞胎数的统计
			}
		}
	}

	printf("-------------------------多胞胎识别结果如下:--------------------------\n");
	for (i = a; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			if (stu[i].bts == 2 && strcmp(stu[i].dadname, stu[j].dadname) == 0 && strcmp(stu[i].mumname, stu[j].mumname) == 0 && \
				((stu[i].hour * 60 + stu[i].min) - (stu[j].hour * 60 + stu[j].min) < 5) && stu[i].day == stu[j].day && strcmp(stu[i].name, stu[j].name) != 0) {
				printf("第%d组双胞胎的信息为：\n", m);
				printf("新生姓名 父亲姓名 母亲姓名 出生日期 出生时刻\n");
				if (strcmp(stu[i].name, stu[j].name) < 0) {
					name1 = stu[j];
					stu[j] = stu[i];
					stu[i] = name1;
				}//按照学生名字升序排列每组学生的信息
				m++;//组数
				printf("%s %s %s %d-%d-%d %d:%d\n", stu[i].name, stu[i].dadname, stu[i].mumname, stu[i].year, stu[i].month, stu[i].day, stu[i].hour, stu[i].min);
				printf("%s %s %s %d-%d-%d %d:%d\n", stu[j].name, stu[j].dadname, stu[j].mumname, stu[j].year, stu[j].month, stu[j].day, stu[j].hour, stu[j].min);
			}
		}
	}//是否为双胞胎的判断

	for (i = a; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			for (k = j + 1; k < num; k++) {
				if (stu[i].bts == 3 && strcmp(stu[i].dadname, stu[j].dadname) == 0 && strcmp(stu[j].dadname, stu[k].dadname) == 0\
					&& strcmp(stu[i].mumname, stu[j].mumname) == 0 && strcmp(stu[j].mumname, stu[k].mumname) == 0\
					&& ((stu[i].hour * 60 + stu[i].min) - (stu[j].hour * 60 + stu[j].min) < 5)\
					&& ((stu[j].hour * 60 + stu[j].min) - (stu[k].hour * 60 + stu[k].min) < 5)\
					&& stu[i].day == stu[j].day && stu[j].day == stu[k].day && stu[i].day == stu[k].day && strcmp(stu[i].name, stu[j].name) != 0\
					&& strcmp(stu[j].name, stu[k].name) != 0 && strcmp(stu[i].name, stu[k].name) != 0) {
					printf("第%d组三胞胎的信息为：\n", n);
					printf("新生姓名 父亲姓名 母亲姓名 出生日期 出生时刻\n");
					if (strcmp(stu[i].name, stu[j].name) < 0) {
						name1 = stu[j];
						stu[j] = stu[i];
						stu[i] = name1;
					}
					if (strcmp(stu[j].name, stu[k].name) < 0) {
						name1 = stu[k];
						stu[k] = stu[j];
						stu[j] = name1;
					}
					if (strcmp(stu[i].name, stu[k].name) < 0) {
						name1 = stu[k];
						stu[k] = stu[i];
						stu[i] = name1;
					}//按照学生名字升序排列每组学生的信息
					n++;//组数
					printf("%s %s %s %d-%d-%d %d:%d\n", stu[i].name, stu[i].dadname, stu[i].mumname, stu[i].year, stu[i].month, stu[i].day, stu[i].hour, stu[i].min);
					printf("%s %s %s %d-%d-%d %d:%d\n", stu[j].name, stu[j].dadname, stu[j].mumname, stu[j].year, stu[j].month, stu[j].day, stu[j].hour, stu[j].min);
					printf("%s %s %s %d-%d-%d %d:%d\n", stu[k].name, stu[k].dadname, stu[k].mumname, stu[k].year, stu[k].month, stu[k].day, stu[k].hour, stu[k].min);
				}
			}
		}
	}//是否为多胞胎的判断

	system("pause");
	return 0;
}