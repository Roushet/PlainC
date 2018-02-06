#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 1000
#define  ITERATIONS 1000

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

//Владимир Евдокимов
//Задачу 3 (двоичный поиск - не делал, мы её сделали на уроке)

//счётчик операций
unsigned count;

void Solution1();
void Solution2();
void Solution3();

void BubbleSort(unsigned * array, const unsigned N);
void Swap(unsigned* a1, unsigned* a2);
unsigned Compare(unsigned a1, unsigned a2);
void ShakerSort(unsigned* array, const unsigned N);
void FillArray(unsigned* array, const unsigned N);

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
			Solution3();
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
	//printf("COUNT %d \n", count);
	//count = 0;
}

//функция сравнения элементов со счётчиком
unsigned Compare(unsigned a, unsigned b) {

	count++;

	if (a > b) return 1;
	else return 0;
}

//функция обмена элементов со счётчиком
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
	int changed;
	int shaker = 1; // число для проверки кратности прохода

	for (i = 0; i < N; i++)
	{
		changed = 0;

		if (shaker % 2 == 1)
		{
			//слева направо
			for (j = 0; j < N - 1; j++)
			{
				//если элемент слева больше элемента справа
				if (Compare(array[j], array[j + 1])) {
					Swap(&array[j], &array[j + 1]);
					changed = 1;
				}
			}
		}
		else
		{
			//справа налево
			for (j = N - 1; j >= 1; j--)
			{
				//если элемент справа меньше элемента слева
				if (Compare(array[j - 1], array[j])) {
					Swap(&array[j], &array[j - 1]);
					changed = 1;
				}
			}
		}
		shaker++;

		//если не было изменений - прервать цикл
		if (changed = 0) break;
	}

	//printf("COUNT %d \n", count);
	//count = 0;
}

//4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.

void Solution3() {

	unsigned array[ARR_SIZE];
	clock_t startTime;
	clock_t endTime;
	unsigned i;
	double averageBuble = 0;
	double averageShaker = 0;


	for (i = 0; i < ITERATIONS; i++) {

		//Создаём большие массивы
		//Заполняем их рандомами
		FillArray(array, ARR_SIZE);

		//сортируем пузырьком
		startTime = clock();
		BubbleSort(array, ARR_SIZE);
		endTime = clock();

		//считаем среднее время для пузырька
		averageBuble += (double)(endTime - startTime) / CLOCKS_PER_SEC;

		printf("Iteration %d\t %lf\t %d ", i, (double)(endTime - startTime) / CLOCKS_PER_SEC, count);
		
		count = 0;
		FillArray(array, ARR_SIZE);


		startTime = clock();
		ShakerSort(array, ARR_SIZE);
		endTime = clock();

		averageShaker += (double)(endTime - startTime) / CLOCKS_PER_SEC;

		printf("%lf\t %d \n", (double)(endTime - startTime) / CLOCKS_PER_SEC, count);
		count = 0;
	}

	printf("Average buble sort time %lf \n", averageBuble / (double) ITERATIONS);
	printf("Average shaker sort time %lf \n", averageShaker / (double)ITERATIONS);

}

//Ассимптотическая сложность N^2, при размере массива 1000, получается 1 000 000
//Количество вызовов на сортировке массива с 1000 случайных элементов получается примерно 1 200 000

//Почему то шейкерная сортировка не даёт особой выгоды, возможно, я не докодил что-то в ней. Возможно там после каждого 
//второго прохода надо сужать интервал

void FillArray(unsigned* array, const unsigned N) {
	unsigned i = 0;
	
	srand(time(NULL));   

	for (i = 0; i < N; i++) {
		array[i] = rand();
	}

}