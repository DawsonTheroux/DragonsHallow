#include<iostream>
using namespace std;

#include "QuestPlayer.h"
#include "string.h"

QuestPlayer::QuestPlayer(string n, char d,int s,int h): dead(false), name(n), dispChar(d), strength(s), health(h){
}

string QuestPlayer::getName(){
  return name;
}

char QuestPlayer::getDispChar(){
  return dispChar;
}

int QuestPlayer::getStrength(){
  return strength;
}


void QuestPlayer::getCoords(int& playerx,int& playery){
  playerx = x;
  playery = y;
}

bool QuestPlayer::operator==(QuestPlayer& qp){
  if(x == qp.x && y == qp.y){
    return true;
  }else{
    return false;
  }
}

int QuestPlayer::getHealth(){
  return health;
}
