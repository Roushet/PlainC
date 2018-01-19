#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int sel = 0;
	printf("Hello! Welcome to Lesson 1 homework\n\nUse numbers between 1 and 6 to select an excercice. Enter 0 to exit.\nPlease select an excercise:\n");
	do {
		scanf("%i", &sel);

		switch (sel)
		{
		case 1:
			printf("Selected 1\n");
			break;
		case 2:
			printf("Selected 1\n");
			break;
		case 3:
			printf("Selected 1\n");
			break;
		case 4:
			printf("Selected 1\n");
			break;
		default:
			printf("Please use numbers between 1 and 6\n");
			break;
		}
	} while (sel != 0);

	return 0;

}
