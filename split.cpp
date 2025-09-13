/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if (in == nullptr){
    return;
  }
  Node* starting = in;
  Node* nex = starting->next;
  starting->next = nullptr;
  in=nex;

//for only 1 item
  if (starting->value % 2==0 && nex==nullptr){
    //tracking the oldhead
    Node* oldStartingHead = evens;
    starting->next=evens;
    evens = starting;
    return;
  }

  //multiple items
  if (starting->value % 2==0){
    Node*oldStartingHead = evens;
    starting->next = evens;
    evens=starting;
  }
  //oddcase
  else{
    Node* oldStartingHead = odds;
    starting->next = odds;
    odds=starting;
  }
  split(in,odds,evens);
}

/* If you needed a helper function, write it here */
