#include "MinHeap.h"

MinHeap::MinHeap()
{
}

MinHeap::~MinHeap()
{
}

Pair MinHeap::Min()
{
	if (heapSize < 1)
	{
		cout << "Wrong input";
		exit(1);
	}
	return dataArr.at(0);
}

Pair MinHeap::DeleteMin()
{
	Pair tmp = dataArr.at(0);
	heapSize--;
	dataArr.at(0) = dataArr.at(heapSize);
	FixHeap(0);
	return tmp;
}


void MinHeap::FixHeap(const int node)
{
	int min;
	const int left = Left(node);
	const int right = Right(node);

	if (left < heapSize && dataArr.at(left).priority < dataArr.at(node).priority)
		min = left;
	else
		min = node;
	if (right < heapSize && dataArr.at(right).priority < dataArr.at(min).priority)
		min = right;

	if (min != node)
	{
		swap(dataArr.at(node), dataArr.at(min));
		FixHeap(min);
	}
}

void MinHeap::Insert(const Pair& item)
{
	heapSize++;
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
	heapSize = maxSize = n;
	dataArr = A;
	for (int i = n / 2 - 1; i >= 0; --i)
	{
		FixHeap(i);
	}
}

void MinHeap::BuildHeapFromGraph(Graph& graph,Vertex startPoint)
{
	heapSize = graph.GetNumOfVertex();
	for(int i = 1; i <= heapSize; i++)
	{
		Pair pair;
		pair.data = i;
		if (i == startPoint)
			pair.priority = 0;
		else
			pair.priority = INFINITY;
		dataArr.push_back(pair);
		graph.getVerteciesArray().at(i).positionInHeap = &pair;
	}
}

void MinHeap::SetHeapSize(int newHeapSize)
{
	this->heapSize = newHeapSize;
}

int MinHeap::GetHeapSize() const
{
	return heapSize;
}

void MinHeap::MakeEmpty()
{
	this->heapSize = 0;
}

bool MinHeap::IsEmpty() const
{
	return heapSize == 0;
}

void MinHeap::DecreaseKey(const int node)
{
	const int parent = Parent(node);

	while (node != 0 && dataArr.at(node).priority < dataArr.at(parent).priority)
	{
		swap(dataArr.at(node), dataArr.at(parent));
		FixHeap(parent);
	}
}
