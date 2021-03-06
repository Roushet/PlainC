#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

//�������� ���������

struct Field
{
	unsigned x, y;
};

void Solution1();
void Solution2();
void Solution3();
void Solution4();

int CheckFieldColors(struct Field F1, struct Field F2);
int isAutomorphic(unsigned num);

int main() {

	unsigned sel = 0;
	printf("Hello! Welcome to Lesson 1 homework\n\nUse numbers between 1 and 4 to select an excercice. Enter 0 to exit.\n\n");
	do {
		printf("Please select an excercise : \n");
		scanf("%i", &sel);

		switch (sel)
		{
		case 1:
			Solution1();
			break;
		case 2:
			Solution2();
			break;
		case 3:
			Solution3();
			break;
		case 4:
			Solution4();
			break;
		default:
			printf("Please use numbers between 1 and 4\n0 for exit.\n");
			break;
		}
	} while (sel != 0);

	return 0;
}

//1. *� ���������� �������� �������� ���������� ���� ����� ��������� �����(x1, y1, x2, y2).
//��������� ����������, ��������� �� � ���� � ������ ����� ��� ���.
void Solution1() {

	struct  Field F1;
	struct  Field F2;

	printf("Solution 1.\n\n");
	printf("This program will determine if two chess field share same color.\n\n");
	printf("Input numbers between 1 and 8 - postion of field 1:\n");

	do {
		scanf("%u", &F1.x);
	} while (F1.x < 1 && F1.x > 8);

	do {
		scanf("%u", &F1.y);
	} while (F1.y < 1 && F1.y >8);

	printf("F1 x %u y %u \n", F1.x, F1.y);

	printf("Please input numbers between 1 and 8 - postion of field 2:\n");

	do {
		scanf("%u", &F2.x);
	} while (F2.x < 1 && F2.x >8);

	do {
		scanf("%u", &F2.y);
	} while (F2.y < 1 && F2.y >8);

	printf("F2 x %u y %u", F2.x, F2.y);

	if (CheckFieldColors(F1, F2) != 0)
		printf("Colors are the same\n");
	else
		printf("Colors are not the same\n");

	return;
}

int CheckFieldColors(struct Field F1, struct Field F2) {
	unsigned int color1 = 0;
	unsigned int color2 = 0;

	//1 - black
	//0 - white

	if (F1.x % 2 == 1 && F1.y % 2 == 1)
		color1 = 1;
	else
		color1 = 0;

	if (F2.x % 2 == 0 && F2.y % 2 == 0)
		color2 = 1;
	else
		color2 = 0;

	if (color1 == color2)
		return 1;
	else
		return 0;

	return 0;
}

//2. * ����������� �����.����������� ����� ���������� �����������, ���� ��� �����
//��������� ������ ������ ��������.��������, 25 2 = 625. �������� ���������, �������
//������ ����������� ����� N � ������� �� ����� ��� ����������� �����, �� �������������
//N.
void Solution2() {
	printf("Solution 2.\n\n");

	unsigned num = 0;
	unsigned i = 0;
	printf("Input number:\n");
	do {
		scanf("%u", &num);
	} while (num == 0);

	for (i = 1; i < num; i++) {
		if (isAutomorphic(i))
			printf("%u ", i);
	}
	printf("\n");
}

int isAutomorphic(unsigned num) {

	if (num == 1) return 1;

	unsigned square = num * num;
	unsigned rank = 1;
	unsigned div;

	do {
		div = num / (unsigned)pow(10, rank);
		if (div > 0) rank += 1;
	} while (div > 0);

	if ((square - num) % (unsigned)pow(10, rank) == 0)
		return 1;
	else
		return 0;

	return 0;
}

//3. *����������� �������� ������ ������� ����� ������� ����������.
//**������� ����� ������� ����� ��������� � ������� ����� ���������.
//***���������� ����� ���������� ����� �����.

void Solution3() {
	unsigned size;
	unsigned * array;
	unsigned i, j;

	printf("Solution 3.\n\n");

	printf("Input size: ");
	scanf("%u", &size);

	if (size == 0)
		return;

	array = (unsigned *)malloc(size * sizeof(unsigned));

	//��������� ������
	for (i = 0; i < size; i++)
		array[i] = i + 1;

	//��������� ����� � �������

	for (i = 1; i < size; i++) {
		if (array[i] != 0) {
			for (j = i + 1; j < size; j++) {
				if (array[j] != 0 && array[j] % array[i] == 0)
					array[j] = 0;
			}
		}
	}

	for (i = 0; i < size; i++) {
		if (array[i] != 0)
			printf("%u ", array[i]);
	}

	printf("\n");
}

//3. *����������� �������� ������ ������� ����� ������� ����������.
//**������� ����� ������� ����� ��������� � ������� ����� ���������.
//***���������� ����� ���������� ����� �����.

void Solution4() {

	//��������� ������� ������ ����� �������
	//1900 MB x86
	int Mb = 0;
	//2 � ������� 20 - ��� 1 048 576 (�.�. 1 ��������)
	while (malloc(1 << 20)) ++Mb;
	printf("Allocated %d Mb total\n", Mb);

	//UINT_MAX = 4 294 967 295
	//2 342 502 400

	//
	unsigned size = Mb * 1048576;
	unsigned * array;
	unsigned i, j;

	clock_t t1, t2;

	printf("Solution 4.\n\n");

	printf("Using max unsigned: %u\n", size);

	t1 = clock();

	array = (unsigned *)malloc(size * sizeof(unsigned));

	//��������� ������
	//--- ������-�� ������ ��� ���������� �������, ���� ��� ����� ����������
	for (i = 0; i < size; i++) {
		array[i] = i + 1;
	}

	//��������� ����� � �������

	for (i = 1; i < size; i++) {
		if (array[i] != 0) {
			for (j = i + 1; j < size; j++) {
				if (array[j] != 0 && array[j] % array[i] == 0)
					array[j] = 0;
			}
		}
	}
	t2 = clock();

	//for (i = 0; i < size; i++) {
	//	if (array[i] != 0)
	//		printf("%u ", array[i]);
	//}

	printf("TIME: \n sec");
	printf("%lf", (double)(t2 - t1) / CLOCKS_PER_SEC);
	printf("\n");
}