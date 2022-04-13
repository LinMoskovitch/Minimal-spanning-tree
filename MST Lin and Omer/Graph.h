#pragma once
#include "List.h"


typedef struct GraphVertex
{
	List* neighbors;
	int* location_in_heap;
}GraphVertex;

typedef struct Edge
{
	int first_vertex;
	int second_vertex;
	int weight;

	Edge& operator=(const Edge& a)
	{
		first_vertex = a.first_vertex;
		second_vertex = a.second_vertex;
		weight = a.weight;
		return *this;
	}
	Edge& operator=(nullptr_t)
	{
		*this = nullptr;
	}
}Edge;

class Graph
{
private:
	int n;  //Number of vertecies
	int m;  //Number of edges
	vector<GraphVertex> verteciesArray;
	vector<Edge> edgeArray;

public:

	Graph(Vertex n = 0, Edges m = 0);
	~Graph();

	void MakeEmptyGraph(Vertex n, Edges m);
	bool IsAdjacent(Vertex u, Vertex v) const;
	List* GetAdjList(Vertex u);
	void AddEdge(Vertex u, Vertex v, Weight w);
	void RemoveEdge(Vertex u, Vertex v);

	int GetNumOfVertex() const { return n; }
	int GetNumOfEdges() const { return m; }
	vector<GraphVertex>& getVerteciesArray() { return verteciesArray; }
	vector<Edge>& getEdgeArray() { return edgeArray; }
	string GetVisualGraph() const;
	bool InGraph(Vertex v) const { return ((v <= n) && (v >= 1)); }

};