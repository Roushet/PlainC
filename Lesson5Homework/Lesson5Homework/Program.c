#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>


void Solution1();
void Solution2();
void Solution3();


//�������� ���������

//1. ����������� ������� �� 10 � 2 ������� ��������� � �������������� �����.

//2. �������� � ��������� ����������� ����� �� ������ ������������ ������� �������� �� 
//��������� ������.���� ������ �� ����������, �� ��������� ��������������� ���������.������������ ������� 
//��������, ����� ������ �� ����� ����������(����������� �������� ���������� ������).

//3. �������� ���������, ������� ����������, �������� �� ��������� ��������� ������������������ 
//����������.������� ���������� ��������� ��������� : (), ([])(), {}(), ([{}]), ������������ � )(, ())({ ), (, ]) }), ([(]) ��� ������[, (, { .
//��������: (2 + (2 * 2)) ���[2 / {5 * (4 + 7)}]

//4. *������� �������, ���������� ����������� ������(�� ���� ������� � ������ ����� ������������ 
//	������, ��� �������� ������� ������).

//5. **����������� �������� �������� �� ��������� ������ ��������������� ��������� � �����������.

//6. *����������� �������.


int main() {

	unsigned sel = 0;

	printf("Hello! Welcome to Lesson 5 homework\n\nUse numbers between 1 and 3 to select an excercice. Enter 0 to exit.\n\n");
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

		default:
			printf("Please use numbers between 1 and 3\n0 for exit.\n");
			break;
		}
	} while (sel != 0);

	return 0;
}
