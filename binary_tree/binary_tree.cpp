#include "binary_tree.h"

#include <iostream>
#include <vector>

using namespace std;

namespace maxim_ds
{

struct btree_node
{
	btree_node(int value)
		: value(value)
		, left(nullptr)
		, right(nullptr)
	{}

	int value;
	btree_node* left;
	btree_node* right;
};

binary_tree::binary_tree()
	: root(nullptr)
{}

void binary_tree::postorder_print()
{
	vector<vector<int>> values{};
	
}

void binary_tree::insert(int key)
{
	root = insert(root, key);
}

btree_node* binary_tree::insert(btree_node* node, int key)
{
	if (!node)
	{
		return new btree_node(key);
	}

	if (key < node->value)
	{
		node->left = insert(node->left, key);
	}
	else if (key > node->value)
	{
		node->right = insert(node->right, key);
	}
}

}