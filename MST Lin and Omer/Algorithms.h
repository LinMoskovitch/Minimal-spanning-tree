#pragma once
#include "DisjointSets.h"
class Algorithms
{
public:
	void QuickSort(const vector<Edge>& edgesArray, int left, int right);
	static void Kruskal(Graph graph);
	static void Prim(Graph graph);

private:
	Vertex Partition(const vector<Edge>& edgesArray, Vertex low, Vertex high) const;
	static void Swap(Edge i, Edge j);

};

