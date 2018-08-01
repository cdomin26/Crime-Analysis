/*classes.h*/

//
// Classes for use with Chicago Crime Analysis program, e.g. "CrimeReport" 
// and "CrimeCode".
//
// << Christian Dominguez >>
// U. of Illinois, Chicago
// CS 341: Spring 2018
// Project 02
//

#pragma once

#include <iostream>
#include <string>

using namespace std;

class CrimeCode
{
  private:
    string Code;
    string Category;
    string Description;
    int Count;
    
  public:
    CrimeCode(string code, string cat, string desc, int count)
      : Code(code), Category(cat), Description(desc), Count(count)
    {}
    
    string getCode(){
      return Code;
    }
    
    string getCategory(){
      return Category;
    }
    
    string getDescription(){
      return Description;
    }
    
    void updateCount(){
      Count = Count + 1;
    }
    
    int getCount(){
      return Count;
    }
  
};//End of CrimeCode class

class CrimeReport
{
  private:
    string Date_Time;
    string IUCR;
    string Arrest;
    string Domestic;
    int Beat;
    int District;
    int Ward;
    int Community;
  
  public:
    CrimeReport(string dt, string iucr, string arrest, string domestic, int beat, int dist, int ward, int com)
     : Date_Time(dt), IUCR(iucr), Arrest(arrest), Domestic(domestic), Beat(beat), District(dist), Ward(ward), Community(com) 
    {}
    
    string getDateAndTime(){
      return Date_Time;
    }
    
    string getIUCR(){
      return IUCR;
    }
    
    string getArrest(){
      return Arrest;  
    }
    
    string getDomestic(){
      return Domestic;
    }
    
    int getBeat(){
      return Beat; 
    }
    
    int getDistrict(){
      return District;
    }
    
    int getWard(){
      return Ward;
    }
    
    int getCommunity(){
      return Community;
    }
  
};//End of CrimeReport class
