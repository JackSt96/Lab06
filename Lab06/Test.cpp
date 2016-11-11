#include "Test.h"

void Test::runTests(){
  testIsEmpty();
  testSize();
  testSearch();
  testAddBack();
  testAddFront();
  testRemoveBack();
  testRemoveFront();
}

bool Test::testIsEmpty()
{
  bool isPassed = true;
  LinkedListOfInts testList;
  if(!testList.isEmpty()){
    isPassed = false;
  }
  printResults(isPassed,"Test 1 of isEmpty() has:");
  testList.addFront(1);
  if(testList.isEmpty()){
    isPassed = false;
  }
  printResults(isPassed,"Test 2 of isEmpty() has:");
  return isPassed;
}

bool Test::testSize()
{
  std::string message = "size() has:";
  bool isPassed = true;
  LinkedListOfInts testList;
  if (testList.size()!=0) {
    isPassed = false;
  }
  for(int i = 0; i<30; i++){
    testList.addBack(i);
  }
  if(testList.size()!=30){
    isPassed = false;
  }
  printResults(isPassed,message);
  return(isPassed);
}

bool Test::testSearch()
{
  LinkedListOfInts testList;
  for(int i = 0; i<50; i++){
    testList.addFront(i);
  }
  bool isPassed = testList.search(30);
  printResults(isPassed,"When looking for 30 (exists) search() has:" );
  isPassed = !testList.search(51);
  printResults(isPassed,"When looking for 51 (doesn't exist) search() has:" );
  return isPassed;
}

bool Test::testAddBack()
{
  std::string message = "";
  bool isPassed = true;
  LinkedListOfInts testList;
  for(int i = 0; i<25; i++){
    testList.addBack(i);
  }
  std::vector<int> v = testList.toVector();
  if(v.size() != 25){
    isPassed = false;
    message = message+"incorrect size ";
  }
  if(v.back()!=24){
    isPassed = false;
    message = message+"incorrect back number ";
  }
  printResults(isPassed, message+"addBack() has:");
  return isPassed;
}

bool Test::testAddFront()
{
  std::string message = "";
  bool isPassed = true;
  LinkedListOfInts testList;
  for(int i = 0; i<25; i++){
    testList.addFront(i);
  }
  std::vector<int> v = testList.toVector();
  if(v.size() != 25){
    isPassed = false;
    message = message+"wrong size ";
  }
  if(v.front() != 24){
    isPassed = false;
    message = message+"wrong front number ";
  }
  printResults(isPassed, message+"addFront() has:");
  return isPassed;
}

bool Test::testRemoveBack()
{
  bool isPassed = true;
  std::string message = "";
  LinkedListOfInts testList;
  for(int i = 0; i<25; i++){
    testList.addFront(i);
  }
  testList.removeBack();
  if (testList.size()!=24) {
    isPassed = false;
    message = std::to_string(testList.size());
  }
  printResults(isPassed,message+": should be 24 removeBack() has:");
  return isPassed;
}

bool Test::testRemoveFront()
{
  bool isPassed = true;
  std::string message = "";
  LinkedListOfInts testList;
  for(int i = 0; i<25; i++){
    testList.addFront(i);
  }
  testList.removeFront();
  if (testList.size()!=24) {
    isPassed = false;
    message = std::to_string(testList.size());
  }
  printResults(isPassed,message+": should be 24 removeFront() has:");
  return isPassed;
}

void Test::printResults(bool isPassed, std::string message)
{
  std::cout << message;
  if(isPassed){
    std::cout << " PASSED" << std::endl;
  }
  else{
    std::cout << " FAILED" << std::endl;
  }
}
