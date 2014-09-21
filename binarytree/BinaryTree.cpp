
#include <algorithm>
#include <iostream>

#include "BinaryTree.h"

using namespace std;

Node::~Node()
{
	if ( _left ) delete _left;
	if ( _right ) delete _right;
}

void Node::print(TraversalOrder order)
{
	if ( order == PRE_ORDER ) cout << this->value() << " ";
	if ( _left ) _left->print(order);
	if ( order == IN_ORDER ) cout << this->value() << " ";
	if ( _right ) _right->print(order);
	if ( order == POST_ORDER ) cout << this->value() << " "; 
}

// Pre-order traversal
void Node::printNoRecursion()
{
	NodeStack* stack = new NodeStack();
	stack->push(this);

	while( !stack->isEmpty() ) {
		Node* node = stack->pop();

		cout << node->value() << " ";
		if ( node->right() ) stack->push(node->right());
		if ( node->left() ) stack->push(node->left());
	}

	delete stack;
}

int Node::height() const
{
	int l=0;
	if ( _left ) {
		l = _left->height();
	}

	int r=0;
	if ( _right ) {
		r = _right->height();
	}

	return 1 + std::max(l,r);
}

BinaryTree::~BinaryTree()
{
	if ( _tree ) delete _tree;
}

void BinaryTree::insertElements(const std::vector<int> &vec)
{
	for(int i=0; i<vec.size(); i++) {
		this->insertNode(new Node(vec[i]));
	}
}

void BinaryTree::insertNode(Node* node)
{
	if ( _tree == NULL ) {
		_tree = node;
		return;
	}

	Node* curr = _tree;
	bool inserted = false;
	
	while(!inserted) {
		if ( node->value() <= curr->value() ) {
			if ( curr->left() ) {
				curr = curr->left();
			}
			else {
				curr->setLeft(node);
				inserted=true;
			}
		}
		else
		{
			if ( curr->right() ) {
				curr = curr->right();
			}
			else {
				curr->setRight(node);
				inserted=true;
			}
		}
	}
}

void BinaryTree::printNodes(TraversalOrder order)
{
	if ( _tree ) {
		_tree->print(order);
		cout << endl;
	}
}

void BinaryTree::printNodesNoRecursion()
{
	if ( _tree ) {
		_tree->printNoRecursion();
		cout << endl;
	}
}

int BinaryTree::height() const
{
	if ( _tree )
		return _tree->height();
	return 1;
}

Node* BinaryTree::findCommonAncestor(int v1, int v2)
{
	if ( _tree )
		return findCommonAncestor(_tree, v1, v2);
	return NULL;
}

Node* BinaryTree::findCommonAncestor(Node* node, int v1, int v2)
{
	while(node)
	{
		if ( v1 <= node->value() && v2 <= node->value() )
			node = node->left();
		else if ( v1 > node->value() && v2 > node->value() )
			node = node->right();
		else
			return node;
	}
	return NULL;
}

