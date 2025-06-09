// AiLinh
// Implementation of CovidDB

#include <iostream>
#include "CovidDB.h"
#include <unordered_map>
#include <vector>
#include <string>
#include "DataEntry.h"
#include <fstream>
#include <sstream>

using namespace std;

CovidDB::CovidDB(){
  m = 17;
  table.resize(m);
}

CovidDB::~CovidDB(){
  for ( auto& bucket: table){
    for (auto entry: bucket){
      delete entry;
    }
    bucket.clear();
  }

  table.clear();
}

int CovidDB:: hash(string country){
  int sum = 0;
  int size = country.length();   
  for (int i = 0; i < size; i++ ){
    char c = country[i];
    sum += (i+1)*(int)c;
  }
    sum = sum % m;
    
    return sum;
}

void CovidDB::readCSV( const string& filename){
  
  ifstream input;
  input.open(filename);
  
  if( input.fail()){
    cerr << endl << "Error open file" << endl;
    return;
  }
  string line;
  getline(input, line);

  while (getline(input, line)){
    stringstream ss(line);
    string date, country;
    int cases, death;
    
    getline(ss,date, ',');
    getline(ss,country, ',');
    ss >> cases;
    
    ss.ignore(1,',');
    ss >> death;
    
    DataEntry* entry = new DataEntry(date,country, cases, death);
    add(entry);
    
  }
  input.close();
}

int CovidDB:: dateToInt ( const string& date){
  stringstream ss(date);
  string token;
  int day, month , year;

  getline(ss,token,'/');
  month = stoi(token);

  getline(ss,token,'/');
  day = stoi(token);

  getline(ss,token,'/');
  year = stoi(token);

  return year*10000 + month*100 +day;


}
bool CovidDB:: add( DataEntry* entry){
   
  int index = hash(entry->getCountry());
  

  if ( table[index].empty()){
    
    table[index].push_back(entry);
    return true;
  }

  else {
  for ( auto &tempCurr: table[index]){
      if ( tempCurr->getCountry() == entry->getCountry()){
        int dayEntry = dateToInt(entry->getDate());
        int dayCurr = dateToInt(tempCurr->getDate());


        if ( dayEntry < dayCurr){
          delete entry;
          return false;
        }
        else {
          tempCurr->setDate(entry->getDate());
          tempCurr->setCases(entry->getCases());
          tempCurr->setDeaths( entry->getDeaths());
          delete entry;
          return true;

        }
      }
    }

  table[index].push_back(entry);
  return true;

  }
  
}

DataEntry* CovidDB:: get(string country){
  int index = hash(country);

  if (table[index].empty()){
    return nullptr;
  }
  if ( index >=0 && index < m){
    for ( DataEntry* entry: table[index]){
      if ( entry->getCountry() == country){
        return entry;
      }
    }

  }
 
  return nullptr;
}

void CovidDB:: remove( string country){
  int index = hash(country);
  if ( index >=0 && index < m){
    for ( auto i = table[index].begin(); i!= table[index].end();){
      if ( (*i)->getCountry() == country){
        delete *i;
        i= table[index].erase(i);
        return;
      }
      else {
        ++i;
      }
    }
  }
  cout << endl << " No country in table" << endl;
}

void CovidDB::displayTable(){

  for ( int index = 0; index < m; index++){

    if ( !table[index].empty()){

      for ( DataEntry* entry: table[index]){
        
        cout << entry->getDate() << " " << entry->getCountry()
            <<" " << entry->getCases() << " " << entry->getDeaths() << endl;            
      }

    }

  }
}
