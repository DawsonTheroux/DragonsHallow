#ifndef RING_H
#define RING_H

#include "QuestPlayer.h"

//Purpose: Hold super powers that each class of QuestPlayer can use in a different way.
class Ring{
  public:
  Ring();                        //ctor.
  string getType();              //Gets the type of ring thats currently in play.
  void getCoords(int&, int&);    //Gets the coords of the ring.
  bool operator==(QuestPlayer&); //returns true if its the right type of ring at the right coords.
  bool found;                    //if the ring is found this is found.

 private:
  string type;                   //The type of ring in play.
  int x;                         //The x coord of the ring.
  int y;                         //The y coord of the ring.
  
};





#endif
