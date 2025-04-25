#pragma once

namespace maxim_ds
{

struct btree_node;

class binary_tree
{
public:
	binary_tree();
	~binary_tree();

	void postorder_print();
	void insert(int key);
	void remove(int key);

private:
	btree_node* insert(btree_node* node, int key);

private:
	btree_node* root;
};

}