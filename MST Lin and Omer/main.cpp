#include "Algorithms.h"



void main(int argc, vector<string> argv)
{

	int n, m;
	Vertex i, j;
	Weight w;
	cout << "Please enter number of vertecies : ";
	cin >> n;

	cout << "Please enter number of edges : ";
	cin >> m;
	Graph weightedGraph(n, m);

	cout << "Enter triplets of edges and weights : ";
	for (int k = 0; k < m; ++k)
	{
		cin >> i;
		cin >> j;
		cin >> w;
		weightedGraph.AddEdge(i, j, w);
	}
	cout << weightedGraph.GetVisualGraph();
	MinHeap heap(weightedGraph, 3);
	HeapNode p1 = heap.DeleteMin();
	std::cout << "check";
	/*cout << "Enter the edge you would like to remove : ";
	cin >> i;
	cin >> j;
	cout << weightedGraph.GetVisualGraph();
	Algorithms::Kruskal(weightedGraph);
	Algorithms::Prim(weightedGraph);
	weightedGraph.RemoveEdge(i, j);
	cout << "Kruskal's weight after removing edge ( " << i << " , " << j << " )" << endl;
	weightedGraph.RemoveEdge(i, j);
	Algorithms::Kruskal(weightedGraph);*/

}
