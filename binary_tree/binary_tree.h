#pragma once

namespace maxim_ds
{

struct btree_node;

class binary_tree
{
public:
    binary_tree();
    ~binary_tree();

    void print();
    bool find(int key);
    void insert(int key);
    void remove(int key);

private:
    void destroy(btree_node* node);
    btree_node* find_min(btree_node* node);
    int get_height(btree_node* root);
    btree_node* find(btree_node* node, int key);
    btree_node* remove(btree_node* node, int key);
    btree_node* insert(btree_node* node, int key);

private:
    btree_node* root;
};

}