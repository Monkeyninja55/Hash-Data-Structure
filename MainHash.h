// File:    MainHash.h
// Project: CMSC341 Project 5
// Author:  Kush Patel
// Date:    May 10, 2016
// Section: 04
// E-mail:  pak2@umbc.edu 
//
// This file contains C++ code for a header file
// with the member functions of the MainHash class.
//


#ifndef MAINHASH_H
#define MAINHASH_H

#include "SecondHash.h"

class MainHash {

 public:

  MainHash(int size);
  ~MainHash();

  //-------------------------------------------------------
  // Name: hashString
  // PreCondition: Takes in a string 
  // PostCondition: Returns an array index
  //---------------------------------------------------------
  long hashString(string key);

  //-------------------------------------------------------
  // Name: insert
  // PreCondition: Takes in two strings 
  // PostCondition: Array size changed
  //---------------------------------------------------------
  void insert(string data1, string data2);

  //-------------------------------------------------------
  // Name: search
  // PreCondition: Takes in a string 
  // PostCondition: None
  //---------------------------------------------------------
  void search(string data1);

  //-------------------------------------------------------
  // Name: printStats
  // PreCondition: None
  // PostCondition: None
  //---------------------------------------------------------
  void printStats();

 private:

  SecondHash * mainArray;

  long Prime1;
  long Prime2;
  long seed;
  long m_size;

  long a;
  long b;
  long c;

};

#endif
