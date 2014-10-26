
#ifndef GRAPH_H_
#define GRAPH_H_

#include <cassert>
#include <string>
#include <vector>

class EdgeNode
{
public:
	EdgeNode(int y, int w) : y_(y), w_(w), next_(NULL) {}

	int y_;
	int w_;
	EdgeNode* next_;
};

enum NodeStatus
{
	kUnknown,
	kKnown,
	kProcessed
};

class Node
{
public:
	Node(const char* name) : name_(name) { status_ = kUnknown; first_edge_ = NULL; }
	~Node() {}

	bool insertEdge(int y, int w) {
		EdgeNode* edge = new EdgeNode(y, w);
		edge->next_ = first_edge_;
		first_edge_ = edge;
	}

	NodeStatus status_;
	std::string name_;
	EdgeNode* first_edge_;
};

class Graph
{
public:
	Graph() {}
	~Graph() {}

	int addNode(const char* name);
	bool insertEdge(int n1, int n2, int w);

	void findShortestPath(const char* name, int start);

private:
	std::vector<Node*> nodes_;
};

#endif // GRAPH_H_

