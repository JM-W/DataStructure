#include <iostream>
#ifndef _DisjSet_

#define NumSets 10

typedef int DisjSet[NumSets + 1];
typedef int SetType;
typedef int ElementType;

void Initialization(SetType S);
void SetUnion(DisjSet S,SetType Root1,SetType Root2);
SetType Find(DisjSet S, ElementType X);


#endif // !_DisjSet_

void Initialization(DisjSet S)
{
	for (int i = 1; i <= NumSets; i++)
	{
		S[i] = 0;
	}
}
#ifdef SlowAlg

void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{

	S[Root2] = Root1;
}


SetType Find(DisjSet S, ElementType X)
{
	if (S[X] <= 0)
		return X;
	else
		Find(S, S[X]);
}


#else
void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
	if (S[Root2] < S[Root1])//Root2 is deeper;
		S[Root1] = Root2;
	else
	{
		if (S[Root1] == S[Root2])
			S[Root1]--;
		S[Root2] = Root1;
	}
}

SetType Find(DisjSet S, ElementType X)
{
	if (S[X] <= 0)
		return X;
	else
		S[X] = Find(S, S[X]);
}


#endif // SlowAlg

using namespace std;
int main()
{
	DisjSet disjSet;
	Initialization(disjSet);
	int i(1), j(2), k(3);
	int root1 = Find(disjSet, i);
	int root2 = Find(disjSet, j);
	int root3 = Find(disjSet, k);
	//cout << root1 << root2 << root3 << endl;
	SetUnion(disjSet, root1, root2);
	//cout << Find(disjSet, i) << Find(disjSet, j) << endl;
	SetUnion(disjSet, root1, root3);
	for (int i = 1; i < NumSets + 1; i++)
		cout << Find(disjSet, i) << endl;

	system("pause");
	return 0;

}
