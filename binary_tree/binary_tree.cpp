#include "binary_tree.h"

#include <iostream>
#include <vector>
#include <queue>

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

binary_tree::~binary_tree()
{
    destroy(root);
}

void binary_tree::print()
{
    if (!root)
    {
        return;
    }

    int height = get_height(root);

    queue<btree_node*> q;
    q.push(root);

    auto nodes_in_level = 1;
    for (auto level = 0; level < height; ++level)
    {
        int spaces = pow(2, height - level) - 1;
        int between = pow(2, height - level + 1) - 1;

        for (int i = 0; i < spaces; ++i)
        {
            cout << " ";
        }

        vector<btree_node*> next_level;
        for (int i = 0; i < nodes_in_level; ++i)
        {
            btree_node* node = q.front();
            q.pop();

            if (node)
            {
                cout << node->value;
                next_level.push_back(node->left);
                next_level.push_back(node->right);
            }
            else
            {
                cout << " ";
                next_level.push_back(nullptr);
                next_level.push_back(nullptr);
            }

            for (int j = 0; j < between; ++j)
            {
                cout << " ";
            }
        }
        cout << endl;

        for (auto node : next_level)
        {
            q.push(node);
        }
        nodes_in_level *= 2;
    }
}

bool binary_tree::find(int key)
{
    auto tmp = find(root, key);
    if (!tmp)
    {
        return false;
    }
    return true;
}

void binary_tree::insert(int key)
{
    root = insert(root, key);
}

void binary_tree::remove(int key)
{
    root = remove(root, key);
}

void binary_tree::destroy(btree_node* node)
{
    if (!node)
    {
        return;
    }

    destroy(node->left);
    destroy(node->right);
    delete node;
}

int binary_tree::get_height(btree_node* root)
{
    if (!root)
    {
        return 0;
    }

    return 1 + max(get_height(root->left), get_height(root->right));
}

btree_node* binary_tree::find_min(btree_node* node)
{
    while (node && node->left)
    {
        node = node->left;
    }
    return node;
}

btree_node* binary_tree::find(btree_node* node, int key)
{
    if (!node || node->value == key)
    {
        return node;
    }

    if (key < node->value)
    {
        return find(node->left, key);
    }
    else
    {
        return find(node->right, key);
    }
}

btree_node* binary_tree::remove(btree_node* node, int key)
{
    if (!node)
    {
        return nullptr;
    }

    if (key < node->value)
    {
        node->left = remove(node->left, key);
    }
    else if (key > node->value)
    {
        node->right = remove(node->right, key);
    }
    else
    {
        if (!node->left)
        {
            btree_node* tmp = node->right;
            delete node;
            return tmp;
        }
        else if (!node->right)
        {
            btree_node* tmp = node->left;
            delete node;
            return tmp;
        }

        btree_node* successor = find_min(node->right);
        node->value = successor->value;
        node->right = remove(node->right, successor->value);
    }

    return node;
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

    return node;
}

}