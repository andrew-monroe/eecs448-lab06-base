/**
*	@author Andy Monroe
*	@date 11/1/2017
*	@file Test.cpp
*	@brief Tests for LinkedList
*/

#include <iostream>
#include "LinkedListOfInts.h"
#include "TestSuite.h"

TestSuite::TestSuite()
{
}

int TestSuite::runTests()
{
  if (canCreateEmptyList())
    std::cout << greenText("canCreateEmptyList") << std::endl;
  else
    std::cout << redText("canCreateEmptyList") << std::endl;

	if (canAddBack())
    std::cout << greenText("canAddBack") << std::endl;
  else
    std::cout << redText("canAddBack") << std::endl;

  if (canAddFront())
    std::cout << greenText("canAddFront") << std::endl;
  else
    std::cout << redText("canAddFront") << std::endl;

  if (canSearch())
    std::cout << greenText("canSearch") << std::endl;
  else
    std::cout << redText("canSearch") << std::endl;

/*
  if (())
    std::cout << greenText("") << std::endl;
  else
    std::cout << redText("") << std::endl;
*/
	return (0);

}

bool TestSuite::canCreateEmptyList() {
  bool passed = true;

  LinkedListOfInts emptyList;

  if (emptyList.isEmpty() != true)
    passed = false;

  if (emptyList.size() != 0)
    passed = false;  

  return passed;
}

bool TestSuite::canAddBack() {
  bool passed = true;

  LinkedListOfInts myList;

  myList.addBack(1);

  if (myList.isEmpty() != false)
    passed = false;

  if (myList.size() != 1)
    passed = false;

  return passed;
}

bool TestSuite::canAddFront() {
  bool passed = true;

  LinkedListOfInts myList;

  myList.addFront(1);

  if (myList.isEmpty() != false)
    passed = false;

  if (myList.size() != 1)
    passed = false;

  return passed;
}

bool TestSuite::canSearch() {
  bool passed = true;

  LinkedListOfInts myList;

  myList.addFront(1);

  if (myList.search(1) != true)
    passed = false;

  if (myList.search(2) != false)
    passed = false;

  return passed;
}

std::string TestSuite::redText(std::string str) {
  return "\033[0;31m" + str + "\033[0m";
}

std::string TestSuite::greenText(std::string str) {
  return "\033[0;32m" + str + "\033[0m";
}
