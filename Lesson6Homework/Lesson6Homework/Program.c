#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

void Solution1();
void Solution2();
//void Solution3();

void print(struct STree * elem);

int hashFor(char *str);

//Владимир Евдокимов

//1. +
//2. 
//
//а) +/-
//б) +
//в) * -
//3.* -


int main() {

	unsigned sel = 0;

	printf("Hello! Welcome to Lesson 6 homework\n\nUse numbers between 1 and 2 to select an excercice. Enter 0 to exit.\n\n");
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
			printf("Please use numbers between 1 and 3\n0 for exit.\n");
			break;
		}
	} while (sel != 0);

	return 0;
}

//1. Реализовать простейшую хэш - функцию.На вход функции подается строка, на выходе сумма кодов символов.
void Solution1() {

	//char *str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
	char str[100];

	printf("Please input string up to 100 symbols to hash: ");
	scanf("%s", &str);
	printf("hash: %u\n", hashFor(str));
}

//Простое суммирование значений символов
//int hash(char *str) {
//
//	int hash = 0;
//	do {
//		//printf("%d\n", *str);
//		hash += *str;
//		str++;
//	} while (*(str) != '\0');
//	//printf("\n");
//	return hash;
//}

//Алгоритм Rot13 отсюда:
//https://sohabr.net/post/219139/ 

int hashFor(char *str) {
	unsigned hash = 0;
	//printf("%u\n", hash - 1);

	for (; *str; str++) {
		hash += *str; 
		//за основу берётся аски текущий символ
		//сдвигается влево на 13, сдвигается вправо на 19, 
		//результаты складываются логическим ИЛИ и 
		//вычитается из 2 в степени 32 + основа
		hash -= (hash << 13) | (hash >> 19); 
		//printf("%d\n", *str);
		//printf("%d\n", hash);
	}
	return hash;
}

//2. Переписать программу, реализующее двоичное дерево поиска.
//
//а) Добавить в него обход дерева различными способами;
//б) Реализовать поиск в двоичном дереве поиска;

void Solution2() {
	int sequence[10] = {5, 55, 3, 11, 9, -3, 8, 15, -7, 73 };
	unsigned i = 0;
	
	//	tree_add(tree->left->right, 11, false);

	//инициализация корневого элемента
	struct STree * tree = tree_create(sequence[0]);
	
	//Заполнение дерева
	for (i = 1; i < 10; i++) 
		tree_build_binary(tree, sequence[i]);


	struct STree * search = tree_search(tree, 9);
	
	// не проверяю на нул, потому что и так понятно что значение найдено
	printf("search %d", search->value);

	tree_tour(tree, &print);

	tree_destroy(tree);

}

void print(struct STree * elem)
{
	printf("next element = %d\n", elem->value);
}
