/**
*	@author 
*	@date 
*	@file main.cpp
*	@brief driver for LinkedList demo
*/
#include <iostream>
#include "LinkedListOfInts.h"
#include "TestSuite.h"

int main(int argc, char** argv)
{

	TestSuite myTester;

  std::cout << "Begin testing..." << std::endl;  

	myTester.runTests();

	std::cout << "Complete." << std::endl;
	
	return (0);

}

