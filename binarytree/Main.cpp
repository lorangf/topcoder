
#include <cstdlib>
#include <iostream>
#include <vector>

#include "BinaryTree.h"

using namespace std;

int main(int argc, char* argv[])
{
	vector<int> vec;
	int n=10;
	vec.reserve(n);

	//srand(34);
	//for(int i=0; i<n; i++)
	//	vec.push_back(rand()%50);
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(10);
	vec.push_back(12);
	vec.push_back(7);
	vec.push_back(4);

	cout << "Random nodes: ";
	for(vector<int>::iterator it=vec.begin(); it != vec.end(); ++it)
			cout << *it << " ";
	cout << endl;

	BinaryTree* tree = new BinaryTree();

	tree->insertElements(vec);

	cout << "Pre Order: ";
	tree->printNodes(PRE_ORDER);
	cout << "In Order: ";
	tree->printNodes(IN_ORDER);
	cout << "Post Order: ";
	tree->printNodes(POST_ORDER);
	
	cout << "Height = " << tree->height() << endl;
	cout << "Pre order, no recursion: ";
	tree->printNodesNoRecursion();

	Node* common = NULL;
	cout << "Common Ancestor 4,2 (expect 3): ";
	common = tree->findCommonAncestor(4,2);
	if ( common ) cout << common->value();
	else cout << "NULL";
	cout << endl;

	cout << "Common Ancestor 3,12 (expect 5): ";
	common = tree->findCommonAncestor(3,12);
	if ( common ) cout << common->value();
	else cout << "NULL";
	cout << endl;
	
	delete tree;
	return 0;
}

