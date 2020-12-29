#include <iostream>
using namespace std;

#include "Dragon.h"

bool Dragon::hasRing = false;
//----------------------------------------------------------------------------------------------------
Dragon::Dragon(QuestPlayer* qp1, QuestPlayer* qp2):Enemy("Dragon",'D',100){
  arr[0] = qp1;
  arr[1] = qp2;
}
//----------------------------------------------------------------------------------------------------
void Dragon::move(){

  if(hasRing){
    int q1x,q1y,q2x,q2y,dist1,dist2;
    
    //Getting the distance of both heros.
    arr[0]->getCoords(q1x,q1y);
    arr[1]->getCoords(q2x,q2y);
    dist1 = y - q1y;
    dist2 = y - q2y;
    //Setting both distances to positive values
    if(dist1 < 0)
      dist1 *= -1;
    if(dist2 < 0)
      dist2 *= -1;
    //Moving towards the closest hero.
    if(dist1 < dist2){
      if(q1y < y){
	--y;
      }else{
	++y;
      }
    }else{
      if(q2y < y){
	--y;
      }else{
	++y;
      }
    }
    return;
  }

  if(movingUp){ //If the dragon is moving up.
    if(y == 0){ //If it reaches the top change directions.
      y++;
      movingUp = false;
    }else{      //If the dragon is moving down.
      --y;
    }
  }else{
    if(y==4){   //If it reaches the bottom change directions.
      y--;
      movingUp = true;
    }else{
      ++y;
    }
  }
}
//----------------------------------------------------------------------------------------------------
void Dragon::foundRing(){
  hasRing = true;
}
//----------------------------------------------------------------------------------------------------
bool Dragon::isWearingRing(){
  return hasRing;
}
