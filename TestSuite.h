/**
*   @file TestSuite.h
*   @author Andy Monroe
*   @date 11/1/2017
*   @brief A header file for TestSuite class
*/

#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include <vector>
#include <string>
#include "LinkedListOfInts.h"

class TestSuite
{
  public:
    TestSuite();
    int runTests();
    bool canCreateEmptyList();
    bool canAddBack();
    bool canAddFront();
    bool canSearch();
    bool canConvertToVector();
    bool canRemoveBack();
    bool canRemoveFront();

  private:
    std::string redText(std::string str);
    std::string greenText(std::string str);
};

#endif
