#include <iostream>
using namespace std;

#include "QuestPlayer.h"
#include "Ring.h"
#include "Display.h"
#include "Dragon.h"
#include "Gollum.h"
#include "Hero.h"
#include "Enemy.h"

int random(int);
//----------------------------------------------------------------------------------------------------
Ring::Ring(){
  int randInt = random(4);   //randomly chooses between the 4 kinds of rings.
  found = false;
  if(randInt == 0){          //Gollums ring of invisibility is selected.
    type = "invisibility";
    x = random(DISPLAY_MAX_X - 15) + 14;  //Only spawns in the last few collumns.
    y = random(DISPLAY_MAX_Y);
  }else if(randInt == 1){    //The Heros ring of invincibility is selected.
    type = "invincibility";
    x = random(DISPLAY_MAX_X - 5) + 4;
    y = random(DISPLAY_MAX_Y);
  }else if(randInt == 2){    //The Dragons Ring of visibility is selected.
    type = "visibility";
    x = DISPLAY_MAX_X - 1;
    y = random(DISPLAY_MAX_Y);
  }else if(randInt == 3){    //The Enemies ring of strength is selected.
    type = "strength";
    x = random((int)(DISPLAY_MAX_X / 2));
    y = random(DISPLAY_MAX_Y);
  }
}
//----------------------------------------------------------------------------------------------------
string Ring::getType(){
    return type;
}
//----------------------------------------------------------------------------------------------------
bool Ring::operator==(QuestPlayer& qp){
  int qpX,qpY;
  qp.getCoords(qpX,qpY);
  if(x == qpX && y == qpY){
    if(typeid(qp) == typeid(Gollum) && type.compare("invisibility") == 0){
      return true;
    }else if(typeid(qp) == typeid(Hero) && type.compare("invincibility") == 0){
      return true;
    }else if(typeid(qp) == typeid(Dragon) && type.compare("visibility") == 0){
      return true;
    }else if(typeid(qp) == typeid(Enemy) && type.compare("strength") == 0){
      return true;
    }
  }
  return false;
}
//----------------------------------------------------------------------------------------------------
void Ring::getCoords(int& refX, int& refY){
  refX = x;
  refY = y;
}
//----------------------------------------------------------------------------------------------------
