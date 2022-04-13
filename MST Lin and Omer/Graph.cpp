#include "Graph.h"


Graph::Graph(Vertex n, Edges m) : n(n), m(m)
{
	MakeEmptyGraph(n, m);
}

Graph::~Graph()
{
	for (GraphVertex vertex : verteciesArray)
	{
		delete vertex.neighbors;
		if (vertex.location_in_heap)
			delete vertex.location_in_heap;
	}
}

void Graph::MakeEmptyGraph(Vertex n, Edges m)
{
	this->n = n;
	this->m = m;
	for (int i = 0; i <= n; ++i)
	{
		GraphVertex newVertex;
		newVertex.neighbors = new List();
		newVertex.location_in_heap = nullptr;
		verteciesArray.push_back(newVertex);
	}
}

bool Graph::IsAdjacent(Vertex u, Vertex v) const
{
	if (!InGraph(u) || !InGraph(v))
		return false;
	if (verteciesArray.at(u).neighbors->IsVertexInList(v) == true)
		return true;
	return false;
}

List* Graph::GetAdjList(Vertex u)
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

	this->verteciesArray.at(u).neighbors->InsertToTail(v, w);
	this->verteciesArray.at(v).neighbors->InsertToTail(u, w);
	this->edgeArray.push_back({ u,v,w });
}

void Graph::RemoveEdge(Vertex u, Vertex v)
{
	if (!InGraph(u) || !InGraph(v) || !IsAdjacent(u, v)) //'parallel' edges
	{
		cout << "invalid input!";
		exit(1);
	}

	this->verteciesArray.at(u).neighbors->DeleteNode(v);
	this->verteciesArray.at(v).neighbors->DeleteNode(u);
	edgeArray.erase(remove_if(edgeArray.begin(), edgeArray.end(), [u, v](Edge edge) {
		return (edge.first_vertex == u && edge.second_vertex == v) ||
			(edge.first_vertex == v && edge.second_vertex == u);}), edgeArray.end());
}

string Graph::GetVisualGraph() const
{
	string graph;
	int i = 0;
	for (GraphVertex vertex : verteciesArray)
	{
		if (i == 0)
		{
			i++;
			continue;
		}
		graph += to_string(i) + ": ";
		ListNode* curr = vertex.neighbors->GetHead();
		if (curr != nullptr) {
			graph += to_string(curr->vertex_name) + "";
			curr = curr->next;
		}
		while (curr != nullptr)
		{
			graph += " -> " + to_string(curr->vertex_name);
			curr = curr->next;
		}
		graph += "\n";
		i++;
	}
	return graph;
}
