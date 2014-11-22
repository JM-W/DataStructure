#include <iostream>
#include "dGraph.h"
#include "GQueue.h"

int main()
{

	/*test for queue*/

	//ElementType tmp[6];
	//ElementType dq;
	//for (int i = 1; i <= 5; i++)
	//{
	//	tmp[i] = i;
	//}
	//GQueue myGQueue;
	//myGQueue.Enqueue(tmp[1]);
	//myGQueue.Enqueue(tmp[3]);
	//myGQueue.Print();
	//std::cout << "Dequeue next!" << std::endl;
	//dq = myGQueue.Dequeue();
	//std::cout << "I Dequeue " << dq << std::endl;

	//myGQueue.Print();
	//myGQueue.DeleteQueue();
	//myGQueue.Print();

	/*-----------------------------------------------*/

	dGraph myGraph;
	myGraph.InsertEdge(2, 1);
	myGraph.InsertEdge(2, 3);
	int TopNum[NumVer + 1];
	myGraph.TopSort(TopNum);

	for (int i = 1; i < NumVer + 1; i++)
		std::cout << TopNum[i] << std::endl;

	




	system("pause");
	return 0;

}