#include "Algorithms.h"

void Algorithms::QuickSort(vector<Edge>& edgesArray, int left, int right)
{
	if (left < right)
	{
		const Weight pivot = Partition(edgesArray, left, right);
        QuickSort(edgesArray, left, pivot - 1);
        QuickSort(edgesArray, pivot + 1, right);
    }
}

vector<Edge> Algorithms::Kruskal(Graph& graph, bool isSorted)
{
	vector<Edge> edgeSet;
	vector<Edge>& edgesArray = graph.getEdgeArray();
	DisjointSets UF(graph);
	if (!isSorted)
	{
		QuickSort(edgesArray, 0, edgesArray.size() - 1);
	}

	for (int i = 1; i <= graph.GetNumOfVertex(); ++i)
	{
		UF.MakeSet(i);
	}
	for (const Edge edge : edgesArray)
	{
		const Vertex uTmp = UF.Find(edge.first_vertex);
		const Vertex vTmp = UF.Find(edge.second_vertex);

		if (uTmp != vTmp)
		{
			edgeSet.push_back(edge);
			UF.Union(uTmp, vTmp);
		}
	}

    return edgeSet;
}


vector<Edge> Algorithms::Prim(Graph& graph)
{
	vector<Vertex> p;
	vector<Edge> edgeSet;
	MinHeap Q(graph, 1);
    vector<bool> inT;
	inT.assign(graph.GetNumOfVertex() + 1, false);
	p.assign(graph.GetNumOfVertex() + 1, -1);

	while (!Q.IsEmpty())
	{
		HeapNode u = Q.DeleteMin();
		if (p.at(u.vertex_name) != -1)
			edgeSet.push_back({ u.vertex_name,p.at(u.vertex_name),u.length_from_tree });
		inT.at(u.vertex_name) = true;
		const List* neighbors = graph.GetverticesArray().at(u.vertex_name).neighbors;
		ListNode* curr = neighbors->GetHead();
		while (curr != nullptr)
		{
			int currInHeap = *(graph.GetverticesArray().at(curr->vertex_name).location_in_heap);
			if (inT.at(curr->vertex_name) == false && curr->weight < Q.GetLengthFromTree(currInHeap))
			{
				Q.SetLengthFromTree(currInHeap, curr->weight);
				p.at(curr->vertex_name) = u.vertex_name;
				Q.DecreaseKey(currInHeap);
			}
			curr = curr->next;
		}
	}
	return edgeSet;
}


void Algorithms::CalculateMSTWeight(string name, const vector<Edge> edgesArray, ofstream& outputFile)
{
	int totalWeight = 0;
	for (const Edge edge : edgesArray)
	{
		totalWeight += edge.weight;
	}
	cout << name + "'s: " << totalWeight << endl;
	outputFile << name + "'s: " << totalWeight << endl;
}

Vertex Algorithms::Partition(vector<Edge>& edgesArray, Vertex low, Vertex high)
{
	const Weight pivot = edgesArray.at(high).weight; 
    Vertex i = (low - 1);

    for (Vertex j = low; j <= high - 1; j++)
    {
        
        if (edgesArray.at(j).weight < pivot)
        {
            i++;
			edgeSwap(edgesArray.at(i), edgesArray.at(j));
        }
    }
	edgeSwap(edgesArray.at(i+1), edgesArray.at(high));
    return (i + 1);
}

void Algorithms::edgeSwap(Edge& src, Edge& dest)
{
	const Edge tmp = src;
	src = dest;
	dest = tmp;
}
Edge Algorithms::GetEdgeToRemoveAndGraphFromFile(ifstream& is, Graph& graph)
{
	string str;
	Edge tmpEdge;
	int n, m;
	getline(is, str);
	GetSingleNumFromStr(str, n); // number of vertices
	getline(is, str);
	GetSingleNumFromStr(str, m);	// number of edges
	graph.MakeEmptyGraph(n,m);
	bool isLastIteration = false;
	for (int i = 0; i < m; ++i)
	{
		getline(is, str);
		GetEdgeFromStr(str, tmpEdge, isLastIteration);
		if (tmpEdge.first_vertex == tmpEdge.second_vertex)
		{
			cout << "Invalid edge!";
			exit(1);
		}

		graph.AddEdge(tmpEdge.first_vertex, tmpEdge.second_vertex, tmpEdge.weight);
		str.clear();
	}
	// get the edge to remove
	isLastIteration = true;
	getline(is, str);
	GetEdgeFromStr(str, tmpEdge, isLastIteration);

	if (!graph.IsAdjacent(tmpEdge.first_vertex, tmpEdge.second_vertex))
	{
		cout << "edge to remove is not in the graph!";
		exit(1);
	}

	return {tmpEdge.first_vertex, tmpEdge.second_vertex, 0};
}

void Algorithms::GetSingleNumFromStr(const string& str, int& num)
{
	char* token;
	char deli[4] = " \n\t";
	token = strtok(const_cast<char*>(str.c_str()), deli);
	if (strtok(NULL, deli))
	{
		cout <<"More than one number in row";
		exit(1);
	}
	num = Algorithms::MyAtoi(token);
}

void Algorithms::GetEdgeFromStr(const string& str, Edge& e , bool isLastIteration)
{
	char* token1, * token2, * token3;
	char deli[4] = " \n\t";
	token1 = strtok(const_cast<char*>(str.c_str()), deli);
	token2 = strtok(NULL, deli);
	token3 = strtok(NULL, deli);

	if (!isLastIteration)
	{
		if (!token1 || !token2 || !token3)
		{
			cout << "More or less than three numbers in row";
			exit(1);
		}
		e.first_vertex = Algorithms::MyAtoi(token1);
		e.second_vertex = Algorithms::MyAtoi(token2);
		e.weight = Algorithms::MyAtoi(token3);
	}
	else
	{
		if (!token1 || !token2)
		{
			cout << "More or less than two numbers in row";
			exit(1);
		}
		e.first_vertex = Algorithms::MyAtoi(token1);
		e.second_vertex = Algorithms::MyAtoi(token2);
		e.weight = 0;
	}
}
int Algorithms::MyAtoi(char* str)
{
	int res = 0;
	while (*str != '\0')
	{
		if (ISNUMBER(*str))
		{
			res *= 10;
			res += TOINT(*str);
		}
		else
		{
			cout << "invalid characters - Not an integer number";
			exit(1);
		}
		str++;
	}
	return res;
}
