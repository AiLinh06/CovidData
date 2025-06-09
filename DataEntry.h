// AiLinh
// header for DataEntry


#include <iostream>
#include <string>
using namespace std;

#ifndef DATAENTRY_H
#define DATAENTRY_H


class DataEntry{
  
private:
  string date;
  string country;
  int c_cases;
  int c_deaths;
  
public:
  DataEntry(string d, string c, int cases, int deaths); 
  //DataEntry(const DataEntry& other) = default;

  string getDate();
  string getCountry();
  int getCases();
  int getDeaths();
  
  void setDate( string newDate);
  void setCases( int newCases);
  void setDeaths(int newDeaths);
};
#endif
