#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

# define ASSERT(cond, msg) \
{\
	if (!(cond)) \
	{\
		fprintf(stderr, msg); \
		exit(-1); \
	}\
}

void Solution1();

void array_stack_push(int var);
int array_stack_pop();

void Solution2();
void Solution3();

char * stack_create(const unsigned size);
void stack_destroy(char *stack);
void stack_push(char *stack, char value);
char stack_pop(char *stack);

int IsOpenBracket(char c);
int IsCloseBracket(char c);
char getReverceBracket(char c);

void Solution6();
int * queue_create(const unsigned size);
void queue_destroy(int *queue);
void queue_push(int *queue, int value);
int queue_pop(int *queue);

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
		case 6:
			Solution6();
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
	ASSERT(p != NULL, "Failed to allocate memory");
	p[0] = 1;
	return p;
}

void stack_destroy(char *stack) {
	ASSERT(stack != NULL, "Stack does not exist");
	free(stack);
}

void stack_push(char *stack, char value) {
	ASSERT(stack != NULL, "Stack does not exist");

	stack[stack[0]] = value;
	stack[0]++;
}

char stack_pop(char *stack) {
	stack[0]--;
	char value = stack[stack[0]];
	return value;
}

//2. �������� � ��������� ����������� ����� �� ������ ������������ ������� �������� �� 
//��������� ������.���� ������ �� ����������, �� ��������� ��������������� ���������.������������ ������� 
//��������, ����� ������ �� ����� ����������(����������� �������� ���������� ������).

void Solution2() {
	//1 410 065 408
	char *char_stack = stack_create(10000000000);
	stack_push(char_stack, "J");

	//printf("POP: %c!\n", stack_pop(char_stack));

}



//3. �������� ���������, ������� ����������, �������� �� ��������� ��������� ������������������ 
//����������.������� ���������� ��������� ��������� : (), ([])(), {}(), ([{}]), ������������ � )(, ())({ ), (, ]) }), ([(]) ��� ������[, (, { .
//��������: (2 + (2 * 2)) ���[2 / {5 * (4 + 7)}]
void Solution3() {

	char string[50];
	char *char_stack = stack_create(50);
	char current;
	int errFlag = 0;

	printf("Please input formula (or just brackets): \n");

	scanf("%s", &string);

	unsigned i = 0;
	//printf("FORMULA: ");

	//do {
	//	printf("%c", *(string + i));

	//	i++;
	//} while (*(string + i) != '\0');

	i = 0;

	do {
		current = *(string + i);
		//printf("%�", current); //������ �� ��� ������ �������� � 

		if (IsOpenBracket(current))
			stack_push(char_stack, current);

		if (IsCloseBracket(current)) {
			if (getReverceBracket(current) != stack_pop(char_stack))
			{
				printf("Error. Brackets does not comply. Fail.\n");
				errFlag = 1;
				break;
			}
		}
		i++;
	} while (current != '\0');

	//printf("POP: %c!\n", stack_pop(char_stack));

	//���� � ����� �������� ����������� ������ - ������
	if (stack_pop(char_stack) != '\0') {
		errFlag = 1;
		printf("Error. Brackets does not comply. Fail.\n");
	}


	if (errFlag == 0)
		printf("OK: Formula does not contain bracket errors");

	// ������� ������
	stack_destroy(char_stack);
	errFlag = 0;
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

//�������� ����������� �� �������� �����������
//��������� �����������
char getReverceBracket(char c) {
	char *openbrackets = "{[(";
	char *closebrackets = "}])";

	//printf("\n");

	unsigned i = 0;
	do {
		//printf("%c vs ", c);
		//printf("%c", *(closebrackets + i));

		if (c == (*(closebrackets + i)))
			return (*(openbrackets + i));
		i++;
	} while (*(closebrackets + i) != '\0');

	return '\0';
}

//6. *����������� �������.

void Solution6() {
	int *int_queue = queue_create(3);

	queue_push(int_queue, 10);
	queue_push(int_queue, 20);
	queue_push(int_queue, 30);
	printf("%d\n", queue_pop(int_queue));
	queue_push(int_queue, 40);
	//--
	printf("%d\n", queue_pop(int_queue));
	printf("%d\n", queue_pop(int_queue));
	printf("%d\n", queue_pop(int_queue));
	printf("%d\n", queue_pop(int_queue));

	//������� ��������� ������
	//������� ������� ������� �� ������

}

int *queue_create(const unsigned size) {
	//ASSERT(size > 0, "Bad size for queue");
	int *q = (int *)malloc(sizeof(int) * (size + 4));
	//ASSERT(q != NULL, "Failed to allocate memory for queue");

	q[0] = size; //���������� ������ �������, ����� ������������ ��� ��� ������� ������� �����
	q[1] = size; //���������� ������ �������, ����� �������������� � ���������
	q[2] = 4; //������ �� ��������� �� ������� 4
	q[3] = 4; //������ �� ��������� �� ������� 4

	return q;

}
void queue_destroy(int *queue) {
	ASSERT(queue != NULL, "Cannot destroy queue. Queue does not exist");

	free(queue);
}

void queue_push(int *queue, int value) {
	ASSERT(queue[0] > 0, "Cannot push to queue. Queue overflow");

	if (queue[3] <= queue[1] + 4 - 1) //���� ������� ������ ������ ��� ����� ������� �������
	{
		queue[queue[3]] = value;
		queue[3]++;
		queue[0]--;
	}

	if (queue[3] > queue[1] + 4 - 1) { //���� ������� ������ ������ ������� ������� - ��������� ������� � ������
		if (queue[2] > 4) //��������� ������� ������, ���� ������ ����� �� ����� ������ ������ ������
		{
			queue[3] = 4;
			queue[queue[3]] = value;
			queue[3]++;
			queue[0]--;
		}

	}
}


int queue_pop(int *queue) {
	//������ �����
	ASSERT(queue != NULL, "Cannot pop from queue. Queue does not exist");
	int value;

	if (queue[2] > queue[1] + 4 - 1) { //���� ������� ������ ������ ������� ������� - ��������� ������� � ������
			queue[2] = 4;
			value = queue[queue[2]];
			queue[2]++;
			queue[0]++;

		}
	else
	{
		value = queue[queue[2]];
		queue[2]++;
		queue[0]++;
	}

	return value;
}