#pragma once
#include "Graph.h"

typedef struct pair
{
	int priority;
	string data;
}Pair;

class MinHeap
{

private:

	vector<Pair> dataArr;
	int maxSize;
	int heapSize;

	static int Left(int node) { return 2 * node + 1; }
	static int Right(int node) { return 2 * node + 2; }
	static int Parent(int node) { return (node - 1) / 2; }

	

public:

	MinHeap();
	~MinHeap();

	Pair Min();
	Pair DeleteMin();
	void FixHeap(int node);

	void Insert(const Pair& item);
	void BuildHeap(vector<Pair> A, int n);
	void BuildHeapFromGraph(Graph& graph);
	void SetHeapSize(int newHeapSize);
	int GetHeapSize() const;
	void MakeEmpty();
	bool IsEmpty() const;
	void DecreaseKey(int place, Weight newKey);

};


