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


//Владимир Евдокимов

//1. Реализовать перевод из 10 в 2 систему счисления с использованием стека.

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
