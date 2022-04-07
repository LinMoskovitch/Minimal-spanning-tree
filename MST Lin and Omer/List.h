#pragma once
#include "Utilities.h"

struct ListNode
{
	Vertex vertex;
	Weight weight;
	ListNode* next;
	ListNode* prev;
};

class List
{
private:
	ListNode* head;
	ListNode* tail;
	int size;

public:

	List() : head(nullptr), tail(nullptr), size(0) {}
	~List();
	void MakeEmpty();
	void InsertToTail(Vertex u, Weight weight);
	void InsertToTail(ListNode* add);
	void DeleteNode(Vertex toDelete);
	bool IsEmpty() const;
	void PrintList() const;
	bool IsVertexInList(Vertex v) const;

	ListNode* GetHead() const { return this->head; }
	int GetSize() const { return size; }


};
typedef struct ListPair
{
	List neighbors;
	* positionInHeap;
}ListPair;

typedef struct Edge
{
	Vertex u;
	Vertex v;
	Weight w;
}Edge;
