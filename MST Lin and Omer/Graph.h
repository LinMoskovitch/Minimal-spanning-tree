#pragma once
#include "List.h"



class Graph
{
private:
	int n;  //Number of vertecies
	int m;  //Number of edges
	vector<ListPair> verteciesArray;
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
	vector<ListPair>& getVerteciesArray() { return verteciesArray; }
	string GetVisualGraph() const;
	bool InGraph(Vertex v) const { return ((v <= n) && (v >= 1)); }

};