
#include "tree.h"

struct STree * tree_create(const int value)
{
	struct STree * tree = (struct STree *) malloc(sizeof(struct STree));

	ASSERT(tree != NULL, "Failed on tree create");

	tree->value = value;
	tree->left = NULL;
	tree->right = NULL;
	tree->parent = NULL;
	//
	return tree;
}

void tree_destroy(struct STree * tree)
{
	struct STree * right = tree->right;
	struct STree * left = tree->left;

	free(tree);

	if (right != NULL)
		tree_destroy(right);

	if (left != NULL)
		tree_destroy(left);
}

struct STree * tree_add(struct STree * parent, const int value, const bool is_left)
{
	if ((is_left && parent->left != NULL) || (!is_left && parent->right != NULL))
		return NULL;

	struct STree * elem = (struct STree *) malloc(sizeof(struct STree));

	ASSERT(elem != NULL, "Failed on add element");

	if (is_left)
		parent->left = elem;
	else
		parent->right = elem;

	elem->value = value;
	elem->parent = parent;
	elem->left = NULL;
	elem->right = NULL;

	return elem;
}

//рекурсивный метод заполнения дерева
void tree_build_binary(struct STree *tree, int value) {

	//если значение больше значения дерева - то идём направо
	if (tree->value < value) {
		//если справа нул, то создать новое дерево и поместить
		if (tree->right == NULL)
			tree_add(tree, value, false);
		//если элемент не нул вызвать себя, т.е. передать value далее вниз по дереву
		else
			tree_build_binary(tree->right, value);
	}
	//если у дерева есть значение но value меньше - проверить левый элемент
	else
	{
		//если нул, то создать новое дерево и поместить
		if (tree->left == NULL)
			tree_add(tree, value, true);
		//если элемент не нул вызвать себя, т.е. передать value далее вниз по дереву
		else
			tree_build_binary(tree->left, value);
	}
}


//поиск по дереву, принимает дерево и значение, возвращает элемент или нулл, если не нашёл
struct STree * tree_search(struct STree *tree, int value) {
	

	//если корневое значение = искомому - вернуть корень
	if (tree->value == value)
		return tree;

	//если значение больше, чем текущее - идти направо
	if (tree->value < value) 
		return tree_search(tree->right, value);
	
	//или идти налево
	else 
		return tree_search(tree->left, value);
	
	//если ничего нет - возвращает нулл
	return NULL;
}


void tree_tour(struct STree * tree, void(*func)(struct STree *))
{
	if (tree != NULL)
	{
		(*func)(tree);

		tree_tour(tree->left, func);
		tree_tour(tree->right, func);
	}
}

void tree_tour_lr_root(struct STree * tree, void(*func)(struct STree *))
{
	if (tree != NULL)
	{
		tree_tour(tree->left, func);
		(*func)(tree);
		tree_tour(tree->right, func);
	}
}


