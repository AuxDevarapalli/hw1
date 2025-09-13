#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  //from instructions i took this there
  ULListStr newList;
  newList.push_back("7");
  newList.push_front("1");
  newList.push_back("4");
  std::cout<<newList.get(0)<<" "<<newList.get(1)<<" "<<newList.get(2)<<std::endl;
}
