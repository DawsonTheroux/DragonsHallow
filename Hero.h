#ifndef HERO_H
#define HERO_H

#include "QuestPlayer.h"

//Purpose:The Players trying to capture the emerald.
class Hero:public QuestPlayer{
 public:
  Hero(int,string,char,int);          //ctor. int = armour, string = name, char = display char, int = strength.
  virtual void move();                //Handles the heros movement.
  virtual void collide(QuestPlayer*); //Handles how the hero collides with other questplayers.
  virtual void foundRing();           //Tells the hero class that a hero has found the ring.
  virtual bool isWearingRing();       //Gets if they have found the ring.
 private:
  int armour;                         //The armour of the Hero.
  static bool hasRing;                //is true if they have the ring.
};



#endif
