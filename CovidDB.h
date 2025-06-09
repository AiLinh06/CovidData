// AiLinh
// Header file for CovidDB

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include "DataEntry.h"
#include <fstream>
#include <sstream>

using namespace std;

#ifndef COVIDDB_H
#define COVIDDB_H

class CovidDB{
private:

  vector<vector<DataEntry*>>table;
  int m ; // size of table

  int hash( string country);
  int dateToInt ( const string& date);
  
public:
  CovidDB();
  ~CovidDB();
  bool add( DataEntry* entry);
  DataEntry* get(string country);
  void remove( string country);
  void displayTable();
  void readCSV ( const string& filename);
 

};
#endif
