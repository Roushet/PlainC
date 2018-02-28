
#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdbool.h>
#include "exception.h"

struct STree
{
	int value;
	struct STree * left, * right, * parent;
};

struct STree * tree_create(const int value);
void tree_destroy(struct STree * tree);
struct STree * tree_add(struct STree * parent, const int value, const bool is_left);
void tree_tour(struct STree * tree, void (* func)(struct STree *));
void tree_build_binary(struct STree *tree, int value); //заполнение дерева
struct STree * tree_search(struct STree *tree, int value); // поиск по дереву
#endif

