#include "Graph.h"


Graph::Graph(Vertex n, Edges m) : n(n), m(m)
{
	MakeEmptyGraph();
}

Graph::~Graph()
{
	//TODO
}

void Graph::MakeEmptyGraph()
{
	for (int i = 0; i <= n; ++i)
	{
		ListPair lp;
		lp.neighbors = List();
		lp.positionInHeap = nullptr;
		this->verteciesArray.push_back(lp);
	}
}

bool Graph::IsAdjacent(Vertex u, Vertex v) const
{
	if (!InGraph(u) || !InGraph(v))
		return false;
	if (verteciesArray.at(u).neighbors.IsVertexInList(v) == true)
		return true;
	return false;
}

List Graph::GetAdjList(Vertex u)
{
	return this->verteciesArray.at(u).neighbors;
}

void Graph::AddEdge(Vertex u, Vertex v, Weight w)
{
	if (!InGraph(u) || !InGraph(v) || IsAdjacent(u, v)) //'parallel' edges
	{
		cout << "invalid input!";
		exit(1);
	}

	this->verteciesArray.at(u).neighbors.InsertToTail(v, w);
	this->verteciesArray.at(v).neighbors.InsertToTail(u, w);
	this->edgeArray.push_back({ u,v,w });
}

void Graph::RemoveEdge(Vertex u, Vertex v)
{
	if (!InGraph(u) || !InGraph(v) || !IsAdjacent(u, v)) //'parallel' edges
	{
		cout << "invalid input!";
		exit(1);
	}

	this->verteciesArray.at(u).neighbors.DeleteNode(v);
	this->verteciesArray.at(v).neighbors.DeleteNode(u);
}

string Graph::GetVisualGraph()
{
	string graph = "";
	int i = 1;
	for (ListPair pair : verteciesArray)
	{
		graph.append(i + ": ");
		ListNode* curr = pair.neighbors.GetHead();
		if (curr != nullptr) {
			graph.append(curr->vertex + "");
			curr = curr->next;
		}
		while (curr != nullptr)
		{
			graph.append(" ->" + curr->vertex);
			curr = curr->next;
		}
		graph.append("\n")
		i++;
	}
}
