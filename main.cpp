//Programmer: Logan Markley
//Student ID: 12579435
//MST Username: lcmkbc
//Instructor Name: San Yeung
//Section: 109
//Date: 3/9/22
//File: main.cpp
//Purpose: make home defender program in C++ (HW 5)

#include "homeDefender.h"

#include <string>
#include <iostream>
using namespace std;

int main()
{
  srand(327);
  const int totalNeighborCount=6;
  int roundCount=0;
  bool acresLeft=true;
  bool badNeighborsLeft=true;
  
  cout<<endl<<endl<<"Congratulations new homeowner!!! Please tell me about yourself!"<<endl;
  newHomeowner user;
  initializeUser(user);
  cout<<endl<<"Sweet cookies! The neighborhood is lucky to have you, "<<user.m_name<<"!";

  neighbor neighborArray[totalNeighborCount];
  int goodNeighborCount=0;
  int badNeighborCount=0;
  for(int i=0; i<totalNeighborCount; i++)
  {
    initializeNeighbor(neighborArray[i]);
    if(neighborArray[i].m_goodNeighbor)
      goodNeighborCount++;
    else
      badNeighborCount++;
  }
  
  cout<<" Looks like you have "<<badNeighborCount<<" bad neighbors and "<<goodNeighborCount<<" good neighbors, and they can't wait to show you around."<<endl<<endl;
  if(goodNeighborCount==totalNeighborCount)
  {
    badNeighborsLeft=false;
    cout<<"You have no bad neighbors!!! Congratulations!!!"<<endl;
  }
  
  while(badNeighborsLeft && acresLeft && roundCount<10)
  {
    roundCount++;
    cout<<"ROUND "<<roundCount<<":"<<endl;
    float startOfRoundUserAcres=user.m_newAcres;
    int startOfRoundUserGarages=user.m_newGarages;
    int activeBadNeighborCount=0;
    for(int i=0; i<totalNeighborCount; i++)
    {
      if(neighborArray[i].m_goodNeighbor)
      {
        cout<<"\tGood neighbor ID #"<<neighborArray[i].m_id<<" has "<<neighborArray[i].m_newGarages<<" garages, and you have "<<user.m_newGarages<<" garages."<<endl;
        requestAssistance(user, neighborArray[i]);
      }
      else if(neighborArray[i].m_activeNeighbor)
      {
        cout<<"\tBad neighbor ID #"<<neighborArray[i].m_id<<" has "<<neighborArray[i].m_newGarages<<" garages, and you have "<<user.m_newGarages<<" garages."<<endl;
        defendHomeland(user, neighborArray[i]);
        if(neighborArray[i].m_activeNeighbor)     //if the bad neighbor is still active after the defense
          activeBadNeighborCount++;
      }
      cout<<endl;
    }
    roundSummary(user, startOfRoundUserAcres, startOfRoundUserGarages);
  }
  
  battleSummary(user, neighborArray, totalNeighborCount);
  
  if(roundCount>0)
    cout<<endl<<"Goodbye, "<<user.m_name<<"! The next time you buy a house, make sure that there's no bad neighbors around it."<<endl;
  cout<<endl<<endl;
  return 0;
}
