#ifndef GOLLUM_H
#define GOLLUM_H

#include "QuestPlayer.h"

//Purpose: -Be an enemy/passive Questplayer to the heros.
//         -If state is evil, will target the closest hero.
//               -Passive otherwise.
class Gollum: public QuestPlayer{
  public:
  Gollum(QuestPlayer*, QuestPlayer*);  //ctor
  virtual void move();                 //Moves gollum either towards the heros are randomly.
  virtual void collide(QuestPlayer*);  //Handles the collisions with other heros and enemies.
  virtual int getStrength();           //gets the strength depending on his state.
  virtual void foundRing();            //Gollum now has the ring.
  virtual bool isWearingRing();        //Returns true if he has collected the ring.
  virtual string getName();            //Gets the name of whose in control.
  bool isGollum();
  
  private:
  QuestPlayer* arr[2];                 //The array of heros in the game so that gollum can know their locations.
  bool evil;                           //Bool to determine if gollum is leading the way or smeagle.
  static bool hasRing;                 //True if he has collected the ring.
};






#endif
