// AiLinh
// assignment4

#include <iostream>
#include "CovidDB.h"
#include "DataEntry.h"

using namespace std;
void menu();
void generate(int choice, CovidDB* &test);

int main(){
  
  CovidDB* test = new CovidDB();
  int choice = -1;

  menu();
  cin >> choice;

  while ( choice > 0 && choice < 6){
    generate(choice, test);
    menu();
    cin >> choice;
  }
  
  delete test;
   
  cout << endl << endl;
  return 0;
}

void menu(){

  cout << endl << endl << "Covid Tracker"<< endl;
  cout << "Please choose the operation you want:" << endl;
  cout << " 1. Create the initial hash table " << endl;
  cout << " 2. Add a new data entry" << endl;
  cout << " 3. Get a data entry " << endl << " 4. Remove a data entry " << endl;
  cout << " 5. Display hash table" << endl << " 0. Quit the system " << endl;
  cout << endl;
}

void generate ( int choice, CovidDB* &test){

  switch (choice)
  {
  case 1:
    cout << endl << "Create a hash table" << endl;
    test->readCSV("WHO-COVID-data.csv");
    break;
  
  case 2:{
    cout << endl << "Add a new data entry" << endl;
    string newDate;
    string newCountry;
    int cases = -1;
    int deaths = -1;

    cout << endl << "Enter the date (month/day/year): ";
    cin.ignore();
    getline(cin, newDate);
    
    cout << endl << "Enter country's name: ";
   
    getline(cin, newCountry);

    while ( cases < 0){
      cout << endl << "Enter number of cases (> = 0): ";
      cin >> cases;
    }

    while ( deaths < 0 || deaths > cases){
      cout << endl <<" Enter number of death (>=0 and less than cases): " ;
      cin >> deaths;
    }

    if (test->add(new DataEntry(newDate, newCountry, cases, deaths))){
      cout << "Add Succesfully !" << endl;
    }
    else {
      cout << "Cannot add !" << endl;
    }

    break;
  }

  case 3:{
    string target;
    cout << endl << "Get a data entry" << endl;
    cout << "Enter country's name: ";
    cin.ignore();
    getline(cin, target);
    DataEntry* temp = test->get(target);

    if ( temp == nullptr){
      cout << " Cannot find!" << endl;
    }
    else {
      cout << " Found it!" << endl;

      cout << temp->getDate() << " " << temp->getCountry() 
          << " " << temp->getCases() << " " << temp->getDeaths() << endl;
      // delete temp;
    }
  
    break;
 
  }

  case 4:{
    string target;
    cout << "Remove a data entry" << endl;
    cout << "Enter the country's name: ";
    cin.ignore();
    getline(cin, target);

    test->remove(target);
    cout << endl << "DONE" << endl;
    break;
  }

  case 5:
    cout << "Display table" << endl;
    test->displayTable();
    cout << endl;
  };
    
}
