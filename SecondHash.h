// File:    SecondHash.h
// Project: CMSC341 Project 5
// Author:  Kush Patel
// Date:    May 10, 2016
// Section: 04
// E-mail:  pak2@umbc.edu 
//
// This file contains C++ code for a header file
// with the member functions of the SecondHash class.
//


#ifndef SECONDHASH_H
#define SECONDHASH_H

#include <stdlib.h>
#include <math.h>

#include "Node.h"

class SecondHash {

 public:

  SecondHash();
  ~SecondHash();

  //-------------------------------------------------------
  // Name: hash
  // PreCondition: Array size was initialized
  // PostCondition: Returns an array index
  //---------------------------------------------------------
  long hash(string key, long size);

  //-------------------------------------------------------
  // Name: rehash
  // PreCondition: Takes in two strings 
  // PostCondition: Array size changed
  //---------------------------------------------------------
  void rehash(string data1, string data2);

  //-------------------------------------------------------
  // Name: insertData
  // PreCondition: Takes in two strings 
  // PostCondition: Array size changed
  //---------------------------------------------------------
  void insertData(string data1, string data2);

  //-------------------------------------------------------
  // Name: findData
  // PreCondition: Takes in a string 
  // PostCondition: None
  //---------------------------------------------------------
  void findData(string data1);

  //-------------------------------------------------------
  // Name: getMaxColls
  // PreCondition: None
  // PostCondition: Returns the number of collisions
  //---------------------------------------------------------
  long getMaxColls();

  //-------------------------------------------------------
  // Name: getHashFuncs
  // PreCondition: None 
  // PostCondition: Returns the number of hash functions called
  //---------------------------------------------------------
  long getHashFuncs();

  //-------------------------------------------------------
  // Name: printArray
  // PreCondition: None
  // PostCondition: None
  //---------------------------------------------------------
  void printArray();

 private:

  Node** secondArray;

  long seed;
  long m_size;
  long hashFuncs;
  long items;

  long Prime1;
  long Prime2;

  long a;
  long b;
  long c;

};

#endif
