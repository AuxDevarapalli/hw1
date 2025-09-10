/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

int main(int argc, char* argv[])
{
  Node first(2,nullptr);
  //Node* second;
  //second->value = 3;
  //second->next = nullptr;
  //first.value = 2;
  //first.next = nullptr;

  Node* in = &first;
  Node* odds = nullptr;
  Node* evens = nullptr;
  split(in,odds,evens);
  std::cout <<evens->value<<std::endl;
  if(odds){
    std::cout <<odds->value<<std::endl;
  }
  else{
    std::cout<<"empty"<<std::endl;
  }
  
}
