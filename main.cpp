/*main.cpp*/

//
// Chicago Crime Analysis program in modern C++.
//
// << Christian Dominguez >>
// U. of Illinois, Chicago
// CS 341: Spring 2018
// Project 02
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

#include "classes.h"

using namespace std;

void crimeCodesOutput(vector<CrimeCode> &CC){
  int size = CC.size();
  
  cout << "# of crime codes: " << size << endl;
  
  //Sorting the vector elements by crime code
  sort(CC.begin(), CC.end(),
    [](CrimeCode c1, CrimeCode c2)
      {
        if(c1.getCode() < c2.getCode()){
          return true;
        }
        else{
          return false;
        }
      }
  );//End of sort function
  
  //Outputting first and last three crime codes
  cout << CC[0].getCode() << ":   " << CC[0].getCategory() << ':' << CC[0].getDescription() << endl;
  cout << CC[1].getCode() << ":   " << CC[1].getCategory() << ':' << CC[1].getDescription() << endl;
  cout << CC[2].getCode() << ":   " << CC[2].getCategory() << ':' << CC[2].getDescription() << endl;
  
  cout << "..." << endl;
  
  cout << CC[size-3].getCode() << ":   " << CC[size-3].getCategory() << ':' << CC[size-3].getDescription() << endl;
  cout << CC[size-2].getCode() << ":   " << CC[size-2].getCategory() << ':' << CC[size-2].getDescription() << endl;
  cout << CC[size-1].getCode() << ":   " << CC[size-1].getCategory() << ':' << CC[size-1].getDescription() << endl;
  
  cout << "\n\n";
  
}//End of crimeCodesOutput()

void crimeReportsOutput(vector<CrimeReport> &CR){
  int size = CR.size();
  
  cout << "# of crimes: " << size << endl;
  
  //Outputting the first and last three crime reports
  cout << CR[0].getIUCR() << ":   " << CR[0].getDateAndTime() << ", " << CR[0].getBeat() << ", " << CR[0].getDistrict() << ", " << CR[0].getWard() << ", " << CR[0].getCommunity();
  if(CR[0].getArrest() == "TRUE" || CR[0].getArrest() == "true"){
    cout << ", arrested";
  }
  if(CR[0].getDomestic() == "TRUE" || CR[0].getDomestic() == "true"){
    cout << ", domestic violence";
  }
  cout << "\n";
  cout << CR[1].getIUCR() << ":   " << CR[1].getDateAndTime() << ", " << CR[1].getBeat() << ", " << CR[1].getDistrict() << ", " << CR[1].getWard() << ", " << CR[1].getCommunity();
  if(CR[1].getArrest() == "TRUE" || CR[1].getArrest() == "true"){
    cout << ", arrested";
  }
  if(CR[1].getDomestic() == "TRUE" || CR[1].getDomestic() == "true"){
    cout << ", domestic violence";
  }
  cout << "\n";
  cout << CR[2].getIUCR() << ":   " << CR[2].getDateAndTime() << ", " << CR[2].getBeat() << ", " << CR[2].getDistrict() << ", " << CR[2].getWard() << ", " << CR[2].getCommunity();
  if(CR[2].getArrest() == "TRUE" || CR[2].getArrest() == "true"){
    cout << ", arrested";
  }
  if(CR[2].getDomestic() == "TRUE" || CR[2].getDomestic() == "true"){
    cout << ", domestic violence";
  }
  cout << "\n";
  
  cout << "..." << endl;
  
  cout << CR[size-3].getIUCR() << ":   " << CR[size-3].getDateAndTime() << ", " << CR[size-3].getBeat() << ", " << CR[size-3].getDistrict() << ", " << CR[size-3].getWard() << ", " << CR[size-3].getCommunity();
  if(CR[size-3].getArrest() == "TRUE" || CR[size-3].getArrest() == "true"){
    cout << ", arrested";
  }
  if(CR[size-3].getDomestic() == "TRUE" || CR[size-3].getDomestic() == "true"){
    cout << ", domestic violence";
  }
  cout << "\n";
  cout << CR[size-2].getIUCR() << ":   " << CR[size-2].getDateAndTime() << ", " << CR[size-2].getBeat() << ", " << CR[size-2].getDistrict() << ", " << CR[size-2].getWard() << ", " << CR[size-2].getCommunity();
  if(CR[size-2].getArrest() == "TRUE" || CR[size-2].getArrest() == "true"){
    cout << ", arrested";
  }
  if(CR[size-2].getDomestic() == "TRUE" || CR[size-2].getDomestic() == "true"){
    cout << ", domestic violence";
  }
  cout << "\n";
  cout << CR[size-1].getIUCR() << ":   " << CR[size-1].getDateAndTime() << ", " << CR[size-1].getBeat() << ", " << CR[size-1].getDistrict() << ", " << CR[size-1].getWard() << ", " << CR[size-1].getCommunity();
  if(CR[size-1].getArrest() == "TRUE" || CR[size-1].getArrest() == "true"){
    cout << ", arrested";
  }
  if(CR[size-1].getDomestic() == "TRUE" || CR[size-1].getDomestic() == "true"){
    cout << ", domestic violence";
  }
  cout << "\n\n\n";  
    
}//End of crimeReportOutput()

void topFiveOutput(vector<CrimeCode> &CC){
  cout << "** Top-5 Crimes **" << endl;
  cout << "Code:   Total, Description" << endl;
  
  //Sorting by number of times each crime code appears in descending order
  sort(CC.begin(), CC.end(),
    [](CrimeCode c1, CrimeCode c2)
      {
        if(c1.getCount() > c2.getCount()){
          return true;
        }
        else{
          return false;
        }
      }
  );//End of sort function
  
  cout << CC[0].getCode() << ":   " << CC[0].getCount() << ", " << CC[0].getCategory() << ": " << CC[0].getDescription() << endl;
  cout << CC[1].getCode() << ":   " << CC[1].getCount() << ", " << CC[1].getCategory() << ": " << CC[1].getDescription() << endl;
  cout << CC[2].getCode() << ":   " << CC[2].getCount() << ", " << CC[2].getCategory() << ": " << CC[2].getDescription() << endl;
  cout << CC[3].getCode() << ":   " << CC[3].getCount() << ", " << CC[3].getCategory() << ": " << CC[3].getDescription() << endl;
  cout << CC[4].getCode() << ":   " << CC[4].getCount() << ", " << CC[4].getCategory() << ": " << CC[4].getDescription() << endl;
  cout << "\n";
  
  cout << "** Done **" << endl;
  cout << "\n";
  
}//End of topFiveOutput()

int main()
{
  string  crimeCodesFilename, crimesFilename;

  cin >> crimeCodesFilename;
  cout << crimeCodesFilename << endl;
  
  cin >> crimesFilename;
  cout << crimesFilename << endl;

  ifstream  codesFile(crimeCodesFilename);
  ifstream  crimesFile(crimesFilename);

  cout << std::fixed;
  cout << std::setprecision(2);

  if (!codesFile.good())
  {
    cout << "**ERROR: cannot open crime codes file: '" << crimeCodesFilename << "'" << endl;
    return -1;
  }
  if (!crimesFile.good())
  {
    cout << "**ERROR: cannot open crimes file: '" << crimesFilename << "'" << endl;
    return -1;
  }
  
  string line;
  
  //Data members used for CrimeCode vector
  vector<CrimeCode> codes;
  string code, category, description;
  
  //Data members used for CrimeReport vector
  vector<CrimeReport> reports;
  string date_time, IUCR, arrest, domestic, beat, district, ward, community, year;
  
  //Skipping the header in the crime code file
  getline(codesFile, line);
  
  //Getting the input from the crime codes file
  while(getline(codesFile, line)){
    stringstream ss(line);
    
    //Parsing the input
    getline(ss, code, ',');
    getline(ss, category, ',');
    getline(ss, description);
    
    CrimeCode cc(code, category, description, 0);
    
    codes.push_back(cc);
    
  }//End of crime code input loop
  
  //Skipping the header file in the Crime Report file
  getline(crimesFile, line);
      
  //Getting the input from the crime report file
  while(getline(crimesFile, line)){
    stringstream ss(line);
    
    //Parsing the input
    getline(ss, date_time, ',');
    getline(ss, IUCR, ',');
    getline(ss, arrest, ',');
    getline(ss, domestic, ',');
    getline(ss, beat, ',');
    getline(ss, district, ',');
    getline(ss, ward, ',');
    getline(ss, community, ',');
    getline(ss, year);
    
    //Counting the number of times each code occurs in the crime reports
    for(auto &x : codes){
      if(IUCR == x.getCode()){
        x.updateCount();
      }
    }
        
    CrimeReport cr(date_time, IUCR, arrest, domestic, stoi(beat), stoi(district), stoi(ward), stoi(community));
    
    reports.push_back(cr);
    
  }//End of crime report input file loop
  
  cout << "\n";
  cout << "** Crime Analysis **" << "\n\n";
  
  auto first = reports.front();
  auto last = reports.back();
  
  cout << "Date range: " << first.getDateAndTime() << " - " << last.getDateAndTime() << "\n\n";
  
  //Outputting the crime codes information
  crimeCodesOutput(codes);
 
  //Outputting the crime report information
  crimeReportsOutput(reports);
 
  //Outputting the top five crimes
  topFiveOutput(codes);
  
   return 0;
}//End of main()
