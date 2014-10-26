
#include "graph.h"

int main(int argc, char*argv[])
{
	{
		Graph* graph = new Graph();

		// Add all the nodes of the graph
		graph->addNode("0");
		graph->addNode("1");
		graph->addNode("2");
		graph->addNode("3");

		// Add all the edges with weight
		graph->insertEdge(0,1,2);
		graph->insertEdge(0,2,1);
		graph->insertEdge(1,2,1);
		graph->insertEdge(1,3,1);
		graph->insertEdge(2,3,3);

		graph->findShortestPath("3", 2);
	}

	{
		Graph* graph = new Graph();

		// Add all the nodes of the graph
		graph->addNode("");
		graph->addNode("B");
		graph->addNode("C");
		graph->addNode("D");
		graph->addNode("E");
		graph->addNode("F");
		graph->addNode("T");
		graph->addNode("Z");

		// Add all the edges with weight
		graph->insertEdge(0,1,3);
		graph->insertEdge(0,2,4);
		graph->insertEdge(0,3,2);
		graph->insertEdge(1,4,1);
		graph->insertEdge(2,4,6);
		graph->insertEdge(2,3,7);
		graph->insertEdge(2,5,5);
		graph->insertEdge(3,5,8);
		graph->insertEdge(4,5,12);
		graph->insertEdge(5,6,2);
		graph->insertEdge(4,7,14);
		graph->insertEdge(6,7,1);
	
		graph->findShortestPath("Z", 0);
	}
	return 0;
}

