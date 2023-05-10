#include <iostream>
using namespace std;

#include "QuestPlayer.h"
#include "Gollum.h"
#include "Display.h"
#include "Dragon.h"
#include "Enemy.h"

int random(int);

bool Gollum::hasRing = false;

//----------------------------------------------------------------------------------------------------
Gollum::Gollum(QuestPlayer* qp1, QuestPlayer* qp2): QuestPlayer("Golum",'G',4,10){
  int qpX,qpY;              
  arr[0] = qp1;
  arr[1] = qp2;
  evil = true;
  qp1->getCoords(qpX,qpY); //Gets the coords of the first hero to spawn Gollum on the same x.
  x = qpX;
  y = 0;
}
//----------------------------------------------------------------------------------------------------
bool Gollum::isGollum(){
  return evil;
}
//----------------------------------------------------------------------------------------------------
void Gollum::move(){
  if(dead){
    return;
  }

  if(hasRing){
    x = DISPLAY_MAX_X - 1;
    y = 2;
    return;
  }
  int randInt = random(100);  //Random number for probability.
  if(x < DISPLAY_MAX_X - 1){  //Move gollum if he is not on the rightmost collumn.
    ++x;
  }
  //Decides weather he will be evil half the time.
  if(randInt < 50){
    evil = true;
  }else{
    evil = false;
  }

  if(isGollum()){  //If gollum is calling the shots.
    int qp1Y, qp1X, qp2Y, qp2X, dist1, dist2;

    //Get the Distance of the Both heros.
    arr[0]->getCoords(qp1X,qp1Y);
    arr[1]->getCoords(qp2X,qp2Y);
    dist1 = y - qp1Y;
    dist2 = y - qp2Y;

    //Making sure that both distances are positive values.
    if(dist1 < 0)
      dist1 *= -1;
    if(dist2 < 0)
      dist2 *= -1;

    //Locate the closest player and move in their direction.
    if(dist1 < dist2){  //If first hero is closer move closer to that player.
      if(y < qp1Y){
	++y;
      }else if(y > qp1Y){
	--y;
      }
    }else{              //If second hero is closer or they are both the same distance.
      if(y < qp2Y){
	++y;
      }else if(y > qp2Y){
	--y;
      }
    }
  }else{                //If smegal is in controll. Be passive.
    int randInt = random(3);
    if(randInt == 0){
      if(y > 0)
	--y;
    }else if(randInt == 2){
      if(y < DISPLAY_MAX_Y - 1){
	++y;
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------
void Gollum::collide(QuestPlayer* otherPlayer){
  if(dead){
    return;
  }
  if(otherPlayer->dead){
    return;
  }else if(typeid(*otherPlayer) == typeid(Dragon)){
    health = 0;
  }else if(typeid(*otherPlayer) == typeid(Enemy)){
    health -= otherPlayer->getStrength();
  }
  if(health < 0){
    health = 0;
  }

}
//----------------------------------------------------------------------------------------------------
int Gollum::getStrength(){
  if(isGollum()){
    return 2;
  }else{
    return 0;
  }
}
//----------------------------------------------------------------------------------------------------
void Gollum::foundRing(){
  hasRing = true;
}
//----------------------------------------------------------------------------------------------------
bool Gollum::isWearingRing(){
  return hasRing;
}
//----------------------------------------------------------------------------------------------------
string Gollum::getName(){
  if(evil){
    return "Gollum";
  }else{
    return "Smegal";
  }
}
//----------------------------------------------------------------------------------------------------
