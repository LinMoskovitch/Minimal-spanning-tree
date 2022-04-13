#include "Algorithms.h"

int main(int argc, char** argv)
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
		cout <<"File corrupt or not found!";
		exit(1);
	}
	Graph graph(0,0);
	Edge toRemove = Algorithms::getEdgeToRemoveAndGraphFromFile(inputFile, graph);
	inputFile.close();

	Kruskal = Algorithms::Kruskal(graph);
	//Prim = Algorithms::Prim(graph);
	Algorithms::CalculateMSTWeight("Kruskal", Kruskal, outputFile);
	//Algorithms::CalculateMSTWeight("Prim", Prim, outputFile);

	/*graph.RemoveEdge(toRemove.first_vertex, toRemove.second_vertex);
	Algorithms::Kruskal(graph);
	Algorithms::CalculateMSTWeight("After removing edge in Kruskal", Kruskal, outputFile);*/
}
