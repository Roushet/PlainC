#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

void Solution1();

void array_stack_push(int var);
int array_stack_pop();

//void Solution2();
void Solution3();

char * stack_create(const unsigned size);
void stack_destroy(char *stack);
void stack_push(char *stack, char value);
char stack_pop(char *stack);

int IsOpenBracket(char c);
int IsCloseBracket(char c);
char getReverceBracket(char c);

//�������� ���������


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
			//Solution2();
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

//1. ����������� ������� �� 10 � 2 ������� ��������� � �������������� �����.

int Stack[100]; //������ ���� �� ������ �������
int Cursor = -1; //����� ������ �����, ������ ��� � -1

void Solution1() {
	int num;
	printf("Please input number to convert to binary number ");
	scanf("%d", &num);

	//��������� ����
	do {
		array_stack_push(num % 2);
		//printf("%d", num % 2);
		num /= 2;
	} while (num != 0);

	//������� ����
	do {
		printf("%d", array_stack_pop());
	} while (Cursor >= 0);
	printf("\n");

}

//����

void array_stack_push(int var) {

	if (Cursor > 100 - 1) {
		printf("Stack is full, cannot add new element\n");
		return;
	}

	Cursor++;
	Stack[Cursor] = var;
}

int array_stack_pop() {
	int temp;

	if (Cursor < 0) {
		printf("Stack is empty\n");
		return -1;
	}

	temp = Stack[Cursor];
	Cursor--;
	return temp;
}


char * stack_create(const unsigned size) {
	char *p = (char *)malloc(sizeof(char) * (size + 1));
	p[0] = 1;
	return p;
}

void stack_destroy(char *stack) {
	free(stack);
}

void stack_push(char *stack, char value) {
	stack[stack[0]] = value;
	stack[0]++;
}

char stack_pop(char *stack) {
	stack[0]--;
	char value = stack[stack[0]];
	return value;
}

//3. �������� ���������, ������� ����������, �������� �� ��������� ��������� ������������������ 
//����������.������� ���������� ��������� ��������� : (), ([])(), {}(), ([{}]), ������������ � )(, ())({ ), (, ]) }), ([(]) ��� ������[, (, { .
//��������: (2 + (2 * 2)) ���[2 / {5 * (4 + 7)}]
void Solution3() {

	char string[50];
	char *char_stack = stack_create(50);


	printf("please input formula: \n");

	scanf("%s", &string);



	unsigned i = 0;
	printf("FORMULA: ");

	do {
		printf("%c", *(string + i));

		i++;
	} while (*(string + i) != '\0');

	i = 0;

	do {
		printf("%�", *(string + i));

		if (IsOpenBracket(*(string + i)))
			stack_push(char_stack, *(string + i));

		if (IsCloseBracket(*(string + i))) {
			if (getReverceBracket(*(string + i)) != stack_pop(char_stack))
			{
				printf("Brackets does not comply. Fail.\n");
				break;
			}
		}
		i++;

		//������� �� ��� �������
	} while (*(string + i) != '\0');

	printf("\n");



}
int IsOpenBracket(char c) {
	char *openbrackets = "{[(";
	unsigned i = 0;

	do {
		if (c == openbrackets[i])
			return 1;
		i++;
	} while (*(openbrackets + i) != '\0');

	return 0;
}

int IsCloseBracket(char c) {
	char *closebrackets = "}])";
	unsigned i = 0;

	do {
		if (c == closebrackets[i])
			return 1;
		i++;
	} while (*(closebrackets + i) != '\0');

	return 0;
}

//����������� �� �����������
//�������� �����������
char getReverceBracket(char c) {
	char *openbrackets = "{[(";
	char *closebrackets = "}])";

	printf("\n");

	unsigned i = 0;
	do {
		printf("%c vs ", c);
		printf("%c", *(closebrackets + i));

		if (c == (*(closebrackets + i)))
			return (*(openbrackets + i));
		i++;
	} while (*(closebrackets + i) != '\0');

	return '\0';
}