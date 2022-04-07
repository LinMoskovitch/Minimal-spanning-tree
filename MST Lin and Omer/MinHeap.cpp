#include "MinHeap.h"



MinHeap::MinHeap(Graph& graph, Vertex startPoint)
{
	Pair pair;
	pair.data = startPoint;
	pair.priority = 0;
	pair.location = 0;
	dataArr.push_back(pair);
	*(graph.getVerteciesArray().at(startPoint).positionInHeap) = dataArr.at(0).location;
	for (int i = 1; i <= graph.GetNumOfVertex(); i++)
	{
		if (i == startPoint)
			continue;
		

		pair.priority = INT32_MAX;
		pair.data = i;
		pair.location = GetHeapSize();
		dataArr.push_back(pair);
		*(graph.getVerteciesArray().at(i).positionInHeap) = dataArr.back().location;
	}
}



Pair MinHeap::Min()
{
	if (GetHeapSize() < 1)
	{
		cout << "Wrong input";
		exit(1);
	}
	return dataArr.at(0);
}

Pair MinHeap::DeleteMin()
{
	dataArr.at(0).location = -1;
	Pair tmp = dataArr.at(0);
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

	if (left < GetHeapSize() && dataArr.at(left).priority < dataArr.at(node).priority)
		min = left;
	else
		min = node;
	if (right < GetHeapSize() && dataArr.at(right).priority < dataArr.at(min).priority)
		min = right;

	if (min != node)
	{
		swap(dataArr.at(node), dataArr.at(min));
		swap(dataArr.at(node).location, dataArr.at(min).location);
		FixHeap(min);
	}
}

void MinHeap::Insert(const Pair& item)
{
	int i = dataArr.size();
	dataArr.push_back(item);
	while (i > 0 && dataArr.at(Parent(i)).priority > item.priority)
	{
		dataArr.at(i) = dataArr.at(Parent(i));
		i = Parent(i);
	}
	dataArr.at(i) = item;
}

void MinHeap::BuildHeap(vector<Pair> A, int n)
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

	while (node != 0 && dataArr.at(node).priority < dataArr.at(parent).priority)
	{
		swap(dataArr.at(node), dataArr.at(parent));
		swap(dataArr.at(node).location, dataArr.at(parent).location);
		FixHeap(parent);
	}
}
