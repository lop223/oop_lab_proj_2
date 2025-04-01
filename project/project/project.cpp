#include <iostream>
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"

int main()
{
 //   SingleLinkedList<int> listS;
	//listS.push_back(1);
	//listS.push_back(12);
	//listS.push_back(17);
	//listS.push_back(39);
	//listS.push_front(0);
	////listS.insert(0, -12);
	////listS.erase(2);


	//std::cout << "List: " << listS << std::endl;
	//std::cout << "Size: " << listS.getSize() << std::endl;
	//std::cout << "Third element: " << listS.get(3) << std::endl;
	//std::cout << "Index of 39: " << listS.find(39) << std::endl;
	//std::cout << "Is empty?: " << listS.isEmpty() << std::endl;

	DoubleLinkedList<int> listD;
	listD.push_back(1);
	listD.push_back(5);
	listD.push_back(17);
	listD.push_back(30);
	listD.push_back(112);
	listD.push_back(45);

	std::cout << "List: " << listD << std::endl;


	return 0;
}
