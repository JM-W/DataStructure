#include "GPQueue.h"
#include <iostream>

void MySwap(int &i, int &j)
{
	int tmp = i;
	i = j;
	j = tmp;
	return;
}

void BinHeap::Insert(ElementType X)
{
	Element[++Size] = X;
	for (int i = Size; i > 0; i /= 2)
	{
		if (Element[i]<Element[i/2])
		{
			MySwap(Element[i], Element[i / 2]);
		}
	}
}

ElementType BinHeap::DeleteMin()
{
	ElementType res = Element[1];
	Element[1] = Element[Size--];
	int i = 1;
	int child = 2 * i;
	for (; i <= Size; i = child)
	{
		child = 2 * i;
		if (child <= Size)
		{
			if (child+1<=Size&&Element[child+1]<Element[child])
			{
				child++;
			}
			std::cout << "little child is : " << child << std::endl;
			if (Element[i]>Element[child])
				MySwap(Element[i], Element[child]);
			else
				break;
		}
	}

	return res;
}