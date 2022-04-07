#pragma once
#include "MinHeap.h"

typedef struct Element
{
	Vertex parent;
	int sizeOfThree;

}Element;

class DisjointSets
{
private:
	vector<Element> A;

public
	DisjointSets(const Graph& graph);
	void MakeSet(Vertex x);
	Vertex Find(Vertex x);
	void Union(Vertex repX, Vertex repY);
};

