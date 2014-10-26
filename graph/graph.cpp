
#include <climits>
#include <iostream>
#include <vector>

#include "graph.h"

int Graph::addNode(const char* name)
{ 
	nodes_.push_back(new Node(name));
	return nodes_.size()-1;
}

bool Graph::insertEdge(int n1, int n2, int w)
{
	assert(n1<nodes_.size());
	assert(n2<nodes_.size());

	nodes_[n1]->insertEdge(n2, w);
	nodes_[n2]->insertEdge(n1, w);
}

void Graph::findShortestPath(const char* name, int start)
{
	std::vector<bool> in_tree;
	std::vector<int> parent;
	std::vector<int> distance;

	for(int i=0; i<nodes_.size(); i++) {
		in_tree.push_back(false);
		parent.push_back(i);
		distance.push_back(INT_MAX);
	}

	int curr = start;
	distance[curr] = 0;

	while(!in_tree[curr]) {
		in_tree[curr] = true;
		
		EdgeNode* edge = nodes_[curr]->first_edge_;
		while(edge) {
			int dist = distance[curr] + edge->w_;
			if ( dist < distance[edge->y_] ) {
				distance[edge->y_] = dist;
				parent[edge->y_] = curr;
			}
			edge = edge->next_;
		}

		int min_dist=INT_MAX;
		for(int i=0; i<nodes_.size(); i++) {
			if ( !in_tree[i] && distance[i]<min_dist ) {
				min_dist = distance[i];
				curr = i;
			}
		}
	}

	// Printing out the shortest path for verification purposes
	int last = 0;
	for(int i=0; i<nodes_.size(); i++) {
		if ( nodes_[i]->name_ == name ) {
			last = i;
			break;
		}
	}

	std::vector<int> path;
	path.push_back(last);

	while(last != parent[last]) {
		last = parent[last];
		path.push_back(last);
	}

	for(std::vector<int>::reverse_iterator i=path.rbegin(); i!=path.rend(); ++i) {
	    std::cout << *i << ' ';
	}
	std::cout << std::endl;
}

