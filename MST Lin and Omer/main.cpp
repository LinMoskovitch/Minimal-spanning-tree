#include "Algorithms.h"

////void main(int argc, char** argv)
//{
//	//Graph weightedGraph = getGraphFromFile(argv.at(1));
//
//	//int n, m;
//	//Vertex i, j;
//	//Weight w;
//	//cout << "Please enter number of vertecies : ";
//	//cin >> n;
//
//	//cout << "Please enter number of edges : ";
//	//cin >> m;
//	//Graph weightedGraph(n, m);
//
//	//cout << "Enter triplets of edges and weights : ";
//	//for (int k = 0; k < m; ++k)
//	//{
//	//	cin >> i;
//	//	cin >> j;
//	//	cin >> w;
//	//	weightedGraph.AddEdge(i, j, w);
//	//}
//	//cout << weightedGraph.GetVisualGraph();
//	//MinHeap heap(weightedGraph, 3);
//	//HeapNode p1 = heap.DeleteMin();
//	//std::cout << "check";
//	///*cout << "Enter the edge you would like to remove : ";
//	//cin >> i;
//	//cin >> j;
//	//cout << weightedGraph.GetVisualGraph();
//	//Algorithms::Kruskal(weightedGraph);
//	//Algorithms::Prim(weightedGraph);
//	//weightedGraph.RemoveEdge(i, j);
//	//cout << "Kruskal's weight after removing edge ( " << i << " , " << j << " )" << endl;
//	//weightedGraph.RemoveEdge(i, j);
//	//Algorithms::Kruskal(weightedGraph);*/
//
//}

void main(int argc, char** argv)
{
	vector<Edge> Kruskal;
	vector<Edge> Prim;
	if (argc <= 2)
	{
		cout << "File names not recieved!";
		exit(1);
	}

	ifstream inputFile(argv[1]);
	ofstream outputFile(argv[2]);

	if (!inputFile || !outputFile)
	{
		cout <<"File currupt or not found!";
		exit(1);
	}
	Edge toRemove;
	Graph graph = Algorithms::getGraphFromFile(inputFile, toRemove);
	inputFile.close();

	Kruskal = Algorithms::Kruskal(graph);
	//Prim = Algorithms::Prim(graph);
	Algorithms::CalculateMSTWeight("Kruskal", Kruskal, outputFile);
	//Algorithms::CalculateMSTWeight("Prim", Prim, outputFile);

	/*graph.RemoveEdge(toRemove.first_vertex, toRemove.second_vertex);
	Algorithms::Kruskal(graph);
	Algorithms::CalculateMSTWeight("After removing edge in Kruskal", Kruskal, outputFile);*/
}
