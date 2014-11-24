#include <stdlib.h>
#include <iostream>
#include "fatal.h"


#define NumVer 7
#define Infinity 100

#ifndef QGRAPH



class Table;
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
		FirstVertex(int Ind,int W) :Vertex(Ind), indgree(0),Weight(W){};
	public:
		int indgree;
		int Weight;
	};

public:
	dGraph()
	{
		for (int i = 1; i <= NumVer; i++)
		{
			edge[i] = new FirstVertex(i);
		}
	};
	dGraph(int W[NumVer + 1])
	{
		for (int i = 1; i <= NumVer; i++)
		{
			edge[i] = new FirstVertex(i,W[i]);
		}
	}
	~dGraph()
	{
		for (int i = 1; i <= NumVer; i++)
		{
			delete edge[i];
		}
	};
private://private
	FirstVertex *edge[NumVer+1];
public:
	void InsertEdge(int Index1, int Index2);

	void Print();

	void TopSort(int top[]);

	void UnWeight(Table *T);


};
class Table
{
	struct TVertex
	{
		bool known;
		int distance;
		int path;
		TVertex() :known(false), distance(Infinity), path(0){}
	};
public:
	TVertex *tVertex[NumVer+1];
public:
	Table()
	{
		for (int i = 0; i < NumVer + 1;i++)
		{
			tVertex[i] = new TVertex;
		}
		
	};
	~Table()
	{
		for (int i = 0; i < NumVer + 1; i++)
		{
			delete tVertex[i];
		}
	}
};

#define QGRAPH
#endif // !QGRAPH