#ifndef ENEMY_H
#define ENEMY_H

#include "QuestPlayer.h"

class Enemy:public QuestPlayer{
 public:
  Enemy(string, char, int);           //ctor.
  virtual void move();                //Moves the Enemy.
  virtual void collide(QuestPlayer*); //Checks the collisions for Enemy.
  virtual void foundRing();           //Tells the enemy class that the ring was found.
  virtual bool isWearingRing();       //Gets if the enemy class has the ring.
  virtual int getStrength();          //Gets the strength depending on if they have the ring.
  
 private:
  static bool hasRing;                //True if they enemies have the ring.
};

#endif
