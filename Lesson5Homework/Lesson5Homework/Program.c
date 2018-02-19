#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

void Solution1();

void stack_push(int var);
int stack_pop();

//void Solution2();
//void Solution3();


//Владимир Евдокимов


//2. Добавить в программу “реализация стека на основе односвязного списка” проверку на 
//выделение памяти.Если память не выделяется, то выводится соответствующее сообщение.Постарайтесь создать 
//ситуацию, когда память не будет выделяться(добавлением большого количества данных).

//3. Написать программу, которая определяет, является ли введенная скобочная последовательность 
//правильной.Примеры правильных скобочных выражений : (), ([])(), {}(), ([{}]), неправильных — )(, ())({ ), (, ]) }), ([(]) для скобок[, (, { .
//Например: (2 + (2 * 2)) или[2 / {5 * (4 + 7)}]

//4. *Создать функцию, копирующую односвязный список(то есть создает в памяти копию односвязного 
//	списка, без удаления первого списка).

//5. **Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную.

//6. *Реализовать очередь.


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
			//Solution3();
			break;

		default:
			printf("Please use numbers between 1 and 3\n0 for exit.\n");
			break;
		}
	} while (sel != 0);

	return 0;
}

//1. Реализовать перевод из 10 в 2 систему счисления с использованием стека.

int Stack[100]; //делаем стек на основе массива
int Cursor = -1; //задаём курсор стека, ставим его в -1

void Solution1() {
	int num;
	printf("Please input number to convert to binary number ");
	scanf("%d", &num);

	//заполняем стек
	do {
		stack_push(num % 2);
		//printf("%d", num % 2);
		num /= 2;
	} while (num != 0);

	//очищаем стек
	do {
		printf("%d", stack_pop());
	} while (Cursor >= 0);
	printf("\n");

}

//Стек

void stack_push(int var) {

	if (Cursor > 100 - 1) {
		printf("Stack is full, cannot add new element\n");
		return;
	}

	Cursor++;
	Stack[Cursor] = var;
}

int stack_pop() {
	int temp;

	if (Cursor < 0) {
		printf("Stack is empty\n");
		return -1;
	}

	temp = Stack[Cursor];
	Cursor--;
	return temp;
}

int * stack_create(const unsigned size);
void stack_destroy(int *stack);
void stack_push(int *stack, const int value);
int stack_pop(int *stack);

int * stack_create(const unsigned size) {
	int *p = (int *)malloc(sizeof(int) * (size + 1));
	p[0] = 1;
	return p;
}

void stack_destroy(int *stack) {
	free(stack);
}

void stack_push(int *stack, const int value) {
	stack[stack[0]] = value;
	stack[0]++;
}

int stack_pop(int *stack) {
	stack[0]--;
	int value = stack[stack[0]];
	return value;
}

void Solution2() {

}