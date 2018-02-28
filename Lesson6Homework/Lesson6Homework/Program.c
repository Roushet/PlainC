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

//�������� ���������

//1. +
//2. 
//
//�) +/-
//�) +
//�) * -
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

//1. ����������� ���������� ��� - �������.�� ���� ������� �������� ������, �� ������ ����� ����� ��������.
void Solution1() {

	//char *str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
	char str[100];

	printf("Please input string up to 100 symbols to hash: ");
	scanf("%s", &str);
	printf("hash: %u\n", hashFor(str));
}

//������� ������������ �������� ��������
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

//�������� Rot13 ������:
//https://sohabr.net/post/219139/ 

int hashFor(char *str) {
	unsigned hash = 0;
	//printf("%u\n", hash - 1);

	for (; *str; str++) {
		hash += *str; 
		//�� ������ ������ ���� ������� ������
		//���������� ����� �� 13, ���������� ������ �� 19, 
		//���������� ������������ ���������� ��� � 
		//���������� �� 2 � ������� 32 + ������
		hash -= (hash << 13) | (hash >> 19); 
		//printf("%d\n", *str);
		//printf("%d\n", hash);
	}
	return hash;
}

//2. ���������� ���������, ����������� �������� ������ ������.
//
//�) �������� � ���� ����� ������ ���������� ���������;
//�) ����������� ����� � �������� ������ ������;

void Solution2() {
	int sequence[10] = {5, 55, 3, 11, 9, -3, 8, 15, -7, 73 };
	unsigned i = 0;
	
	//	tree_add(tree->left->right, 11, false);

	//������������� ��������� ��������
	struct STree * tree = tree_create(sequence[0]);
	
	//���������� ������
	for (i = 1; i < 10; i++) 
		tree_build_binary(tree, sequence[i]);


	struct STree * search = tree_search(tree, 9);
	
	// �� �������� �� ���, ������ ��� � ��� ������� ��� �������� �������
	printf("search %d", search->value);

	tree_tour(tree, &print);

	tree_destroy(tree);

}

void print(struct STree * elem)
{
	printf("next element = %d\n", elem->value);
}
