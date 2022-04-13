#pragma once
#include "Graph.h"

typedef struct HeapNode
{
	int length_from_tree;
	Vertex vertex_name;
	int* location;
}HeapNode;

class MinHeap
{
private:
	vector<HeapNode> dataArr;
	
	static int Left(int node) { return 2 * node + 1; }
	static int Right(int node) { return 2 * node + 2; }
	static int Parent(int node) { return (node - 1) / 2; }

public:

	MinHeap() = default;
	MinHeap(Graph& graph, Vertex startPoint);
	~MinHeap() = default;

	HeapNode Min();
	HeapNode DeleteMin();
	void FixHeap(int node);

	void Insert(const HeapNode& item);
	void BuildHeap(vector<HeapNode> A, int n);
	int GetHeapSize() const;
	void MakeEmpty();
	bool IsEmpty() const;
	void DecreaseKey(const int node);
	int GetLengthFromTree(Vertex vertex_name);
	void SetLengthFromTree(Vertex vertex_name, int new_length);
};
