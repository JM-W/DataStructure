#include "dGraph.h"
#include "GQueue.h"

void dGraph::InsertEdge(int Index1, int Index2)
{
	if (edge[Index1] == NULL)
	{
		Error("The vertex is not in this Graph!");
		return;
	}
	Vertex *tmp, *ver;
	ver = new Vertex(Index2);
	tmp = edge[Index1]->Next;
	edge[Index1]->Next = ver;
	ver->Next = tmp;
	edge[Index2]->indgree++;
}
void dGraph::Print()
{
	for (int i = 1; i <= NumVer; i++)
	{
		Vertex *p;
		p = edge[i];
		while (p != NULL)
		{
			std::cout << p->Index << ' ';
			p = p->Next;
		}
		std::cout << std::endl;
	}
}
void dGraph::TopSort(int top[NumVer+1])
{
	int indgr[NumVer + 1];
	indgr[0] = 0;
	top[0] = 0;
	GQueue myQueue;
	for (int i = 1; i <= NumVer; i++)
	{
		indgr[i] = edge[i]->indgree;
		if (indgr[i] == 0)
			myQueue.Enqueue(i);
	}

	int Index,i;

	for (i = 1; i < NumVer + 1; i++)
	{
		Index = myQueue.Dequeue();
		if (Index == 0)
		{
			Error("The Queue is None");
			break;
		}
		top[i] = Index;
		Vertex *tmp;
		tmp = edge[Index]->Next;
		while (tmp!=NULL)
		{
			edge[tmp->Index]->indgree--;
			if (edge[tmp->Index]->indgree == 0)
				myQueue.Enqueue(tmp->Index);
			tmp = tmp->Next;
		}
	}
	if (--i != NumVer)
		Error("The graph has a circle!");
}
void dGraph::UnWeight(Table *T)
{
	GQueue myGQueue;
	for (int i = 0; i <= NumVer; i++)
	{
		if (T->tVertex[i]->known == false && T->tVertex[i]->distance == 0)
		{
			myGQueue.Enqueue(i);
		}
	}

	int V=myGQueue.Dequeue();

	if (V == 0)
	{
		Error("There is no start point!");
		return;
	}
	Vertex *tmp;
	while (V!=0)
	{
		T->tVertex[V]->known = true;
		tmp = edge[V]->Next;
		while ((tmp != NULL) && (T->tVertex[tmp->Index]->known == false))
		{
			int W = tmp->Index;
			T->tVertex[W]->distance = T->tVertex[V]->distance + 1;
			T->tVertex[W]->path = V;
			tmp = tmp->Next;
			myGQueue.Enqueue(W);
		}
		V = myGQueue.Dequeue();
	}

	myGQueue.DeleteQueue();
	return;
};