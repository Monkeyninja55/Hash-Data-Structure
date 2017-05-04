// File:    MainHash.cpp
// Project: CMSC341 Project 5
// Author:  Kush Patel
// Date:    May 10, 2016
// Section: 04
// E-mail:  pak2@umbc.edu 
//
// This file contains C++ code for an implementation file
// with the member functions of the MainHash class.
//

#include "MainHash.h"

// default constructor
// initializes the seed, and the size
MainHash::MainHash(int size)
  : seed(0), m_size(size)
{
  mainArray = new SecondHash[m_size];

  Prime1 = 16890581;
  Prime2 = 17027399;

  srand(seed);
  c = rand() % Prime1 + 1;
  a = rand() % Prime2 + 1;
  b = rand() % Prime2;
}

// destructor
// deallocates array
MainHash::~MainHash()
{ delete [] mainArray; }

// hashString
// returns an array index
long MainHash::hashString(string key) {

  unsigned long long int x = 0;

  // hashes the string
  for (unsigned int i = 0; i < key.size(); i++)
    { x = (((x * c) + key[i]) % Prime1); }

  long index = ((((a * x) + b) % Prime2) % m_size);
  return index;
}

// insert
// inserts data into the array
void MainHash::insert(string data1, string data2) {

  long index = hashString(data1);
  mainArray[index].insertData(data1, data2);
}

// search
// finds the index the string is stored at
void MainHash::search(string data1) {

  long index = hashString(data1);

  cout << "city details: Key = " << index << endl;

  mainArray[index].findData(data1);
}

// printStats
// prints statistics of the primary and secondary arrays
void MainHash::printStats() {

  long maxCol = 0;
  long hashNum = 0;
  long size = 0;
  double avgFunc = 0;

  cout << endl;
  cout << "p1: " << Prime1 << endl;
  cout << "p2: " << Prime2 << endl;

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;
  cout << endl;

  cout << "number of cities: " << m_size << endl;

  // finds max number of collisions
  for (int i = 0; i < m_size; i++) {

    if (maxCol < mainArray[i].getMaxColls())
      { maxCol = mainArray[i].getMaxColls(); }
  }

  cout << "maximum collisions: " << maxCol << endl;

  // finds total number of i collisions
  for (int i = 0; i < 10; i++) {

    int collsNum = 0;
    cout << "# primary slots with " << i << " cities: ";

    for (int j = 0; j < m_size; j++) {

      if (mainArray[j].getMaxColls() == i)
        { collsNum += 1; }      
    }
    cout << collsNum << endl;
  }

  // prints each item in the index with the most collisions
  for (int i = 0; i < m_size; i++) {

    if (maxCol == mainArray[i].getMaxColls()) {
      cout << "** cities in the slot with the most collisions **" << endl;
      mainArray[i].printArray();
      break;
    }
  }

  // prints the total number of i hash functions last called 
  for (int i = 1; i <= 10; i++) {
    int funcNum = 0;
    cout << "# secondary hash tables trying " << i << " hash functions: ";

    for (int j = 0; j < m_size; j++) {
      if (mainArray[j].getMaxColls() > 0) {

        if (mainArray[j].getHashFuncs() == i)
          { funcNum += 1; }  
      }    
    }
    cout << funcNum << endl;
  }

  // finds the total number of secondary tables with more than one item
  for (int i = 0; i < m_size; i++) {

    if (mainArray[i].getMaxColls() > 1)
      { hashNum += 1; }      
  }
  cout << "number of secondary hash tables with more than one item: " << hashNum << endl;

  // finds the average number of hash functions tried
  for (int i = 0; i < m_size; i++) {

    if (mainArray[i].getMaxColls() >= 2) {
      avgFunc += mainArray[i].getHashFuncs(); 
      size += 1;
    }
  }

  avgFunc = avgFunc / size;
  cout << "average # of hash functions tried: " << avgFunc << endl;
}

