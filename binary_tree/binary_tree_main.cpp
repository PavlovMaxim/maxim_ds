#include "binary_tree.h"

#include <iostream>

using namespace std;

int main()
{
	maxim_ds::binary_tree btree;
	btree.insert(5);
	btree.insert(3);
	btree.insert(7);
	btree.insert(2);
	btree.insert(4);
	btree.insert(6);
	btree.insert(8);

	//cout << "Tree before: " << endl;
	//btree.print();

	//btree.remove(2);

	//cout << "Tree after: " << endl;
	//btree.print();

	bool cond = btree.find(9);
	cout << cond << endl;
}