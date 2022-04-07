#pragma once
#include "Graph.h"



class MinHeap
{

private:

	vector<Pair> dataArr;
	

	static int Left(int node) { return 2 * node + 1; }
	static int Right(int node) { return 2 * node + 2; }
	static int Parent(int node) { return (node - 1) / 2; }

	

public:

	MinHeap() = default;
	MinHeap(Graph& graph, Vertex startPoint);
	~MinHeap() = default;

	Pair Min();
	Pair DeleteMin();
	void FixHeap(int node);

	void Insert(const Pair& item);
	void BuildHeap(vector<Pair> A, int n);
	int GetHeapSize() const;
	void MakeEmpty();
	bool IsEmpty() const;
	void DecreaseKey(const int node);
};

typedef struct Pair
{
	Weight priority;
	string data;
	int location;
}Pair;




