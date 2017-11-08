/**
*   @file TestSuite.h
*   @author Andy Monroe
*   @date 11/1/2017
*   @brief A header file for TestSuite class
*/

#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include <vector>
#include <algorithm>
#include <string>
#include "LinkedListOfInts.h"

class TestSuite
{
  public:
    TestSuite();
    int runTests();
  private:
    void outputTestResult(std::string funcName, std::string errors);
    std::string canCreateEmptyList();
    std::string canCheckSize();
    std::string canConvertToVector();
    std::string canCheckIsEmpty();
    std::string canAddBack();
    std::string canAddFront();
    std::string canSearch();
    std::string canRemoveBack();
    std::string canRemoveFront();
    std::string redText(std::string str);
    std::string greenText(std::string str);
    std::string vecToString(std::vector<int> vec);
};

#endif
