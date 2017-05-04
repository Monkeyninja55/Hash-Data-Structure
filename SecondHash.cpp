// File:    SecondHash.cpp
// Project: CMSC341 Project 5
// Author:  Kush Patel
// Date:    May 10, 2016
// Section: 04
// E-mail:  pak2@umbc.edu 
//
// This file contains C++ code for an implementation file
// with the member functions of the SecondHash class.
//

#include "SecondHash.h"

// default constructor
// initializes the seed, size, hash function counter, and collision counter
SecondHash::SecondHash()
  : seed(-1), m_size(1), hashFuncs(0), items(0)
{
  secondArray = new Node*[m_size];

  // sets each node as null
  for (int i = 0; i < m_size; i++)
    { secondArray[i] = NULL; }

  Prime1 = 16890581;
  Prime2 = 17027399;
}

// destructor
// deallocates nodes and array
SecondHash::~SecondHash() {

  // deletes each node
  for (int i = 0; i < m_size; i++)
    { delete secondArray[i]; }

  delete [] secondArray;
}

// hash
// returns an array index
long SecondHash::hash(string key, long size ) {

  unsigned long long int x = 0;

  // hashes the string
  for (unsigned int i = 0; i < key.size(); i++)
    { x = (((x * c) + key[i]) % Prime1); }

  long index = ((((a * x) + b) % Prime2) % size);

  return index;
}

// rehash
// rehashes the array
void SecondHash::rehash(string data1, string data2) {

  Node** nextArray = new Node*[items * items];
  long nextIndex = 0;
  long counter = 0;
  long tempSize = items * items;

  for (int i = 0; i < tempSize; i++)
    { nextArray[i] = NULL; }

  hashFuncs += 1;
  seed += 1;
  srand(seed);

  c = rand() % Prime1 + 1;
  a = rand() % Prime2 + 1;
  b = rand() % Prime2;

  // inserts nodes into nextArray
  for (int i = 0; i < m_size; i++) {

    if (secondArray[i] != NULL) {
      nextIndex = hash(secondArray[i]->key1, tempSize);

      if (nextIndex < tempSize && nextArray[nextIndex] == NULL) {
        counter += 1;
        nextArray[nextIndex] = new Node(secondArray[i]->key1, secondArray[i]->key2);
      }
    }
  }

  nextIndex = hash(data1, tempSize);

  if (nextIndex < tempSize && nextArray[nextIndex] == NULL) {
    counter += 1;
    nextArray[nextIndex] = new Node(data1, data2); 
  }

  // checks if all items were inserted
  if (counter != items) {

    for (int i = 0; i < tempSize; i++)
      { delete nextArray[i]; }

    delete [] nextArray;
    rehash(data1, data2);
  }
  else {

    for (int i = 0; i < m_size; i++)
      { delete secondArray[i]; }

    delete [] secondArray;
    secondArray = nextArray;
    m_size = items * items;
  }
}

// insertData
// inserts data into the array
void SecondHash::insertData(string data1, string data2) {

  items += 1;

  if (m_size == 1 && secondArray[0] == NULL)
    { secondArray[0] = new Node(data1, data2); }

  else {
    seed = -1;
    hashFuncs = 0;
    rehash(data1, data2);
  }
}

// findData
// finds the index the string is stored at
void SecondHash::findData(string data1) {

  long index = hash(data1, m_size);

  if (index < m_size && secondArray[index] != NULL) {

    if (secondArray[index]->key1 == data1)
      { cout << secondArray[index]->key1 << " (" << secondArray[index]->key2 << ")" << endl; }
    else
      { cout << "n/a" << endl; }
  }
  else
    { cout << "n/a" << endl; }
}

// getMaxColls
// returns the total collision counter
long SecondHash::getMaxColls()
{ return items; }

// getHashFuncs
// returns the hash function counter
long SecondHash::getHashFuncs()
{ return hashFuncs; }

// printArray
// prints each item in the array
void SecondHash::printArray() {

  for (int i = 0; i < m_size; i++) {

    if (secondArray[i] != NULL)
      { cout << secondArray[i]->key1 << " (" << secondArray[i]->key2 << ")" << endl; }
  }
}


