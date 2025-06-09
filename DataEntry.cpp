// AiLinh
// Implementation for DataEntry.h

#include <iostream>
#include <string>
#include "DataEntry.h"

using namespace std;

DataEntry::DataEntry(string d, string c, int cases, int deaths): date(d), country(c), c_cases(cases), c_deaths(deaths) {}



int DataEntry::getCases(){
    return c_cases;    
}

int DataEntry:: getDeaths(){
    return c_deaths;
}

string DataEntry:: getDate(){
    return date;
}

string DataEntry:: getCountry(){
    return country;
}

void DataEntry:: setDate( string newDate){
    date = newDate;
}

void DataEntry:: setCases( int newCases){
    c_cases+= newCases;
}

void DataEntry:: setDeaths ( int newDeaths){
    c_deaths += newDeaths;
}
