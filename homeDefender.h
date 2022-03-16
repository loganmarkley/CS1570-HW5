#ifndef HOMEDEFENDER_H
#define HOMEDEFENDER_H

#include <iostream> 
using namespace std; 

struct newHomeowner{
  string m_name;
  string m_address;
  float m_originalAcres;
  float m_newAcres;
  int m_originalGarages;
  int m_newGarages;
};

struct neighbor{
  int m_id;
  float m_originalAcres;
  float m_newAcres;
  int m_originalGarages;
  int m_newGarages;
  bool m_goodNeighbor;
  bool m_activeNeighbor;
  bool m_stoleLand;
};

//description: initialize the struct parameter using user inputs
//pre: theNewHomeowner must be a newHomeowner struct
//post: theNewHomeowner's member variables are initialized with user inputs
void initializeUser(newHomeowner & theNewHomeowner);

//description: initialize the struct parameter using random inputs
//pre: aNeighbor must be a neighbor struct
//post: aNeighbor's member variables are initialized with random values
void initializeNeighbor(neighbor & aNeighbor);

//description: this function should be called when the homeowner encounters a GOOD neighbor, it will than use random percent chance
//             to determine if aGoodNeighbor will gift a garage to theNewHomeowner
//pre: theNewHomeowner must be a newHomeowner struct and aGoodNeighbor must be a neighbor struct that has m_goodNeighbor==true
//post: Either theNewHomeowner gains 1 garage and aGoodNeighbor loses 1 garage, or their values do not change.
//      Text is also displayed to see what happens to the values
void requestAssistance(newHomeowner & theNewHomeowner, neighbor & aGoodNeighbor);

//description: this function should be called when the homeowner encounters a BAD neighbor, it will than use random percent chance
//             to determine if aBadNeighbor will steal land from theNewHomeowner or if theNewHomeowner will take stolen
//            land back (if aBadNeighbor has stolen land before).
//pre: theNewHomeowner must be a newHomeowner struct and aBadNeighbor must be a neighbor struct that has m_goodNeighbor==false
//post: Either theNewHomeowner takes all stolen land back from aBadNeighbor, half the stolen land back , or aBadNeighbor steals
//      land from theNewHomeowner, or their values do not change. Text is also displayed to see what happens to the values
void defendHomeland(newHomeowner & theNewHomeowner, neighbor & aBadNeighbor);

//description: displays theNewHomeowner's current acres of land and number of garages and how
//             much each changed from last round to the current round
//pre: theNewHomeowner must be a newHomeowner struct, startOfRoundAcres must be a float, startOfRoundGarages must be an int
//post: the END-OF-ROUND SUMMARY section (which holds the above information) is displayed to the user.
void roundSummary(const newHomeowner theNewHomeowner, const float startOfRoundAcres, const int startOfRoundGarages);

//description: displays theNewHomeowner's information using its member variables, then displays EVERY element in neighborArray
//             and each neighbor's member values
//pre: theNewHomeowner must be a newHomeowner struct, neighborArray must be an array of neighbor structs, totalNeighbors must be an int
//post: the BATTLE SUMMARY section (which holds the above information) is displayed to the user.
void battleSummary(const newHomeowner theNewHomeowner, const neighbor neighborArray[], const int totalNeighbors);

#endif
