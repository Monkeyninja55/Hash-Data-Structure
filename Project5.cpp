// File:    Project5.cpp
// Project: CMSC341 Project 5
// Author:  Kush Patel
// Date:    May 10, 2016
// Section: 04
// E-mail:  pak2@umbc.edu 
//
// This file contains C++ code for a driver file that tests
// the member functions of the MainHash and SecondHash classes.
//

#include "MainHash.h"
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;


const string SEARCH_FOR_CITY = "Ringgold, GA";

int main(int argc, char *argv[])
{
  int size = 0;
  vector<string> cities;
  string filename;

  if (argc == 2)
    { filename = argv[1]; }
  else {
    cout << "Not enough command line arguments." << endl;
    return 0;
  }

  ifstream file(filename.c_str());

  // stores each line in a vector of strings
  if (file.is_open()) {

    string line;

    while(getline(file, line))
      { cities.push_back(line.c_str()); }
  }
  else {
    cout << "File was not opened." << endl;
    return 0;
  }

  // finds the total number of cities
  size = cities.size() / 2;

  MainHash perfectTable(size);

  for (unsigned int i = 0; i < cities.size(); i += 2) {
    perfectTable.insert(cities[i], cities[i + 1]); 
  }

  perfectTable.printStats();
  perfectTable.search(SEARCH_FOR_CITY);
}
