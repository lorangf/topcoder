
#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <exception>
#include <vector>

enum TraversalOrder { PRE_ORDER, IN_ORDER, POST_ORDER };

// Not using template or subclassing to simplify the implementation
class Node
{
public:
	Node(int value) : _left(NULL), _right(NULL), _value(value) {}
	//Node(const Node& in);
	~Node();

	int value() const { return _value; }
	const Node* left() const { return _left; }
	const Node* right() const { return _right; }
	
	Node* left() { return _left; }
	Node* right() { return _right; }

	void setLeft(Node* left) { _left = left; }
	void setRight(Node* right) { _right = right; }

	//Node& operator=(const Node& in);
	void print(TraversalOrder order);
	void printNoRecursion();
	int height() const;

private:
	Node* _left;
	Node* _right;
	int _value;
};

class NodeStackException : public std::exception
{
public:
	NodeStackException() {}

	virtual const char* what() const throw()
	{
		return "Node pop attempted on empty stack";
	}
};

class NodeStack
{
public:
	NodeStack() : _head(NULL) {}
	~NodeStack() { while(!isEmpty()) pop(); }

	void push(Node* node) {
		StackItem* item = new StackItem(_head, node);
		_head = item;
	}
	Node* pop() {
		if ( _head==NULL )
			throw new NodeStackException();
		StackItem* item = _head;
		_head = _head->next();
		Node* node = item->node();
		delete item;
		return node;
	}
	bool isEmpty() const { return (_head)?false:true; }
private:
	class StackItem
	{
	public:
		StackItem(StackItem* head, Node* node) : _node(node), _next(head) {}
		~StackItem() {}

		Node* node() { return _node; }
		StackItem* next() { return _next; }

	private:
		StackItem* _next;
		Node* _node;
	};
	StackItem* _head;
};

class BinaryTree
{
public:
	BinaryTree() : _tree(NULL) {}
	BinaryTree(Node* tree) : _tree(tree) {}
	~BinaryTree();

	void insertElements(const std::vector<int> &vec);
	void printNodes(TraversalOrder order);
	void printNodesNoRecursion();
	int  height() const;
	Node* findCommonAncestor(int v1, int v2);

private:
	Node* _tree;
	
	void insertNode(Node* node);
	Node* findCommonAncestor(Node*, int v1, int v2);
};

#endif

