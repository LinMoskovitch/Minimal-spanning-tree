#include "Algorithms.h"

void Algorithms::QuickSort(const vector<Edge>& edgesArray, int left, int right)
{
	if (left < right)
	{
		const Weight pivot = Partition(edgesArray, left, right);
        QuickSort(edgesArray, left, pivot - 1);
        QuickSort(edgesArray, pivot + 1, right);
    }
}

void Algorithms::Kruskal(Graph graph)
{
    cout << "blah";
}

void Algorithms::Prim(Graph graph)
{
    MinHeap Q;
    vector<bool> inT ={false};
    vector<Weight> min;
    min.reserve(graph.GetNumOfVertex());
    min.at(0) = 0;


}

Vertex Algorithms::Partition(const vector<Edge>& edgesArray, Vertex low, Vertex high)
{
	const Weight pivot = edgesArray.at(high).weight; 
    Vertex i = (low - 1);

    for (Vertex j = low; j <= high - 1; j++)
    {
        
        if (edgesArray.at(j).weight < pivot)
        {
            i++;
            //swap(edgesArray.at(i), edgesArray.at(j));
        }
    }
    //Algorithms::swap(edgesArray.at(i+1), edgesArray.at(high));
    return (i + 1);
}

//void Algorithms::MySwap(Edge i, Edge j)
//{
//    Edge tmp = i;
//    i = j;
//    j = i;
//}

