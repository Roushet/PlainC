#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

//Владимир Евдокимов
//Не понял третью задачу. Надо сделать обратные вычисления для калькулятора? Т.е. из допустим 20 получить 3 за минимум шагов?

void Solution1();
void DivByTwo();
void Solution2();
unsigned RecPower();
void Solution3();
unsigned CountOnes();

int main() {

	printf("%d", 10 >> 1);

	unsigned sel = 0;
	printf("Hello! Welcome to Lesson 1 homework\n\nUse numbers between 1 and 3 to select an excercice. Enter 0 to exit.\n\n");
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
			//22
		default:
			printf("Please use numbers between 1 and 3\n0 for exit.\n");
			break;
		}
	} while (sel != 0);

	return 0;
}


//1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
void Solution1() {
	unsigned num;
	//
	printf("Input decimal number: ");
	scanf("%d", &num);
	//
	printf("Binary number: ");
	DivByTwo(num);
	//прямая конверсия циклом выдает число задом наперёд
	//do {
	//	printf("%d", num % 2);
	//	num /= 2;
	//} while (num != 0);

	printf("\n");
}

void DivByTwo(unsigned num) {

	if (num == 0)
		return;

	DivByTwo(num >> 1);
	printf("%d", num % 2);
}


//2. Реализовать функцию возведения числа a в степень b :
//
//a.без рекурсии;
//b.рекурсивно;
//c. *рекурсивно, используя свойство чётности степени(если степень четная, то умножение ТЕКУЩИЙ_РЕЗУЛЬТАТ * a заменить на ТЕКУЩИЙ_РЕЗУЛЬТАТ * ТЕКУЩИЙ_РЕЗУЛЬТАТ).

void Solution2() {
	unsigned num;
	unsigned power;
	unsigned result;
	unsigned power_;

	printf("Input number:");
	scanf("%d", &num);

	printf("Input power:");
	scanf("%d", &power);
	power_ = power;

	printf("Without recursion: ");
	result = num;
	do {
		result *= num;
		power -= 1;
	} while (power > 1);

	printf("%d\n", result);

	result = 0;
	printf("With recrusion: ");
	printf("%d\n", RecPower(num, power_));

}

unsigned RecPower(unsigned num, unsigned pow) {
	unsigned temp;

	if (pow == 1) return num;

	if (pow % 2 == 0) {
		temp = RecPower(num, pow >> 1);
		return  temp * temp;
	}
	else
	{
		return  num * RecPower(num, pow - 1);
	}

}

//Не понял задание

//3. Исполнитель Калькулятор преобразует целое число, записанное на экране.
//У исполнителя две команды, каждой команде присвоен номер :
//
//Прибавь 1
//Умножь на 2
//
//Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза.
//а) с использованием массива;
//б) с использованием рекурсии.
//
//Сколько существует программ(т.е.комбинаций операций 1 и 2), которые число 3 преобразуют 
//в число 20 ?

void Solution3() {
	unsigned goal;
	unsigned current = 1;
	unsigned input;
	unsigned count = 0;

	printf("Input your goal number: ");
	scanf("%d", &goal);



	do
	{
		printf("Please input command 1: +1; 2: *2. Your choise: ");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			current += 1;
			break;
		case 2:
			current *= 2;
			break;
		default:
			printf("Wrong command, please input 1 or 2");
			break;
		}
		printf("Current value is %d; goal is %d\n", current, goal);

	} while (current < goal);

	if (current == goal) printf("You have matched the goal\n");
	if (current > goal) printf("You have missed the goal\n");

}

