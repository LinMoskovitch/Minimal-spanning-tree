#pragma once
#include "DisjointSets.h"
class Algorithms
{
public:
	static void QuickSort(const vector<Edge>& edgesArray, int left, int right);
	static vector<Edge> Kruskal(Graph& graph);
	static void Prim(Graph graph);
	static Graph getGraphFromFile(string fileName);

private:
	static Vertex Partition(const vector<Edge>& edgesArray, Vertex low, Vertex high);
};

