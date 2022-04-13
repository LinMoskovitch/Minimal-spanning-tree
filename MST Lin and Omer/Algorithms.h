#pragma once
#include "DisjointSets.h"
class Algorithms
{
public:
	static void QuickSort(vector<Edge>& edgesArray, int left, int right);
	static vector<Edge> Kruskal(Graph& graph, bool isSorted);
	static vector<Edge> Prim(Graph& graph);

	static Edge GetEdgeToRemoveAndGraphFromFile(ifstream& is, Graph& graph); // A method to get the input from the input file.
	static void GetSingleNumFromStr(const string& str, int& num); // A helper method to get a line from file
	static void GetEdgeFromStr(const string& str, Edge& e, bool isLastIteration); // A helper method to get edge (u,v,w(u,v)) from file.
	static int MyAtoi(char* str); // A helper to convert from string to int

	static void CalculateMSTWeight(string name, vector<Edge> edgesArray, ofstream& outputFile); // A method to calc weight of tree


private:
	static Vertex Partition(vector<Edge>& edgesArray, Vertex low, Vertex high);
	static void edgeSwap(Edge& src, Edge& dest); // swap for partition

};

