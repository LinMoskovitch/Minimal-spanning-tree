#include "DisjointSets.h"

DisjointSets::DisjointSets(const Graph& graph)
{
	A.assign(graph.GetNumOfVertex() + 1, { -1,0 });
}

void DisjointSets::MakeSet(const Vertex x)
{
	A.at(x).parent = x;
	A.at(x).sizeOfThree = 1;
}

Vertex DisjointSets::Find(Vertex x)
{
	if (A.at(x).parent == x)
	{
		return x;
	}

	return (A.at(x).parent == Find(A.at(x).parent));
}

void DisjointSets::Union(Vertex repX, Vertex repY)
{
	if (A.at(repX).sizeOfThree > A.at(repY).sizeOfThree)
	{
		A.at(repY).parent = repX;
		A.at(repX).sizeOfThree += A.at(repY).sizeOfThree;
	}
	else
	{
		A.at(repX).parent = repY;
		A.at(repY).sizeOfThree += A.at(repX).sizeOfThree;
	}
}
