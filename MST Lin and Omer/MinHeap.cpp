#include "MinHeap.h"



MinHeap::MinHeap(Graph& graph, Vertex startPoint)
{
	HeapNode pair;
	pair.vertex_name = startPoint;
	pair.length_from_tree = 0;
	pair.location = 0;
	dataArr.push_back(pair);
	*(graph.getVerteciesArray().at(startPoint).positionInHeap) = dataArr.at(0).location;
	for (int i = 1; i <= graph.GetNumOfVertex(); i++)
	{
		if (i == startPoint)
			continue;
		

		pair.length_from_tree = INT32_MAX;
		pair.vertex_name = i;
		pair.location = GetHeapSize();
		dataArr.push_back(pair);
		*(graph.getVerteciesArray().at(i).positionInHeap) = dataArr.back().location;
	}
}



HeapNode MinHeap::Min()
{
	if (GetHeapSize() < 1)
	{
		cout << "Wrong input";
		exit(1);
	}
	return dataArr.at(0);
}

HeapNode MinHeap::DeleteMin()
{
	dataArr.at(0).location = -1;
	HeapNode tmp = dataArr.at(0);
	dataArr.at(0) = dataArr.back();
	dataArr.pop_back();
	FixHeap(0);
	return tmp;
}


void MinHeap::FixHeap(const int node)
{
	int min;
	const int left = Left(node);
	const int right = Right(node);

	if (left < GetHeapSize() && dataArr.at(left).length_from_tree < dataArr.at(node).length_from_tree)
		min = left;
	else
		min = node;
	if (right < GetHeapSize() && dataArr.at(right).length_from_tree < dataArr.at(min).length_from_tree)
		min = right;

	if (min != node)
	{
		swap(dataArr.at(node), dataArr.at(min));
		swap(dataArr.at(node).location, dataArr.at(min).location);
		FixHeap(min);
	}
}

void MinHeap::Insert(const HeapNode& item)
{
	int i = dataArr.size();
	dataArr.push_back(item);
	while (i > 0 && dataArr.at(Parent(i)).length_from_tree > item.length_from_tree)
	{
		dataArr.at(i) = dataArr.at(Parent(i));
		i = Parent(i);
	}
	dataArr.at(i) = item;
}

void MinHeap::BuildHeap(vector<HeapNode> A, int n)
{
	
	dataArr = A;
	for (int i = n / 2 - 1; i >= 0; --i)
	{
		FixHeap(i);
	}
}

int MinHeap::GetHeapSize() const
{
	return dataArr.size();
}

void MinHeap::MakeEmpty()
{
	dataArr.resize(0);
}

bool MinHeap::IsEmpty() const
{
	return dataArr.empty();
}

void MinHeap::DecreaseKey(const int node)
{
	const int parent = Parent(node);

	while (node != 0 && dataArr.at(node).length_from_tree < dataArr.at(parent).length_from_tree)
	{
		swap(dataArr.at(node), dataArr.at(parent));
		swap(dataArr.at(node).location, dataArr.at(parent).location);
		FixHeap(parent);
	}
}
