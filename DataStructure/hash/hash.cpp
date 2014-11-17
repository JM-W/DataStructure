#include<string>
#include<iostream>
#include"fatal.h"
#include"hash.h"


#define MinTableSize (1)

struct ListNode
{
    ElementType Element;
    Position Next;
};

typedef Position List;

struct HashTbl
{
    int TableSize;
    List* Lists;
};

Index Hash(ElementType Key,int TableSize)
{
    Index H(0);
    while(*Key!='\0')
    {
        H = (H<<5) + *Key++;
    }
    return H%TableSize;
}

HashTable InitializeTable(int Size)
{
    if(Size<MinTableSize)
    {
        Error("This Size is too small!");
        return NULL;
    }
    HashTable H = (HashTbl*)malloc(sizeof(HashTbl));
    if(H==NULL)
    {
        Error("There is no free space!");
        return NULL;
    }
    H->TableSize = Size;
    H->Lists = (List*)(malloc(sizeof(List)*H->TableSize));
    if(H->Lists==NULL)
    {
        Error("There is no free space for Lists!");
        return NULL;
    }


    //headNode

    for(int i = 0;i<H->TableSize;i++)
    {
        H->Lists[i] = (List)malloc(sizeof(ListNode));
        H->Lists[i]->Next = NULL;
    }

    return H;
}

void DestroyTable(HashTable H)
{
    int i;
    for(i = 0;i<H->TableSize;i++)
    {
        List l = H->Lists[i];
        List tmp;
        while(l!=NULL)
        {
            tmp = l;
            l=l->Next;
            free(tmp);
        }
    }
        free(H->Lists);
        free(H);
        std::cout<<"DestroyTable success!"<<std::endl;
}

Position Find(ElementType Key,HashTable H)
{
    List l;
    Position p;
    Index i = Hash(Key,H->TableSize);
    l = H->Lists[i];
    p = l->Next;
    while(p!=NULL&&strcmp(p->Element,Key))
        p = p->Next;
    return p;
}


void Insert(ElementType Key,HashTable H)
{
    Position p,NewCell;
    List l;
    p = Find(Key,H);
    if(p==NULL)
    {
        l = H ->Lists[Hash(Key,H->TableSize)];
        NewCell = (Position)malloc(sizeof(ListNode));
        NewCell ->Element = Key;//???????????strcpy(NewCell ->Element,Key);
        NewCell ->Next = l ->Next;
        l ->Next = NewCell;
    }
}

ElementType Retrieve(Position P)
{
    return P->Element;
}


























