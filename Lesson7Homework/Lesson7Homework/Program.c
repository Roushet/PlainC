#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MTX(row, col) (mtx + row * 6 + col)

//Владимир Евдокимов
//1. Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран
//2. Написать функцию поиска точки в графе алгоритмом Дейкстры


void Solution1();
void Solution2();

bool dijkstra(unsigned start, unsigned end, unsigned *mtx, unsigned *out, unsigned *values, unsigned *vertexes);
//void Solution3();

int main() {

	unsigned sel = 0;

	printf("Hello! Welcome to Lesson 7 homework\n\nUse numbers between 1 and 2 to select an excercice. Enter 0 to exit.\n\n");
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

		default:
			printf("Please use numbers between 1 and 2\n0 for exit.\n");
			break;
		}
	} while (sel != 0);

	return 0;
}

void Solution1() {
	unsigned arr_size;
	int **arr; //������������ ��������� ������ - ������ ���������� �� ���������� �������
	unsigned i = 0;
	unsigned j = 0;

	FILE *file = fopen("matrix.txt", "r");

	if (file == NULL) {
		printf("File error, breaking execution\n");
		return;
	}

	//������ ������ �������
	fscanf(file, "%d", &arr_size);

	//�������� ������ ��� ������ �������� �������

	arr = malloc(sizeof(int*)*arr_size);  //������

	for (i = 0; i < arr_size; i++)
		arr[i] = malloc(sizeof(unsigned)*arr_size); //�������

	for (i = 0; i < arr_size; i++) {
		for (j = 0; j < arr_size; j++) {
			if (fscanf(file, "%d", &arr[i][j]) == EOF)
				printf("Array size error\n");
		}
	}

	//�������� ������
	for (i = 0; i < arr_size; i++) {
		for (j = 0; j < arr_size; j++) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	_fcloseall();
}

void Solution2() {
	unsigned v;
	unsigned * mtx;
	bool * out;
	unsigned * values;
	unsigned * vertexes;

	mtx = (unsigned *)malloc(sizeof(unsigned) * 6 * 6);
	out = (bool *)malloc(sizeof(bool) * 6);
	values = (unsigned *)malloc(sizeof(unsigned) * 6);

	//����: ������� ����
	vertexes = (unsigned *)malloc(sizeof(unsigned) * 6);

	//������� �����
	for (v = 0; v < 36; v++)
		mtx[v] = 0;

	for (v = 0; v < 6; v++) {
		//������ ������� � ��������� �������
		out[v] = false;
		//������ ���������� ������ � ������� �� ������, �������������� �������� �������� ���������� ��� ���� � �����
		values[v] = 100;
	}

	//�� 1 � 2 � �������
	*MTX(0, 1) = *MTX(1, 0) = 3;
	//�� 1 � 5 � �������
	*MTX(0, 4) = *MTX(4, 0) = 11;

	//�� 2 � 3 � �������
	*MTX(1, 2) = *MTX(2, 1) = 7;
	//�� 2 � 6 � �������
	*MTX(1, 5) = *MTX(5, 1) = 1;

	//�� 1 � 3 � �������
	*MTX(2, 3) = *MTX(3, 2) = 15;
	//�� 1 � 4 � �������
	*MTX(2, 5) = *MTX(5, 2) = 6;

	//�� 5 � 6 � �������
	*MTX(4, 5) = *MTX(5, 4) = 9;

	//������� ������� ���������
	for (v = 0; v < 36; v++) {

		if ((v + 1) % 6 == 0)
			printf("%d\n", mtx[v]);
		else
			printf("%d\t", mtx[v]);
	}
	printf("\n");

	//���� ���� �� 0 � 5
	dijkstra(0, 5, mtx, out, values, vertexes);

	printf("path:\t", mtx[v]);
	for (v = 0; v < 6; v++)
		printf("%d\t", vertexes[v]);

	printf("\n");
}

bool dijkstra(unsigned start, unsigned end, unsigned *mtx, unsigned *out, unsigned *values, unsigned *vertexes) {

		//получаем номер строки
		//проверяем были ли мы там
		//пробегаемся по ней
		//	находим минимальное
		//		записываем номер вершины в вершины
		//		записываем величину ребра в рёбра

		//метим себя как посещенную
		//вызываем себя на мин вершину

	unsigned i, j;
	//���� ����� ��� �������� - �������
	if (out[start] == true)
		return false;

	//���� �������� ���� - �������
	if (start == end)
		return true;


	for (j = 0; j < 6; j++) {

		//������� ����������� �������� �����
		if (*MTX(start, j) > 0 && *MTX(start, j) < values[start]) {

			//���������� ����������� �������� ����� � ������
			values[start] = *MTX(start, j);
			vertexes[start] = j;
		}
		//���������� ����� ����� � ����������� ������ � ������
		//�������� ����� ��� �����������
		out[start] = true;
	}
	//�������� �������� ��� ����������� �����
	dijkstra(vertexes[start], end, mtx, out, values, vertexes);
}


