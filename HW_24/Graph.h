#pragma once
#include <list>
#include <vector>

class Graph
{
public:
	enum class ConnectionType
	{
		undirected,
		directed
	};

	Graph(int vertixes, ConnectionType type = ConnectionType::undirected)
		: m_vertixes(vertixes), m_connectionType(type) {}

	virtual void addEdge(int v, int w) = 0;

	virtual void BFS(int vertex = 0) {};
	virtual void DFS(int vertex = 0) {};

protected:
	unsigned int m_vertixes;
	ConnectionType m_connectionType;
};

// using adjacency list
class GraphAdjList : public Graph
{
public:
	GraphAdjList(int vertixes, ConnectionType type = ConnectionType::undirected);
	void addEdge(int v, int w) override;

	void BFS(int vertex = 0) override;

	int numberOfNodesInLevel(int level); //#TODO IMPLEMLENT
	bool isStronglyConnected() const;

private:
	std::vector<std::list<int> > m_list;
};

//#TODO HW
class GraphAdjMatrix : public Graph
{
public:
	GraphAdjMatrix(int vertixes, ConnectionType type = ConnectionType::undirected);

	void addEdge(int v, int w) override; //#TODO IMPLEMENT
	void DFS(int vertex = 0) override;	//#TODO IMPLEMENT

private:
	//#TODO
	std::vector<std::vector<bool>> m_matrix;
};