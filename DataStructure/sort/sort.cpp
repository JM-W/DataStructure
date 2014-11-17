#include<iostream>
#include<stdlib.h>
#include"fatal.h"

using namespace std;

typedef int ElementType;

void InsertionSort (ElementType A[],int N)
{
     int i,p;
     ElementType X;
     for(p = 1; p<N; p++)
     {
         X = A[p];
         for(i = p;i>0&&A[i-1]>X;i--)
            A[i]=A[i-1];
         A[i] = X;
     }
}

void ShellSort (ElementType A[], int N)
{
    int h,p,i;
    ElementType X;
    for(h=N/2; h>0; h/=2)
    {
        for(p=h; p<N; p++)
        {
            X = A[p];
            for(i = p;i>=h&&A[i-h]>X;i-=h)
                A[i] = A[i-h];
            A[i] = X;
        }
    }
}



void PercDown(ElementType A[],int i,int N)
{
    int child;
    ElementType X;
    for(X=A[i];2*i+1<=N-1;i=child)
    {
        child=2*i+1;
        if(2*i+1!=N-1&&A[child]<A[child+1])
            child++;
        if(A[child]>A[i])
            A[i]=A[child];
        else
            break;/// i forget again.......
    }
    A[i]=X;
}

void HeapSort(ElementType A[],int N)
{
    for(int i=N/2;i>=0;i--)
        PercDown(A,i,N);
    for(int i=N-1;i>0;i--)
    {
        ElementType X=A[0];
        A[0]=A[i];
        A[i]=X;
        PercDown(A,0,i);
    }

}

void Merge(ElementType A[],ElementType TmpArray[],int Ls,int Rs,int Rend)
{
    int i = Ls,LeftEnd = Rs-1,NumElement = Rend - Ls + 1;///it's very necessary!
    for(;Ls<=LeftEnd&&Rs<=Rend;i++)
    {
        if(A[Ls]<A[Rs])
            TmpArray[i] = A[Ls++];
        else
            TmpArray[i] = A[Rs++];
    }
    if(Ls == LeftEnd+1)
    {
        for(;i<=Rend;i++)
        {
            TmpArray[i] = A[Rs++];
        }
    }
    else
    {
       for(;i<=Rend;i++)
        {
            TmpArray[i] = A[Ls++];
        }
    }
    for(int i=0;i<NumElement;i++,Rend--)
        A[Rend] = TmpArray[Rend];
}



void MSort(ElementType A[],ElementType TmpArray[],int Ls,int Rend)
{
    int Rs;///note not here
    if(Ls<Rend)
    {
        Rs = (Ls + Rend)/2+1;///is here
        MSort(A,TmpArray,Ls,Rs-1);
        MSort(A,TmpArray,Rs,Rend);
        Merge(A,TmpArray,Ls,Rs,Rend);
    }
}

void MergeSort(ElementType A[],int N)
{
    ElementType *TmpArray;
    TmpArray = (ElementType*)malloc(N*sizeof(ElementType));
    if (TmpArray == NULL)
        Error("the space is full");
    else
    {
        MSort(A,TmpArray,0,N-1);
        free(TmpArray);
    }
}


ElementType Media3(ElementType A[],int left,int right)
{
    int center = (left+right)/2;
    ///it's not good!
//    if((A[left]<A[center]&&A[center]<A[right])\
//        ||(A[left]>A[center]&&A[center]>A[right]))
//        swap(A[center],A[right]);
//    if((A[left]<A[center]&&A[left]>A[right])\
//        ||(A[left]>A[center]&&A[left]<A[right]))
//        swap(A[left],A[right]);
    if(A[left]>A[center])
        swap(A[left],A[center]);
    if(A[left]>A[right])
        swap(A[left],A[right]);
    if(A[center]>A[right])
        swap(A[center],A[right]);
    swap(A[center],A[right]);
    return A[right];

}

#define Cutoff ( 3 )
void QSort(ElementType A[],int left,int right)
{
    if(right-left>=Cutoff)
  {
    int End = right;
    int newleft=left;
    int v = Media3(A,left,right);
    int i=left;
    int j=right-1;///-1
    while(i<j)
    {
        while(A[i]<v)
            i++;
        while(A[j]>v)
            j--;
        if(i<j)
        {
        ElementType Tmp = A[i];
        A[i] = A[j];
        A[j] = Tmp;
        }
    }
    ElementType Tmp = A[i];
    A[i] = v;
    A[End] = Tmp;
    QSort(A,newleft,i-1);
    QSort(A,i+1,End);
  }
  else
    InsertionSort(A+left,right-left+1);///insert
}





int main()
{
    int A[8] = {2,4,1,3,5,7,8,6};
    for(int i = 0;i<8;i++)
        cout<<A[i]<<endl;
    //ElementType *TmpArray;
    //TmpArray =(ElementType*)malloc(5*sizeof(ElementType));
    //Merge(A,TmpArray,0,2,4);
    //Media3(A,0,4);
    QSort(A,0,7);
    for(int i = 0;i<8;i++)
        cout<<A[i]<<endl;
    cout<<Cutoff<<endl;
    cout<<"heh"<<endl;
    //cout<<Media3(A,0,4)<<endl;
    return 0;
}























