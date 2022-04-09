#pragma once
#include "List.h"

typedef struct GraphVertex
{
	List* neighbors;
	int* positionInHeap;
}GraphVertex;

typedef struct Edge
{
	int first_vertex;
	int second_vertex;
	int weight;
}Edge;

class Graph
{
private:
	int n;  //Number of vertecies
	int m;  //Number of edges
	vector<GraphVertex> verteciesArray;
	vector<Edge> edgeArray;

public:

	Graph(Vertex n, Edges m);
	~Graph();

	void MakeEmptyGraph();
	bool IsAdjacent(Vertex u, Vertex v) const;
	List* GetAdjList(Vertex u);
	void AddEdge(Vertex u, Vertex v, Weight w);
	void RemoveEdge(Vertex u, Vertex v);

	int GetNumOfVertex() const { return n; }
	int GetNumOfEdges() const { return m; }
	vector<GraphVertex>& getVerteciesArray() { return verteciesArray; }
	string GetVisualGraph() const;
	bool InGraph(Vertex v) const { return ((v <= n) && (v >= 1)); }

};