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
		cout << "File corrupt or not found!";
		exit(1);
	}
	Graph graph(0, 0);
	Edge toRemove = Algorithms::GetEdgeToRemoveAndGraphFromFile(inputFile, graph);
	inputFile.close();
	Kruskal = Algorithms::Kruskal(graph);
	Prim = Algorithms::Prim(graph);
	Algorithms::CalculateMSTWeight("Kruskal", Kruskal, outputFile);
	Algorithms::CalculateMSTWeight("Prim", Prim, outputFile);
	graph.RemoveEdge(toRemove.first_vertex, toRemove.second_vertex);
	Kruskal = Algorithms::Kruskal(graph);
	if (Kruskal.size() < graph.GetNumOfVertex() - 1)
	{
		cout << "NO MST";
		outputFile << "NO MST";
	}
	else
	{
		
		Algorithms::CalculateMSTWeight("Kruskal2", Kruskal, outputFile);
	}
	outputFile.close();
}
