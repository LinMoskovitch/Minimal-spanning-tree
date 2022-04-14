// Lin Moskovitch 208849745 Omer Cohen Shor 207423906

#include "Algorithms.h"
/* HOW TO USE:
   Run the program with 2 parameters - an input and output file names.
   The input file should represent a graph
   The input file should be in this format: one integer number at the start of each of the first two lines, representing
											num of vertices and num of edges correspondingly
											rest of the lines should consist of 3 positive numbers each (u, v, w(u,v)) -
											the last line should consist of 2 positive numbers representing the edge to remove (u,v)
											all inputs should be integers.
   The program will run and find minimal spanning tree using Kruskal's and Prims's algorithms and find the MST after removing the edge
   The program will print the weights of the MST for both console and output file */
   
void main(int argc, char** argv)
{
	vector<Edge> Kruskal;
	vector<Edge> Prim;
	if (argc <= 2)
	{
		cout << "File names not received!";
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

	Kruskal = Algorithms::Kruskal(graph,false);
	if (Kruskal.size() < graph.GetNumOfVertex() - 1)
	{
		cout << "Not a linked graph!";
		exit(1);
	}
	Prim = Algorithms::Prim(graph);

	Algorithms::CalculateMSTWeight("Kruskal", Kruskal, outputFile);
	Algorithms::CalculateMSTWeight("Prim", Prim, outputFile);

	graph.RemoveEdge(toRemove.first_vertex, toRemove.second_vertex);
	Kruskal = Algorithms::Kruskal(graph,true);
	if (Kruskal.size() < graph.GetNumOfVertex() - 1) // check if the removed edge is a bridge.
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
