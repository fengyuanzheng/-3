#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

struct student {
	char name[30];//ѧ������
	char dadname[30];//��������
	char mumname[30];//ĸ������
	int year;//������
	int month;//������
	int day;//������
	int hour;//����ʱ��-ʱ
	int min;//����ʱ��-��
	int bts = 1;//��̥��
};

struct student stu[100];//�������ݽṹ�е�˳���ʵ�������Ľṹ��
struct student name1;//�����������ÿ��ѧ����Ϣ����ʱ����

int main() {
	int i = 0;
	int j = 1;
	int k = 0;
	int num = 0;//��������
	int m = 1;//ͳ��˫��̥����
	int n = 1;//ͳ������̥����
	int a = 0;

	printf("-------------------��ӭʹ���������̥�Զ�ʶ��ϵͳ��-------------------\n��������������:");
	scanf("%d", &num);
	printf("�����������ĸ�����Ϣ:(����Ϊѧ���������������֣�ĸ�����֣���������(�꣬�£���)������ʱ��(ʱ����))\n");
	for (i = 0; i < num; i++) {
		scanf("%s%s%s%d-%d-%d%d:%d", stu[i].name, stu[i].dadname, stu[i].mumname, &stu[i].year, &stu[i].month, &stu[i].day, &stu[i].hour, &stu[i].min);
	}
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			if (strcmp(stu[i].dadname, stu[j].dadname) == 0 && ((stu[i].hour * 60 + stu[i].min) - \
				(stu[j].hour * 60 + stu[j].min) < 5) && stu[i].day == stu[j].day && strcmp(stu[i].name, stu[j].name) != 0) {//�ж��Ǽ���̥
				 stu[i].bts++;//��̥����ͳ��
			}
		}
	}

	printf("-------------------------���̥ʶ��������:--------------------------\n");
	for (i = a; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			if (stu[i].bts == 2 && strcmp(stu[i].dadname, stu[j].dadname) == 0 && strcmp(stu[i].mumname, stu[j].mumname) == 0 && \
				((stu[i].hour * 60 + stu[i].min) - (stu[j].hour * 60 + stu[j].min) < 5) && stu[i].day == stu[j].day && strcmp(stu[i].name, stu[j].name) != 0) {
				printf("��%d��˫��̥����ϢΪ��\n", m);
				printf("�������� �������� ĸ������ �������� ����ʱ��\n");
				if (strcmp(stu[i].name, stu[j].name) < 0) {
					name1 = stu[j];
					stu[j] = stu[i];
					stu[i] = name1;
				}//����ѧ��������������ÿ��ѧ������Ϣ
				m++;//����
				printf("%s %s %s %d-%d-%d %d:%d\n", stu[i].name, stu[i].dadname, stu[i].mumname, stu[i].year, stu[i].month, stu[i].day, stu[i].hour, stu[i].min);
				printf("%s %s %s %d-%d-%d %d:%d\n", stu[j].name, stu[j].dadname, stu[j].mumname, stu[j].year, stu[j].month, stu[j].day, stu[j].hour, stu[j].min);
			}
		}
	}//�Ƿ�Ϊ˫��̥���ж�

	for (i = a; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			for (k = j + 1; k < num; k++) {
				if (stu[i].bts == 3 && strcmp(stu[i].dadname, stu[j].dadname) == 0 && strcmp(stu[j].dadname, stu[k].dadname) == 0\
					&& strcmp(stu[i].mumname, stu[j].mumname) == 0 && strcmp(stu[j].mumname, stu[k].mumname) == 0\
					&& ((stu[i].hour * 60 + stu[i].min) - (stu[j].hour * 60 + stu[j].min) < 5)\
					&& ((stu[j].hour * 60 + stu[j].min) - (stu[k].hour * 60 + stu[k].min) < 5)\
					&& stu[i].day == stu[j].day && stu[j].day == stu[k].day && stu[i].day == stu[k].day && strcmp(stu[i].name, stu[j].name) != 0\
					&& strcmp(stu[j].name, stu[k].name) != 0 && strcmp(stu[i].name, stu[k].name) != 0) {
					printf("��%d������̥����ϢΪ��\n", n);
					printf("�������� �������� ĸ������ �������� ����ʱ��\n");
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
					}//����ѧ��������������ÿ��ѧ������Ϣ
					n++;//����
					printf("%s %s %s %d-%d-%d %d:%d\n", stu[i].name, stu[i].dadname, stu[i].mumname, stu[i].year, stu[i].month, stu[i].day, stu[i].hour, stu[i].min);
					printf("%s %s %s %d-%d-%d %d:%d\n", stu[j].name, stu[j].dadname, stu[j].mumname, stu[j].year, stu[j].month, stu[j].day, stu[j].hour, stu[j].min);
					printf("%s %s %s %d-%d-%d %d:%d\n", stu[k].name, stu[k].dadname, stu[k].mumname, stu[k].year, stu[k].month, stu[k].day, stu[k].hour, stu[k].min);
				}
			}
		}
	}//�Ƿ�Ϊ���̥���ж�

	system("pause");
	return 0;
}