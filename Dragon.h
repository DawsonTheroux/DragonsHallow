#ifndef DRAGON_H
#define DRADON_H

#include "Enemy.h"

class Dragon: public Enemy{
 public:
  Dragon(QuestPlayer*,QuestPlayer*); //ctor.
  virtual void move();               //Move function.
  virtual void foundRing();          //Tells the dragon class that the ring was found.
  virtual bool isWearingRing();      //Returns true if the dragon has collected the ring.
 private:
  static bool hasRing;               //bool that represents if the dragon has the ring.
  bool movingUp;                     //Boolean to determine direction of movment.
  QuestPlayer* arr[2];               //The Questplayers in the game to help him move with the ring.
};

#endif
