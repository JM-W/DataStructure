#include "dGraph.h"


#ifndef GQUEUE



typedef dGraph::Vertex* ElementType;


class GQueue
{
public:
	class GList
	{
	public:
		GList(ElementType ele) :Element(ele),Next(NULL){};
		ElementType  Element;
		GList* Next;
	};
public:
	GQueue()
	{ 
		Ver = End = NULL;
	};
	~GQueue(){};
public:
	void Enqueue(ElementType ele)
	{
		GList *ver = new GList(ele);
		if (Ver == NULL)
		{
			Ver = ver;
			End = ver;
		}
		else
		{
			End->Next = ver;
			End = ver;
			End->Next = NULL;
		}
	}
	ElementType Dequeue()
	{
		if (Ver == NULL)
		{
			Error("The GQueue is none!");
			return NULL;
		}
		else
		{
			GList *tmp;
			tmp = Ver;
			Ver = Ver->Next;
			return tmp->Element;
		}
	};
	void Print()
	{
		if (Ver == NULL)
		{
			Error("The GQueue is None!");
			return;
		}
		GList *tmp;
		tmp = Ver;
		while (tmp!=NULL)
		{
			std::cout << tmp->Element->Index << " ";
			tmp = tmp->Next;
		}
	}
private:
	GList *Ver;
	GList *End;
};

#define GQUEUE
#endif // !GQUEUE
