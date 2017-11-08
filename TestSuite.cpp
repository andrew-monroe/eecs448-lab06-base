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
  std::string errors = "";

  errors = canCreateEmptyList();
  outputTestResult("canCreateEmptyList",errors);

  errors = canAddBack();
  outputTestResult("canAddBack",errors);

  errors = canAddFront();
  outputTestResult("canAddFront",errors);

  errors = canCheckSize();
  outputTestResult("canCheckSize",errors);

  errors = canCheckIsEmpty();
  outputTestResult("canCheckIsEmpty",errors);

  errors = canConvertToVector();
  outputTestResult("canConvertToVector",errors);

  errors = canSearch();
  outputTestResult("canSearch",errors);

  errors = canRemoveBack();
  outputTestResult("canRemoveBack",errors);

  errors = canRemoveFront();
  outputTestResult("canRemoveFront",errors);

	return (0);
}

// Private:

void TestSuite::outputTestResult(std::string funcName, std::string errors) {
  if (errors == "") {
    std::cout << greenText(funcName + " - PASSED") << std::endl;
  } else {
    std::cout << redText(funcName + " - FAILED\n\n\tComparisons Failed:") << std::endl;
    std::cout << errors << std::endl;
  }
  return;
}

std::string TestSuite::canCreateEmptyList() {
  std::string errors = "";

  LinkedListOfInts emptyList;

  if (emptyList.isEmpty() != true) {
    errors += "\tExpected: list.isEmpty() == true\n";
    errors += "\tGot: list.isEmpty() == false\n";
  }

  if (emptyList.size() != 0) {
    errors += "\tExpected: list.isEmpty() == true\n";
    errors += "\tGot: list.isEmpty() == false\n";
  }

  return errors;
}

std::string TestSuite::canCheckSize() {
  std::string errors = "";

  LinkedListOfInts emptyList;
  LinkedListOfInts listOfOne;
  LinkedListOfInts listOfFive;

  listOfOne.addFront(1);

  listOfFive.addFront(1);
  listOfFive.addFront(2);
  listOfFive.addFront(3);
  listOfFive.addFront(4);
  listOfFive.addFront(5);

  if (emptyList.size() != 0) {
    errors += "\tExpected: emptyList.size() == 0\n";
    errors += "\tGot: emptyList.size() == " + std::to_string(emptyList.size()) + "\n";
  }

  if (listOfOne.size() != 1) {
    errors += "\tExpected: listOfOne.size() == 1\n";
    errors += "\tGot: listOfOne.size() == " + std::to_string(listOfOne.size()) + "\n";
  }

  if (listOfFive.size() != 5) {
    errors += "\tExpected: listOfFive.size() == 1\n";
    errors += "\tGot: listOfFive.size() == " + std::to_string(listOfFive.size()) + "\n";
  }

  return errors;
}

std::string TestSuite::canCheckIsEmpty() {
  std::string errors = "";

  LinkedListOfInts emptyList;
  LinkedListOfInts frontAdded;
  LinkedListOfInts backAdded;

  frontAdded.addFront(1);
  backAdded.addBack(1);

  if (emptyList.isEmpty() != true) {
    errors += "\tExpected: emptyList.isEmpty() == true\n";
    errors += "\tGot: emptyList.isEmpty() == false\n"; 
  }

  if (frontAdded.size() == 1 && frontAdded.isEmpty() != false) {
    errors += "\tExpected: frontAdded.isEmpty() == false\n";
    errors += "\tGot: frontAdded.isEmtpy() == true\n";
  }

  if (backAdded.size() == 1 && backAdded.isEmpty() != false) {
    errors += "\tExpected: backAdded.isEmpty() == false\n";
    errors += "\tGot: backAdded.isEmpty() == true\n";
  }

  return errors;
}

std::string TestSuite::canConvertToVector() {
  std::string errors = "";

  std::vector<int> emptyVec;
  std::vector<int> simpleVec = {-1,0,1,2};
  
  LinkedListOfInts emptyList;
  LinkedListOfInts simpleList;

  simpleList.addFront(2);
  simpleList.addFront(1);
  simpleList.addFront(0);
  simpleList.addFront(-1);

  std::vector<int> listAsVec = simpleList.toVector();

  if (emptyList.toVector() != emptyVec) {
    errors += "\tExpected: list.toVector() == []\n";
    errors += "\tGot: list.toVector() == " + vecToString(emptyList.toVector()) + "\n";
  }
  
  if (!std::equal(listAsVec.begin(), listAsVec.end(), simpleVec.begin())) {
    errors += "\tExpected: list.toVector() == [-1,0,1,2]\n";
    errors += "\tGot: list.toVector() == " + vecToString(listAsVec) + "\n";
  }

  return errors;
}

std::string TestSuite::canAddBack() {
  std::string errors = "";

  LinkedListOfInts myList;

  myList.addBack(1);
  myList.addBack(2);
  myList.addBack(-5);

  std::vector<int> correctVec = {1,2,-5};
  std::vector<int> listAsVec = myList.toVector();

  if (myList.size() != 3) {
    errors += "\tExpected: list.size() == 3\n";
    errors += "\tGot: list.size() == " + std::to_string(myList.size()) + "\n";
  }

  if(!std::equal(listAsVec.begin(),listAsVec.end(),correctVec.begin())) {
    errors += "\tExpected: list.toVector() == [1,2,-5]\n";
    errors += "\tGot: list.toVector() == " + vecToString(listAsVec) + "\n";
  }

  return errors;
}

std::string TestSuite::canAddFront() {
  std::string errors = "";

  LinkedListOfInts myList;

  myList.addFront(1);
  myList.addFront(2);
  myList.addFront(-5);

  std::vector<int> correctVec = {-5,2,1};
  std::vector<int> listAsVec = myList.toVector();

  if (myList.size() != 3) {
    errors += "\tExpected: list.size() == 3\n";
    errors += "\tGot: list.size() == " + std::to_string(myList.size()) + "\n";
  }

  if(!std::equal(listAsVec.begin(),listAsVec.end(),correctVec.begin())) {
    errors += "\tExpected: list.toVector() == [-5,2,1]\n";
    errors += "\tGot: list.toVector() == " + vecToString(listAsVec) + "\n";
  }

  return errors;
}

std::string TestSuite::canSearch() {
  std::string errors = "";

  LinkedListOfInts myList;

  myList.addFront(1);

  if (myList.search(1) != true) {
    errors += "\tExpected: list.search(1) == true\n";
    errors += "\tGot: list.search(1) == false\n";
  }

  if (myList.search(2) != false) {
    errors += "\tExpected: list.search(2) == false\n";
    errors += "\tGot: list.search(2) == true\n";
  }

  return errors;
}

std::string TestSuite::canRemoveBack() {
  std::string errors = "";

  LinkedListOfInts myList;

  if (myList.removeBack())
    errors += "\tExpected: list.removeBack == ERROR\n";

  myList.addFront(3);
  myList.addFront(2);
  myList.addFront(1);

  if (myList.size() != 3) {
    errors += "\tExpected: list.size() == 3\n";
    errors += "\tGot: list.size() == " + std::to_string(myList.size()) + "\n";
  }

  myList.removeBack();

  std::vector<int> correctVec = {2,3};
  std::vector<int> listAsVec = myList.toVector();

  if (myList.size() != 2) {
    errors += "\tExpected: list.size() == 2\n";
    errors += "\tGot: list.size() == " + std::to_string(myList.size()) + "\n";
  }

  if (!std::equal(listAsVec.begin(),listAsVec.end(),correctVec.begin())) {
    errors += "\tExpected: list.toVector() == [2,3]\n";
    errors += "\tGot: list.toVector() == " + vecToString(listAsVec) + "\n";
  }

  return errors;
}

std::string TestSuite::canRemoveFront() {
  std::string errors = "";

  LinkedListOfInts myList;

  if (myList.removeFront())
    errors += "\tExpected: list.removeFront == ERROR\n";

  myList.addFront(3);
  myList.addFront(2);
  myList.addFront(1);

  if (myList.size() != 3) {
    errors += "\tExpected: list.size() == 3\n";
    errors += "\tGot: list.size() == " + std::to_string(myList.size()) + "\n";
  }

  myList.removeFront();

  std::vector<int> correctVec = {1,2};
  std::vector<int> listAsVec = myList.toVector();

  if (myList.size() != 2) {
    errors += "\tExpected: list.size() == 2\n";
    errors += "\tGot: list.size() == " + std::to_string(myList.size()) + "\n";
  }

  if (!std::equal(listAsVec.begin(),listAsVec.end(),correctVec.begin())) {
    errors += "\tExpected: list.toVector() == [1,2]\n";
    errors += "\tGot: list.toVector() == " + vecToString(listAsVec) + "\n";
  }

  return errors;
}

std::string TestSuite::redText(std::string str) {
  return "\033[0;31m" + str + "\033[0m";
}

std::string TestSuite::greenText(std::string str) {
  return "\033[0;32m" + str + "\033[0m";
}

std::string TestSuite::vecToString(std::vector<int> vec) {
  std::string str = "[";

  for (unsigned int x = 0; x < vec.size() - 1; x++) {
    str += std::to_string(vec[x]) + ",";
  }

  str += std::to_string(vec[vec.size()-1]) + "]";
  return str;
}
