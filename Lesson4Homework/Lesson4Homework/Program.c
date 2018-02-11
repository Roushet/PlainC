#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

#define SIZE 8

void Solution1();

unsigned WayCount(unsigned x, unsigned y);

void Solution2();

unsigned strLen(char *str);
unsigned len(char * A, char * B);
unsigned Matrix(char * A, char * B);
unsigned MatrixMax(char * A, char * B);

//1. *Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.
//Например, карта:
//3 3
//1 1 1
//0 1 0
//0 1 0

//2. Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.

//3. ***Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по одному 
// разу.Здесь алгоритм решения такой же как и в задаче о 8 ферзях.Разница только в проверке положения коня.


int main() {

	unsigned sel = 0;

	printf("Hello! Welcome to Lesson 4 homework\n\nUse numbers between 1 and 3 to select an excercice. Enter 0 to exit.\n\n");
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
			//Solution3();
			break;

		default:
			printf("Please use numbers between 1 and 3\n0 for exit.\n");
			break;
		}
	} while (sel != 0);

	return 0;
}

unsigned field[SIZE][SIZE] = {
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 1, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
};


void Solution1() {
	//5
	printf("Ways count %d\n", WayCount(0, 0));

}

unsigned WayCount(unsigned x, unsigned y) {
	if (x == 5 && y == 5)
		return 1;

	if (field[x][y] == 1)
		return 0;

	if (x > 5 || y > 5)
		return 0;

	return WayCount(x, y + 1) + WayCount(x + 1, y);
}

void Solution2() {

	unsigned i = 0;
	char *str1 = "geekbrains";
	char *str2 = "geekminds";

	//for (i = 0; i < 20; i++) {
	//	printf("%c \n", *(str1 + i));
	//	
	//	if (*(str1 + i) == '\0') break;
	//}

	do {
		i++;
		printf("%c", *(str1 + i));
	} while (*(str1 + i) != '\0');

	printf("%d \n", i);

	//printf("%d \n", len(str1, str2));
}

unsigned Matrix(char *str1, char *str2) {
	unsigned len1, len2;
	
	len1 = strLen(str1); //строка
	len2 = strLen(str2); //столбец

	unsigned i = 0;

	unsigned **mat; //динамический двумерный массив - массив указателей на одномерные массивы

	mat = malloc(sizeof(unsigned*)*len1);  //строки

	for (i = 0; i < len1; i++)
		mat[i] = malloc(sizeof(unsigned)*len2); //столбцы

	//заполняем матрицу
	//https://foxford.ru/wiki/informatika/naibolshaya-obschaya-podposledovatelnost

	//если буква

}

unsigned strLen(char *str) {
	unsigned i = 0;
	do {
		i++;
	} while (*(str + i) != '\0');

	return i;
}

unsigned len(char * A, char * B)
{
	if (*A == '\0' || *B == '\0')
		return 0;

	if (*A == *B)
		return 1 + len(A + 1, B + 1);

	return max(
		len(A + 1, B),
		len(A, B + 1));
}


unsigned MatrixMax(char * A, char * B) {
	return 1;
}
