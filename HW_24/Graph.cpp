#include "Graph.h"
#include <unordered_set>
#include <iostream>
#include <stack>
#include <queue>

GraphAdjList::GraphAdjList(int Vertixes, ConnectionType type)
	: Graph(Vertixes, type)
{
	m_list.resize(Vertixes);
}

void GraphAdjList::addEdge(int v, int w)
{
	if (std::find(m_list[v].begin(), m_list[v].end(), w) == m_list[v].end()) {
		m_list[v].push_back(w);
	}

	if (m_connectionType == ConnectionType::undirected)
	{
		m_list[w].push_back(v);
	}
}


void GraphAdjList::BFS(int vertex)
{
	std::unordered_set<int> visited;
	std::list<int> queue;

	visited.insert(vertex);
	queue.push_back(vertex);

	while (!queue.empty())
	{
		int currentVertex = queue.front();
		std::cout << currentVertex << " ";
		queue.pop_front();

		for (int adjacent : m_list[currentVertex])
		{
			if (!visited.count(adjacent))
			{
				visited.insert(adjacent);
				queue.push_back(adjacent);
			}
		}
	}
}

int GraphAdjList::numberOfNodesInLevel(int level)
{
	if (level < 0 || level >= m_vertixes) {
		return 0; 
	}

	std::vector<bool> visited(m_vertixes, false);
	std::queue<int> q;
	int currentLevel = 1;
	int nodesInLevel = 0;

	q.push(0);

	while (!q.empty()) {
		int nodesAtCurrentLevel = q.size();

		if (currentLevel == level) {
			nodesInLevel = nodesAtCurrentLevel;
			break;
		}

		for (int i = 0; i < nodesAtCurrentLevel; ++i) {
			int node = q.front();
			q.pop();
			visited[node] = true;

			for (int adjacentNode : m_list[node]) {
				if (!visited[adjacentNode]) {
					q.push(adjacentNode);
				}
			}
		}
		currentLevel++;
	}

	return nodesInLevel;
}

bool GraphAdjList::isStronglyConnected() const {
	for (int startVertex = 0; startVertex < m_vertixes; ++startVertex) {
		std::vector<bool> visited(m_vertixes, false);
		std::stack<int> stack;

		stack.push(startVertex);
		visited[startVertex] = true;

		while (!stack.empty()) {
			int currentVertex = stack.top();
			stack.pop();

			for (int adjacentVertex : m_list[currentVertex]) {
				if (!visited[adjacentVertex]) {
					stack.push(adjacentVertex);
					visited[adjacentVertex] = true;
				}
			}
		}

		for (int vertex = 0; vertex < m_vertixes; ++vertex) {
			if (!visited[vertex]) {
				return false;
			}
		}
	}

	return true;
}

// == matrix
GraphAdjMatrix::GraphAdjMatrix(int vertixes, ConnectionType type)
	: Graph(vertixes, type)
{
	m_matrix.resize(vertixes, std::vector<bool>(vertixes, false));
};

void GraphAdjMatrix::addEdge(int v, int w) {
	m_matrix[v][w] = true;
	if (m_connectionType == ConnectionType::undirected) {
		m_matrix[w][v] = true;
	}
}

void GraphAdjMatrix::DFS(int vertex) {
	std::vector<bool> visited(m_vertixes, false);
	std::stack<int> stack;

	stack.push(vertex);

	while (!stack.empty())
	{
		int currentVertex = stack.top();
		stack.pop();

		if (!visited[currentVertex])
		{
			std::cout << currentVertex << " ";
			visited[currentVertex] = true;
		}

		for (int i = 0; i < m_vertixes; i++)
		{
			if (m_matrix[currentVertex][i] && !visited[i])
			{
				stack.push(i);
			}
		}
	}
}