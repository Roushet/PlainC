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

void Solution3();
void MoveKnigth(int curPosX, int curPosY);


//Владимир Евдокимов

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
			Solution3();
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


//1. *Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.
//Например, карта:
//3 3
//1 1 1
//0 1 0
//0 1 0

void Solution1() {
	printf("Ways count %d\n", WayCount(0, 0));

}

unsigned WayCount(unsigned x, unsigned y) {
	if (x == 5 && y == 5)
		return 1;

	//проверка на препятствие
	if (field[x][y] == 1)
		return 0;

	if (x > 5 || y > 5)
		return 0;

	return WayCount(x, y + 1) + WayCount(x + 1, y);
}


//2. Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.

void Solution2() {

	unsigned i = 0;
	char *str1 = "geekbrains";
	char *str2 = "geekminds";


	
	printf("LCS matrix: %d \n", Matrix(str1, str2));

	printf("LCS recurcive %d \n", len(str1, str2));
}

//решение через матрицу
//вероятно тут ошибка в подсчётах НОС

unsigned Matrix(char *str1, char *str2) {

	unsigned len1, len2;
	unsigned i = 0;
	unsigned j = 0;

	unsigned lcs = 0;

	if (*str1 == '\0' || *str2 == '\0')
		return 0;

	len1 = strLen(str1); //строка
	len2 = strLen(str2); //столбец

	unsigned **mat; //динамический двумерный массив - массив указателей на одномерные массивы

	mat = malloc(sizeof(unsigned*)*len1);  //строки

	for (i = 0; i < len1; i++)
		mat[i] = malloc(sizeof(unsigned)*len2); //столбцы

	//заполняем матрицу нулями
	for (i = 0; i < len1; i++) {
		for (j = 0; j < len2; j++) {
			mat[i][j] = 0;
		}
	}

	for (i = 0; i < len1; i++) {
		for (j = 0; j < len2; j++) {
			printf("%d \t ", mat[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");

	for (i = 0; i < len1; i++) {
		for (j = 0; j < len2; j++) {
			//Если буквы равны
			if (*(str1 + i) == *(str2 + j)) {
				//если это первая строка
				if (i == 0) mat[i][j] = 1;
				//если не первая строка, то учитываем результат прошлой строки
				if (i > 0)
					mat[i][j] = 1; // +mat[i - 1][j];
				//если поставили значение в клетку - переходим к следующему витку цикла
				continue;
			}
		}
	}

	//Печать матрицы
	for (i = 0; i < len1; i++) {
		for (j = 0; j < len2; j++) {
			printf("%d \t ", mat[i][j]);
		}
		printf("\n");
	}

	//Длина наибольшей общей подпоследовательности = сумма измененных столбцов
	//Проходим по столбцам
	for (j = 0; j < len2; j++) {
		//по строкам
		for (i = 0; i < len1; i++)
		{
			if (mat[i][j] > 0)
			{
				lcs++;
				break; //при первом вхождении считаем что есть общая буква и прерываем цикл
			}
		}
	}

	return lcs;
}

//длина строки - нужна чтобы создать матрицу правильного размера
unsigned strLen(char *str) {
	unsigned i = 0;
	do {
		i++;
	} while (*(str + i) != '\0');

	return i;
}

//решение с урока через рекурсию
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

//3. ***Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по одному 
// разу.Здесь алгоритм решения такой же как и в задаче о 8 ферзях.Разница только в проверке положения коня.

unsigned Chessfield[8][8] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
};

unsigned movesX[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
unsigned movesY[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

//счётчик ходов
//наверное не самое лучшее решение делать счётчик для рекурсии вне рекурсии
unsigned move = 1;

void Solution3() {
	// печать поля
	unsigned i, j;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			printf("%d \t ", Chessfield[i][j]);
		}
		printf("\n");
	}
	//начинаем движение с точки 0 0, ход 1
	MoveKnigth(0, 0);
	
	printf("\n");

	// печать поля
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			printf("%d \t ", Chessfield[i][j]);
		}
		printf("\n");
	}

}

void MoveKnigth(int curPosX, int curPosY) {
	int i = 0;

	//Конь пришёл в клетку и метит её как посещённую
	Chessfield[curPosX][curPosY] = move;
	move++;

	//определяем клетку цель
	for (i = 0; i < 8; i++) {
		//printf("X %d Y %d \n", curPosX + movesX[i], curPosY + movesY[i]);

		//если клетка в пределах поля - ошибка
		if (curPosX + movesX[i] < 0 || 
			curPosY + movesY[i] < 0 || 
			curPosX + movesX[i]> 7 || 
			curPosY + movesY[i] > 7) 
		{
			return;
		}

		//если клетка не была посещена - инвариант
		if (Chessfield[curPosX + movesX[i]][curPosY + movesY[i]] == 1) {
			return;
		}

		//если клетка не была посещена - наша цель
		if (Chessfield[curPosX + movesX[i]][curPosY + movesY[i]] == 0) {
			//тогда перейти в клетку
			MoveKnigth(curPosX + movesX[i], curPosY + movesY[i]);
		}
	}
	//когда все возможности исчерпаны
	return;
}
