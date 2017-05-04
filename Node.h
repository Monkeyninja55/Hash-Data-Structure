// File:    Node.h
// Project: CMSC341 Project 5
// Author:  Kush Patel
// Date:    May 10, 2016
// Section: 04
// E-mail:  pak2@umbc.edu 
//
// This file contains C++ code for a header file for the Node structure.
//

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

struct Node {

  string key1;
  string key2;

  // default constructor
  // does nothing
  Node()
  {}

  // alternative constructor
  // initializes key1 and key2
  Node(string data1, string data2) : key1(data1), key2(data2)
  {}

  // destructor
  // does nothing
  ~Node()
  {}

};

#endif

