#include <stdlib.h>
#include <iostream>
#include "fatal.h"


#define NumVer 3

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

	class FirstVertex :public Vertex
	{
	public:
		FirstVertex(int Ind) :Vertex(Ind),indgree(0){};
	public:
		int indgree;
	};

public:
	dGraph()
	{
		for (int i = 1; i <= NumVer; i++)
		{
			edge[i] = new FirstVertex(i);
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
	FirstVertex *edge[NumVer+1];
public:
	void InsertEdge(int Index1, int Index2);

	void Print();

	void TopSort(int top[]);


};

#define QGRAPH
#endif // !QGRAPH