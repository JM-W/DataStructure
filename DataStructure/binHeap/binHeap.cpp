#include"binHeap.h"
#include"fatal.h"
#include<stdlib.h>
#include<iostream>

using namespace std;

#define MinPQSize (10)
#define MinData (-32767)

struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType *elements;
};

PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;
    if(MaxElements < MinPQSize)
        Error("Priority queue size is too small");
    H = new HeapStruct;
    if(H == NULL)
        Error("Out of Space!!!");
    H->elements = new int[MaxElements+1];
    H->Size = 0;
    H->elements[0]=MinData;
    return H;
}

void Destory(PriorityQueue H)
{
    delete H->elements;
    delete H;
}

void MakeEmpty(PriorityQueue H)
{
    H->Size = 0;
}

void Insert(ElementType X,PriorityQueue H)
{
    if(IsFull(H))
    {
        Error("The Heap id full!");
        return;
    }

    int i=++H->Size;/// i=H->++Size is wrong.
    for(; X<H->elements[i/2]; i/=2)
    {
        H->elements[i]=H->elements[i/2];
    }
    H->elements[i]=X;
    return;
}

ElementType DeleteMin(PriorityQueue H)
{
    if(IsEmpty(H))
    {
     Error("The Heap is Empty");
     return H->elements[0];
    }
    int i,child;
    ElementType MinElement = H->elements[1];///it's just for return?
    ElementType X=H->elements[H->Size--];


    for(i=1;2*i<=H->Size;i=child)///i is not here to define.
    {
        /// i have some difficult in this place/// find the smaller child.
        child = 2*i;
        if(child!= H->Size&&H->elements[child]<H->elements[child+1])
            child++;
        ///down
        if(H->elements[child]<X)
            H->elements[i]=H->elements[child];
        else
            break;///Don't forget to break to out the "for",,.
    }
    H->elements[i] = X;///it's not H->elements[child] = X  is i.
    return MinElement;

}

ElementType FindMin(PriorityQueue H)
{
    ///i forget the judge is empty?
    if(!IsEmpty(H))
        return H->elements[1];
    Error("The Heap is Empty!");
    return H->elements[0];

}

bool IsEmpty(PriorityQueue H)
{
    return H->Size == 0;
}

bool IsFull(PriorityQueue H)
{
    return H->Size == H->Capacity;
}

int main()
{
    PriorityQueue TestHeap;
    TestHeap = Initialize(10);
    Insert(3,TestHeap);
    Insert(2,TestHeap);
    Insert(1,TestHeap);
    for(int i=1;i<4;i++)
        cout<<TestHeap->elements[i]<<endl;
    return 0;
}




