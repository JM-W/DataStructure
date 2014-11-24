#ifndef GPQUEUE


#define NumVer 7
typedef int ElementType;


class BinHeap
{
public:
	BinHeap() :Size(0)
	{

	};
	ElementType Element[NumVer+1];
	int Size;
public:
	void Insert(ElementType X);
	ElementType DeleteMin();
};




#define GPQUEUE
#endif