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

vector<Edge> Algorithms::Kruskal(Graph& graph)
{
    vector<Edge> edgeSet;
    DisjointSets UF(graph);
    QuickSort(edgeSet, 0, edgeSet.size() - 1);
    for (int i = 0; i < graph.GetNumOfVertex(); ++i)
    {
        UF.MakeSet(i);
    }
    for(const Edge edge : edgeSet)
    {
        Vertex uTmp = UF.Find(edge.first_vertex);
        Vertex vTmp = UF.Find(edge.second_vertex);

        if (uTmp != vTmp)
        {
            edgeSet.push_back(edge);
            UF.Union(edge.first_vertex, edge.second_vertex);
        }
    }
    return edgeSet;
}

void Algorithms::Prim(Graph graph)
{
    MinHeap Q;
    vector<bool> inT ={false};
    vector<Weight> min;
    min.reserve(graph.GetNumOfVertex());
    min.at(0) = 0;


}

Graph Algorithms::getGraphFromFile(string fileName)
{
    return Graph(1,3);
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
            swap(edgesArray.at(i), edgesArray.at(j));
        }
    }
    swap(edgesArray.at(i+1), edgesArray.at(high));
    return (i + 1);
}
