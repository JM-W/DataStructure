#include <iostream>
#include "dGraph.h"
#include "GQueue.h"

int main()
{
	//dGraph mygraph = dGraph();
	//mygraph.InsertEdge(1, 2);
	//mygraph.InsertEdge(1, 4);
	//mygraph.InsertEdge(1, 3);
	//mygraph.Print();
	ElementType tmp[6];
	ElementType dq;
	for (int i = 1; i <= 5; i++)
	{
		tmp[i] = new dGraph::Vertex(i);
	}
	GQueue myGQueue;
	myGQueue.Enqueue(tmp[1]);
	myGQueue.Enqueue(tmp[3]);
	myGQueue.Print();
	std::cout << "Dequeue next!" << std::endl;
	dq = myGQueue.Dequeue();
	std::cout << "I Dequeue " << dq->Index << std::endl;

	myGQueue.Print();

	
	for (int i = 1; i <= 5; i++)
	{
		delete tmp[i];
	}



	system("pause");
	return 0;

}