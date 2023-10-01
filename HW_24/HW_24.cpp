#include <iostream>
#include "Graph.h"

int getTime() { return 1; }

int main()
{
	GraphAdjList graph(10);

	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(0, 3);

	graph.addEdge(1, 4);
	graph.addEdge(2, 5);
	graph.addEdge(2, 6);
	graph.addEdge(3, 7);

	graph.addEdge(4, 8);
	graph.addEdge(5, 9);

#ifdef TIME_LOG_ENABLED
	int startTime = getTime();
#endif

	graph.BFS();

#ifdef TIME_LOG_ENABLED
	int endTime = getTime();
	int diff = endTime - startTime;
	std::cout << "Time used for BFS: " << diff << std::endl;
#endif

	std::cout << "\n\n";

	std::cout << "Nodes In Level: " << graph.numberOfNodesInLevel(3);

	std::cout << "\n\n";

	std::cout << "Strongly connected: " << graph.isStronglyConnected();

	std::cout << "\n\n";

	// == matrix
	GraphAdjMatrix graphMatrix(10, Graph::ConnectionType::undirected);

	graphMatrix.addEdge(0, 1);
	graphMatrix.addEdge(0, 2);
	graphMatrix.addEdge(0, 3);

	graphMatrix.addEdge(1, 4);
	graphMatrix.addEdge(2, 5);
	graphMatrix.addEdge(2, 6);
	graphMatrix.addEdge(3, 7);

	graphMatrix.addEdge(4, 8);
	graphMatrix.addEdge(5, 9);

	graphMatrix.DFS(0);
}