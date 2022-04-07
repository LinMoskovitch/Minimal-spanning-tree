#pragma once
#include "DisjointSets.h"
class Algorithms
{
public:
	void QuickSort(const vector<Edge>& edgesArray, int left, int right);
	static void Kruskal(Graph graph);
	static void Prim(Graph graph);

private:
	Vertex Partition(const vector<Edge>& edgesArray, Vertex low, Vertex high);
	//void MySwap(Edge i, Edge j);

};

