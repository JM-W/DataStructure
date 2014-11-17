#include<stdio.h>
#include<stdlib.h>
#include "fatal.h"
#include <iostream>

using namespace std;

const int chileNum = 26;

struct TrieNode
{
	const char* str;
	char letter;
	int cnt;
	bool is_terminal;
	TrieNode *child[chileNum];
	TrieNode() :str(NULL),letter(0), cnt(0), is_terminal(false)
	{
		for (int i = 0; i < 26;i++)
		{
			child[i] = NULL;
		}
	}
};

struct TrieTree
{
public:

	TrieTree():Root(NULL){};

	~TrieTree(){
		delete Root;
	};


	public:
	TrieNode *Root;//private

public:
	TrieNode* Creat() //Not creat the tree   is the node...
	{
		TrieNode* N = new TrieNode;
		return N;
	}

	void Insert(const char* X) // no need to pass the TrieTree
	{
		if (Root == NULL)
		{
			Root = Creat();
		}
		const char* wholestr=X;///wair to identify??????
		TrieNode* n;
		n = Root;
		while (*X != '\0')
		{
			int i = *X - 'a';
			//tmp = n->child['*X' - 'a'];
			if (n->child[i] == NULL)
			{
				n->child[i] = Creat();  /// no use tmp = new TrieNode;
				n->child[i]->letter = *X;
			}
			if (*(++X) == '\0')
			{
				n->child[i]->is_terminal = true;
				n->child[i]->str = wholestr;
			}
			n->child[i]->cnt++;
			n = n->child[i];
		}
	}

	bool Find(const char *X)
	{
		if (Root == NULL)
		{
			Error("Root is NULL!");
			return false;
		}
		TrieNode *n=Root;
		while (*X!='\0'&&n->child[*X-'a']!=NULL)
		{
			if (*(X + 1) == '\0'&&n->child[*X - 'a']->is_terminal==true)
			{
				return true;
			}
			n = n->child[*X++ - 'a'];
		}
		return false;
	}

	void PrintDlr(TrieNode *n)
	{
		if (n->is_terminal == true)
			cout << n->str << endl;
		for (int i = 0; i < chileNum; i++)
		{
			if (n->child[i]!=NULL)///fuck must be check the NULL;
			PrintDlr(n->child[i]);
		}
	}

	void DeleTree(TrieNode * N)
	{
		if (N != NULL)
		{
			for (int i = 0; i < 26;i++)
			{
				TrieNode * child = N->child[i];
				if (child!=NULL)
				{
					DeleTree(child);
				}
			}
			delete N;
		}
	}
};
