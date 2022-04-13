#pragma once
#include "DisjointSets.h"
class Algorithms
{
public:
	static void QuickSort(vector<Edge>& edgesArray, int left, int right);
	static vector<Edge> Kruskal(Graph& graph);
	static vector<Edge> Prim(Graph& graph);

	static Edge GetEdgeToRemoveAndGraphFromFile(ifstream& is, Graph& graph);
	static void GetSingleNumFromStr(const string& str, int& num);
	static void GetEdgeFromStr(const string& str, Edge& e, bool isLastIteration);
	static int MyAtoi(char* str);
	static void CalculateMSTWeight(string name, vector<Edge> edgesArray, ofstream& outputFile);


private:
	static Vertex Partition(vector<Edge>& edgesArray, Vertex low, Vertex high);
	static void edgeSwap(Edge& src, Edge& dest);

};

