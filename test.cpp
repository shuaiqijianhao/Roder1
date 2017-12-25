#include "net.h"
#include <iostream>
int main() {
	Graph<int> graph;

	graph.CreateGraph();
	graph.PrintGraph();
	graph.InsertVex(14); graph.InsertVex(15);
	graph.InsertEdge(14, 1, 3);
	graph.PrintGraph();
	graph.PrintGraph();
	system("pause");
	return 0;
}