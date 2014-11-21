#include <stdlib.h>
#include <iostream>
#include "fatal.h"


#define NumVer 7

#ifndef QGRAPH




class dGraph
{
public:
	class Vertex
	{
	public:
		Vertex(int Ind) :Index(Ind),Next(NULL){};
		int Index;
		Vertex *Next;
	};

public:
	dGraph()
	{
		for (int i = 1; i <= NumVer; i++)
		{
			edge[i] = new Vertex(i);
		}
	};
	~dGraph()
	{
		for (int i = 1; i <= NumVer; i++)
		{
			delete edge[i];
		}
	};
private:
	Vertex *edge[NumVer+1];
public:
	void InsertEdge(int Index1, int Index2)
	{
		if (edge[Index1] == NULL)
		{
			Error("The vertex is not in this Graph!");
			return;
		}
		Vertex *tmp,*ver;
		ver = new Vertex(Index2);
		tmp = edge[Index1]->Next;
		edge[Index1]->Next = ver;
		ver->Next = tmp;
	}
	void Print()
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
};

#define QGRAPH
#endif // !QGRAPH