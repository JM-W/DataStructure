#include "GQueue.h"

void GQueue::Enqueue(ElementType ele)
{
	GList *ver = new GList(ele);
	if (ver == NULL)
	{
		Error("queue space is none!");
		return;
	}
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
ElementType GQueue::Dequeue()
{
	if (Ver == NULL)
	{
		return 0;
	}
	else
	{
		GList *tmp;
		ElementType i;
		tmp = Ver;
		i = tmp->Element;
		Ver = Ver->Next;
		delete tmp;
		return i;
	}
};
void GQueue::Print()
{
	if (Ver == NULL)
	{
		Error("The GQueue is None P!");
		return;
	}
	GList *tmp;
	tmp = Ver;
	while (tmp != NULL)
	{
		std::cout << tmp->Element << " ";
		tmp = tmp->Next;
	}
}

void GQueue::DeleteQueue()
{
	while (Ver != NULL)
	{
		Dequeue();
	}
}