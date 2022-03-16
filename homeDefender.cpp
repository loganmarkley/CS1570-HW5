#include "homeDefender.h"

#include <string>
#include <iostream>
using namespace std;

void initializeUser(newHomeowner & theNewHomeowner)
{
  cout<<"May I get your name, please? ";
  cin>>theNewHomeowner.m_name;
  
  cout<<"First, could you tell me the address of your new home? ";
  cin.ignore();
  getline(cin, theNewHomeowner.m_address);

  cout<<"Time for a fresh start, eh? What's the total number of acres of your property? ";
  cin>>theNewHomeowner.m_originalAcres;
  theNewHomeowner.m_newAcres=theNewHomeowner.m_originalAcres;
  
  cout<<"I'll wait for that housewarming party invite. How many garages does the house have? ";
  cin>>theNewHomeowner.m_originalGarages;
  theNewHomeowner.m_newGarages=theNewHomeowner.m_originalGarages;
  return;
}

void initializeNeighbor(neighbor & aNeighbor)
{
  const int minRandomNum=19;
  const int maxRandomNum=50;
  static int idNum=0;
  
  aNeighbor.m_id=idNum;
  idNum++;
  aNeighbor.m_originalAcres=rand() % (maxRandomNum-minRandomNum+1) + minRandomNum;    //following the formula rand() % (max - min + 1) + min
  aNeighbor.m_newAcres=aNeighbor.m_originalAcres;
  
  aNeighbor.m_originalGarages=( static_cast<int>(aNeighbor.m_originalAcres)/10 ) % 10; //returns the tens digit;
  aNeighbor.m_newGarages=aNeighbor.m_originalGarages;
  
  if(rand() % 2)   //rand from 0 to 1, if 1, it's true
    aNeighbor.m_goodNeighbor=true;
  else
    aNeighbor.m_goodNeighbor=false;
  
  aNeighbor.m_activeNeighbor=true;
  aNeighbor.m_stoleLand=false;
  return;
}

void requestAssistance(newHomeowner & theNewHomeowner, neighbor & aGoodNeighbor)
{
  int randomNum=rand() % 100 + 1;
  if(theNewHomeowner.m_newGarages < aGoodNeighbor.m_newGarages)
  {
    const int percentGarageDonate=80;
    if(aGoodNeighbor.m_newGarages==0)
      cout<<"\tThis neighbor has no garages to give! Sorry!"<<endl;
    else if(randomNum<percentGarageDonate)
    {
      cout<<"\tExcuse me, do you need an extra garage? The good neighbor got one for you!"<<endl;
      theNewHomeowner.m_newGarages++;
      aGoodNeighbor.m_newGarages--;
      cout<<"\tYou have "<<theNewHomeowner.m_newGarages<<" garage(s) now."<<endl;
    }
    else
      cout<<"\tGarages? The good neighbor doesn’t have any extra available."<<endl;
  }
  else
  {
    const int percentGarageDonate=30;
    if(aGoodNeighbor.m_newGarages==0)
      cout<<"\tThis neighbor has no garages to give! Sorry!"<<endl;
    else if(randomNum<percentGarageDonate)
    {
      cout<<"\tExcuse me, do you need an extra garage? The good neighbor got one for you!"<<endl;
      theNewHomeowner.m_newGarages++;
      aGoodNeighbor.m_newGarages--;
      cout<<"\tYou have "<<theNewHomeowner.m_newGarages<<" garages now."<<endl;
    }
    else
      cout<<"\tGarages? The good neighbor doesn't have any extra available."<<endl;
  }
  return;
}

void defendHomeland(newHomeowner & theNewHomeowner, neighbor & aBadNeighbor)
{
  int randomNum=rand() % 100 + 1;
  if(theNewHomeowner.m_newGarages < aBadNeighbor.m_newGarages)
  {
    const int percentStealLand=53;
    if(randomNum<percentStealLand)
    {
      int garageDiff=aBadNeighbor.m_newGarages - theNewHomeowner.m_newGarages;
      if(theNewHomeowner.m_newAcres-garageDiff<0) //if the user will have negative acres, they just lose all of their land instead of going negative.
      {
        garageDiff=theNewHomeowner.m_newAcres;
        theNewHomeowner.m_newAcres-=garageDiff;
        aBadNeighbor.m_newAcres+=garageDiff;
        aBadNeighbor.m_stoleLand=true;
      }
      else
      {
        theNewHomeowner.m_newAcres-=garageDiff;
        aBadNeighbor.m_newAcres+=garageDiff;
        aBadNeighbor.m_stoleLand=true;
      }
      cout<<"\tThe bad neighbor's garages look better than yours! So hand over "<<garageDiff<<" acre(s) of land to your neighbor."<<endl; 
      cout<<"\tYou have "<<theNewHomeowner.m_newAcres<<" acres of land now."<<endl;
      randomNum=rand() % 100 + 1;
      const int percentNewGarage=46;
      if(randomNum<percentNewGarage)
      {
        cout<<"\tAnd guess what? The bad neighbor managed to build a new garage just now!"<<endl;
        aBadNeighbor.m_newGarages++;
      }
    }
    else
      cout<<"\tThe bad neighbor has no idea what's going on, so you are safe, run!"<<endl;
  }
  else if(aBadNeighbor.m_stoleLand)
  {
    const int minRandomNum=1;
    const int maxRandomNum=80;
    randomNum=rand() % (maxRandomNum-minRandomNum+1) + minRandomNum;
    if(randomNum%2==0)
    {
      randomNum=rand() % 100 + 1;
      float stolenLand=aBadNeighbor.m_newAcres - aBadNeighbor.m_originalAcres;
      const int percentReclaimHalf=73;
      if(randomNum<percentReclaimHalf)
      {
        cout<<"\tYou are in luck! You got back half of the stolen land from this bad neighbor."<<endl;
        if(stolenLand*0.5==1)
          cout<<"\t"<<stolenLand*0.5<<" acre of land reclaimed!"<<endl;
        else
          cout<<"\t"<<stolenLand*0.5<<" acres of land reclaimed!"<<endl;
        aBadNeighbor.m_newAcres-=stolenLand*0.5;
        theNewHomeowner.m_newAcres+=stolenLand*0.5;
        
      }
      else
      {
        cout<<"\tYou are super lucky! You got back ALL of the stolen land from this bad neighbor."<<endl;
        if(stolenLand==1)
          cout<<"\t"<<stolenLand<<" acre of land reclaimed!"<<endl;
        else
          cout<<"\t"<<stolenLand<<" acres of land reclaimed!"<<endl;
        cout<<"\tAmazing work! This bad neighbor is now inactive."<<endl;
        aBadNeighbor.m_newAcres-=stolenLand;
        theNewHomeowner.m_newAcres+=stolenLand;
        aBadNeighbor.m_activeNeighbor=false;
      }
    }
  }
  else
    cout<<"\tYou are safe, run!"<<endl;
  return;
}

void roundSummary(const newHomeowner theNewHomeowner, const float startOfRoundAcres, const int startOfRoundGarages)
{
  cout<<"\tEND-OF-ROUND SUMMARY:"<<endl;
  if(startOfRoundAcres<theNewHomeowner.m_newAcres)
    cout<<"\t\tCurrent acres of land: "<<theNewHomeowner.m_newAcres<<"   Change: +"<<theNewHomeowner.m_newAcres-startOfRoundAcres<<endl;
  else if(startOfRoundAcres>theNewHomeowner.m_newAcres)
    cout<<"\t\tCurrent acres of land: "<<theNewHomeowner.m_newAcres<<"   Change: -"<<startOfRoundAcres-theNewHomeowner.m_newAcres<<endl;
  else
    cout<<"\t\tCurrent acres of land: "<<theNewHomeowner.m_newAcres<<"   Change: 0"<<endl;
    
  if(startOfRoundGarages<theNewHomeowner.m_newGarages)
    cout<<"\t\tCurrent number of garages: "<<theNewHomeowner.m_newGarages<<"   Change: +"<<theNewHomeowner.m_newGarages-startOfRoundGarages<<endl<<endl;
  else if(startOfRoundAcres>theNewHomeowner.m_newAcres)
    cout<<"\t\tCurrent number of garages: "<<theNewHomeowner.m_newGarages<<"   Change: -"<<startOfRoundGarages-theNewHomeowner.m_newGarages<<endl<<endl;
  else
    cout<<"\t\tCurrent number of garages: "<<theNewHomeowner.m_newGarages<<"   Change: 0"<<endl<<endl;
  return;
}

void battleSummary(const newHomeowner theNewHomeowner, const neighbor neighborArray[], const int totalNeighbors)
{
  cout<<"HOME DEFENDER "<<theNewHomeowner.m_name<<"! Let's run through your battle summary!"<<endl;
  cout<<"\tHome Defender:   "<<theNewHomeowner.m_name<<endl;
  cout<<"\tHome Address:    "<<theNewHomeowner.m_address<<endl;
  cout<<"\tInitial Acres of Land Owned:    "<<theNewHomeowner.m_originalAcres<<endl;
  cout<<"\tFinal Acres of Land Owned:      "<<theNewHomeowner.m_newAcres<<endl;
  cout<<"\tInitial Number of Garages Owned:   "<<theNewHomeowner.m_originalGarages<<endl;
  cout<<"\tFinal Number of Garages Owned:	    "<<theNewHomeowner.m_newGarages<<endl;
  
  for(int i=0; i<totalNeighbors; i++)
  {
    cout<<endl;
    cout<<"\tNeighbor ID #:   "<<neighborArray[i].m_id<<endl;
    cout<<"\tAcres of Land Owned:    "<<neighborArray[i].m_newAcres<<endl;
    cout<<"\tAcres of Land Stolen:    "<<neighborArray[i].m_newAcres-neighborArray[i].m_originalAcres<<endl;
    cout<<"\tInitial Number of Garages Owned:   "<<neighborArray[i].m_originalGarages<<endl;
    cout<<"\tFinal Number of Garages Owned:	    "<<neighborArray[i].m_newGarages<<endl;
    if(neighborArray[i].m_goodNeighbor)
      cout<<"\tLikeable?   GOOD!"<<endl;
    else
      cout<<"\tLikeable?   BAD!"<<endl;
    if(neighborArray[i].m_activeNeighbor)
      cout<<"\tStatus:     Active"<<endl;
    else
      cout<<"\tStatus:     Inactive"<<endl;
  }
  return;
}
