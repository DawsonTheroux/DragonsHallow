#include <iostream>
using namespace std;

#include "Hero.h"
#include "Display.h"
#include "Dragon.h"
#include "Enemy.h"
#include "QuestPlayer.h"
#include "Gollum.h"

int random(int);  //Declare which random to use.

bool Hero::hasRing = false;
//----------------------------------------------------------------------------------------------------
Hero::Hero(int a, string n, char dn, int s): QuestPlayer(n,dn,s,15), armour(a){
  x = 0;
  y  = random(5);
}
//----------------------------------------------------------------------------------------------------
void Hero::move(){
  int randInt = random(3);       //Random variable to choose movement options.
  if(dead){
    return;
  }   
  if(x < DISPLAY_MAX_X - 1){     //If the player is not at the end of the display.
    ++x;
  }
  if(randInt == 0){
    if(y>0){                     //If the player is not in the top row.
      --y;
    }
  }else if(randInt == 2){
    if(y < (DISPLAY_MAX_Y - 1)){ //If the player is not in the bottom row.
      ++y;
    }
  }
}
//----------------------------------------------------------------------------------------------------
void Hero::collide(QuestPlayer* otherPlayer){
  if(dead || (hasRing && typeid(*otherPlayer) != typeid(Dragon))){ //Dont take damage if wearing the ring.
    return;
  }
  if(otherPlayer->dead){
    return;
  }else if(typeid(*otherPlayer) == typeid(Dragon)){
    health = 0;
  }else if(typeid(*otherPlayer) == typeid(Enemy)){
    health -= otherPlayer->getStrength() - armour;
  }else if(typeid(*otherPlayer) == typeid(Gollum)){
    health -= otherPlayer->getStrength();
  }
  if(health < 0){
    health = 0;
  }
}
//----------------------------------------------------------------------------------------------------
void Hero::foundRing(){
  hasRing = true;
}
//----------------------------------------------------------------------------------------------------
bool Hero::isWearingRing(){
  return hasRing;
}
