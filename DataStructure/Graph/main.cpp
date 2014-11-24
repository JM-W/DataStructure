#include <iostream>
#include "dGraph.h"
#include "GQueue.h"
#include "GPQueue.h"


int main()
{


	//dGraph *myGraph;
#ifdef TOPSORT


	myGraph.InsertEdge(1, 2);
	myGraph.InsertEdge(1, 3);
	myGraph.InsertEdge(2, 4);
	myGraph.InsertEdge(2, 5);
	myGraph.InsertEdge(3, 6);
	myGraph.InsertEdge(4, 3);
	myGraph.InsertEdge(4, 6);
	myGraph.InsertEdge(4, 7);
	myGraph.InsertEdge(5, 4);
	myGraph.InsertEdge(5, 7);
	myGraph.InsertEdge(7, 6);
	int TopNum[NumVer + 1];
	myGraph.TopSort(TopNum);

	std::cout << "This is topology sort!" << std::endl;
	for (int i = 1; i < NumVer + 1; i++)
		std::cout << TopNum[i] << std::endl;

#endif

#ifdef UNWEIGHT

	myGraph = new dGraph;

	myGraph->InsertEdge(1, 2);
	myGraph->InsertEdge(1, 4);
	myGraph->InsertEdge(2, 4);
	myGraph->InsertEdge(2, 5);
	myGraph->InsertEdge(3, 1);
	myGraph->InsertEdge(3, 6);
	myGraph->InsertEdge(4, 3);
	myGraph->InsertEdge(4, 5);
	myGraph->InsertEdge(4, 6);
	myGraph->InsertEdge(4, 7);
	myGraph->InsertEdge(5, 7);
	myGraph->InsertEdge(7, 6);
	std::cout << "This is short path from v3!" << std::endl;
	Table *T;
	T = new Table;
	T->tVertex[3]->distance=0;
	myGraph->UnWeight(T);

	for (int i = 0; i <= NumVer;i++)
	{
		std::cout << T->tVertex[i]->distance << std::endl;
	}

	delete T;
	delete myGraph;

#endif

	BinHeap H;
	H.Insert(5);
	H.Insert(1);
	H.Insert(2);
	H.Insert(4);
	H.Insert(3);



	

	std::cout << H.Element[1] << std::endl;
	std::cout << H.Element[2] << std::endl;
	std::cout << H.Element[3] << std::endl;
	std::cout << H.Element[4] << std::endl;
	std::cout << H.Element[5] << std::endl;
	//H.DeleteMin();
	//H.DeleteMin();
	//H.DeleteMin();
	//H.DeleteMin();
	//H.DeleteMin();
	//H.Insert(3);
	//H.Insert(7);


	std::cout << "Size: " << H.Size << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << H.DeleteMin() << std::endl;
	}
	





	system("pause");
	return 0;

}