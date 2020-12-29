#include<iostream>
using namespace std;

#include "QuestPlayer.h"
#include "Display.h"
#include "Enemy.h"
#include "Hero.h"

int random(int);

bool Enemy::hasRing = false;
//----------------------------------------------------------------------------------------------------
Enemy::Enemy(string n, char dc, int s):QuestPlayer(n,dc,s,5){
  x = 24;
  y = random(5);
}
//----------------------------------------------------------------------------------------------------
void Enemy::move(){
 int randInt = random(3);  //random number to determine direction of movement.
  
 if(dead){
    return;
 }
 if(x > 0){               
    --x;
 }else{           //If the enemy reaches the left side of the display they are dead.
    dead = true;
    health = 0;
    return;
 }
 if(randInt == 0){
   if(y>0){
     --y;
   }
 }else if(randInt == 2){
   if(y < (DISPLAY_MAX_Y - 1)){
     ++y;
   }
 }
}
//----------------------------------------------------------------------------------------------------
void Enemy::collide(QuestPlayer* otherPlayer){
  if(dead){                                //If this is dead dont collide.
    return;
  }
  if(typeid(otherPlayer) == typeid(Hero)){ // If collides with hero.
    health -= otherPlayer->getStrength();
  }
}
//----------------------------------------------------------------------------------------------------
void Enemy::foundRing(){
  hasRing = true;
  strength *= 2;
}
//----------------------------------------------------------------------------------------------------
int Enemy::getStrength(){
  if(hasRing){
    return strength * 2;
  }else{
    return strength;
  }
}
//----------------------------------------------------------------------------------------------------
bool Enemy::isWearingRing(){
  return hasRing;
}
