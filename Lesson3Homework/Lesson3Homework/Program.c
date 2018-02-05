//1. Попробовать оптимизировать пузырьковую сортировку.Сравнить количество операций сравнения оптимизированной и 
//не оптимизированной программы.Написать функции сортировки, которые возвращают количество операций.

//3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив.Функция возвращает 
//индекс найденного элемента или - 1, если элемент не найден.
//4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

//счётчик операций
unsigned count;

void Solution1();
void Solution2();

void BubbleSort(unsigned * array, const unsigned N);
void Swap(unsigned* a1, unsigned* a2);
unsigned Compare(unsigned a1, unsigned a2);
void ShakerSort(unsigned* array, const unsigned N);

int main() {

	unsigned sel = 0;

	printf("Hello! Welcome to Lesson 3 homework\n\nUse numbers between 1 and 4 to select an excercice. Enter 0 to exit.\n\n");
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

//1. Попробовать оптимизировать пузырьковую сортировку.Сравнить количество операций сравнения оптимизированной и 
//не оптимизированной программы.Написать функции сортировки, которые возвращают количество операций.
void Solution1() {
	unsigned arr[10] = { 6, 5, 1, 3, 9, 4, 8 ,7, 2, 0 };
	unsigned i;

	BubbleSort(arr, 10);

	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	printf("\n");
}


void BubbleSort(unsigned* array, const unsigned N)
{
	unsigned i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - 1; j++)
		{
			if (Compare(array[j], array[j + 1])) {
				Swap(&array[j], &array[j + 1]);

				//temp = array[j];
				//array[j] = array[j + 1];
				//array[j + 1] = temp;
			}
		}
	}
}

unsigned Compare(unsigned a, unsigned b) {

	count++;

	if (a > b) return 1;
	else return 0;
}

void Swap(unsigned* a, unsigned* b) {
	count++;

	unsigned temp = *a;
	*a = *b;
	*b = temp;
}


//2. *Реализовать шейкерную сортировку.
void Solution2() {
	unsigned arr[10] = { 6, 5, 1, 3, 9, 4, 8 ,7, 2, 0 };
	unsigned i;

	ShakerSort(arr, 10);

	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	printf("\n");
}

void ShakerSort(unsigned* array, const unsigned N)
{
	unsigned i, j;
	unsigned shaker = 1;

	for (i = 0; i < N; i++)
	{
		//if (Compare(shaker % 2, 1)) {
			for (j = 0; j < N - 1; j++)
			{

				if (Compare(array[j], array[j + 1])) {
					Swap(array[j], array[j + 1]);

					//temp = array[j];
					//array[j] = array[j + 1];
					//array[j + 1] = temp;
				}
			}
		//}
		//else {
		//	for (j = N - 1; j > 0; j--)
		//	{
		//		if (Compare(array[j - 1], array[j])) {
		//			Swap(array[j], array[j - 1]);

		//			//temp = array[j];
		//			//array[j] = array[j + 1];
		//			//array[j + 1] = temp;
		//		}
		//	}
		//}
		shaker++;
	}
}
