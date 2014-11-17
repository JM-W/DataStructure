#include<iostream>
#include <string>
#include<vector>
#include"Trie.h"

using namespace std;

int main()
{
	char *str1="wang";
	char *str2 = "ji";
	char *str3 = "min";
	string str("hehe");

	vector<string> vec_str;
	string Input;

	//char Input[] = "0";
	TrieTree *Tree;
	Tree = new TrieTree;
	Tree->Root = Tree->Creat();





	/*For Debug*/
	//Tree->Insert(str1);
	//Tree->Insert(str2);
	//Tree->Insert(str3);
	//Tree->Insert(str.c_str());
	//cout << Tree->Root->child[0]->letter << endl;
	//cout << Tree->Root->child[0]->child[1]->letter << endl;
	//if (Tree->Root->child[0]->child[1]->is_terminal == true)
	//	cout << "true" << endl;
	//cout << Tree->Root->child[0]->child[1]->str << endl;

	//cout << "PrintDlr is begining!" << endl;
	//Tree->PrintDlr(Tree->Root);
	//Tree->DeleTree(Tree->Root);





	while (cin >> Input)
	{
		if (Input[0] == '#')
			break;
		vec_str.push_back(Input);
	}

	for (vector<string>::size_type i = 0; i < vec_str.size(); i++)
	{
		Tree->Insert(vec_str[i].data());
	}

	Tree->PrintDlr(Tree->Root);
	Tree->DeleTree(Tree->Root);

	//while (cin >> Input)
	//{
	//	if (Input[0] == 's')
	//	{
	//		break;
	//	}
	//	//cout << "s?" << endl;
	//	Tree->Insert(Input.c_str());

	//}
	//cout << "we are finding now!" << endl;
	//while (cin >> Input)
	//{
	//	if (Input[0] == 's')
	//	{
	//		break;
	//	}
	//	if (Tree->Find(Input.data()))
	//	{
	//		cout << Input << " is in the trie tree!" << endl;
	//	}
	//	else
	//	{
	//		cout << Input << "is not in the trie tree!" << endl;
	//	}
	//}

	//Tree->PrintDlr(Tree->Root);

	//Tree->DeleTree(Tree->Root);


	system("pause");
	return 0;

}
