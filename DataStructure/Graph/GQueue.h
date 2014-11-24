#include "dGraph.h"


#ifndef GQUEUE



typedef int ElementType;


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
	void Enqueue(ElementType ele);

	ElementType Dequeue();

	void Print();

	void DeleteQueue();

private://private
	GList *Ver;
	GList *End;
};



#define GQUEUE
#endif // !GQUEUE
