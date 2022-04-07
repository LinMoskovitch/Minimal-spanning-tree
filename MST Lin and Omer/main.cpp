#include "Algorithms.h"



void main(int argc, vector<string> argv)
{
	
	int n, m;
	Vertex i, j;
	Weight w;
	cout << "Please enter number of vertecies :";
	cin >> n;

	cout << "Please enter number of edges :";
	cin >> m;
	Graph weightedGraph(n, m);

	cout << "Enter trees of edges and weights :";
	for (int k = 0; k < n; ++k)
	{
		cin >> i;
		cin >> j;
		cin >> w;
		weightedGraph.AddEdge(i, j, w);
	}
	cout << weightedGraph.getVisualGraph();
	cout << "Enter the edge you would like to remove :";
	cin >> i;
	cin >> j;
	cout << weightedGraph.getVisualGraph();
	/*cout << "Kruskal weight :" << Algorithms::Kruskal(weightedGraph);
	cout << "Prim weight :" << Algorithms::Prim(weightedGraph);
	weightedGraph.RemoveEdge(i, j);
	cout << "Kruskal weight after removing edge :" << Algorithms::Kruskal(weightedGraph);*/
	
}
