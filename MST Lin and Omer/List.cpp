#include "List.h"

List::~List()
{
	MakeEmpty();
	
}
void List::MakeEmpty()
{
	ListNode* curr = head;
	ListNode* save;
	while (curr != nullptr)
	{
		save = curr->next;
		delete curr;
		curr = save;
	}
	this->head = this->tail = nullptr;
}

void List::InsertToTail(Vertex u, Weight weight)
{
	ListNode* node = new ListNode{ u,weight };
	InsertToTail(node);
}

void List::InsertToTail(ListNode* add)
{
	size++;
	if (head == nullptr)
	{
		head = tail = add;
		return;
	}
	this->tail->next = add;
	add->prev = tail;
	tail = add;
	add->next = nullptr;
}

bool List::IsEmpty() const
{
	return (head == nullptr);
}

void List::PrintList() const
{
	ListNode* curr = head;
	while (curr != nullptr)
	{
		cout << "(" << curr->vertex << ", " << curr->weight << ") -> ";
		curr = curr->next;
	}
	cout << "//" << endl;
}

bool List::IsVertexInList(Vertex v) const
{
	ListNode* currentNode = head;
	while (currentNode != nullptr)
	{
		if (currentNode->vertex == v)
			return true;
		currentNode = currentNode->next;
	}
	return false;
}

void List::DeleteNode(Vertex toDelete)
{
	/*if (toDelete < 0 || toDelete >= size)
		return;*/
	size--;
	ListNode* curr = head;
	ListNode* save;
	if (head == nullptr)
		return;

	while ((curr != nullptr))
	{
		if (toDelete == curr->vertex)
		{
			if (curr == head && curr == tail)
			{
				MakeEmpty();
			}
			else if (curr == head)
			{
				head = curr->next;
				head->prev = nullptr;
				delete curr;
			}
			else if (curr == tail)
			{
				tail = curr->prev;
				tail->next = nullptr;
				delete curr;
			}
			else
			{
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				delete curr;
			}
			return;
		}
		curr = curr->next;
	}
}

