#include <iostream>
using namespace std;

#include <list>
#include <iterator>
#include <string>
#include "Control.h"
#include "QuestPlayer.h"
#include "Hero.h"
#include "Enemy.h"
#include "Dragon.h"
#include "View.h"
#include "Gollum.h"
#include "Ring.h"

int random(int);  //Forward declaration so compiler knows what random to use.
//----------------------------------------------------------------------------------------------------
Control::Control():game(true){
  ring = new Ring();
}
//----------------------------------------------------------------------------------------------------
Control::~Control(){
  list<QuestPlayer*>::iterator it;
  //Iterate through list of players and free them.
  for(it = playerList.begin(); it != playerList.end(); ++it){
    delete *it;
  }
  delete ring;
}
//----------------------------------------------------------------------------------------------------
void Control::launch(){
  QuestPlayer* winner;  //The Hero who has collected the emrald.
  string strEnd;        //String that contains the winner to be shown to the user.

  initPlayers();
  populate();
  int numLoops = 0;
  while(game){
    string gameStats[5];
    movePlayers();
    checkCollisions();
    setDead();
    populate();
    newOrc();
    fillGameStats(gameStats);
    view.printBoard(&display,gameStats);
    winner = checkGameState();
    //If the game has looped 10 times spawn Gollum.
    if(numLoops == 10){
      spawnGollum();
    }
    ++numLoops;
  }
  
  //Determine who has won the game to print the correct message.
  if(winner == NULL){
    strEnd = "Game Over. Both heros are dead.";
  }else{
    strEnd = winner->getName() + " has collected the Emerald!!";
  }
  view.printStr(strEnd);
  
}
//----------------------------------------------------------------------------------------------------
void Control::initPlayers(){
  Hero* timmy = new Hero(3,"Timmy",'T',3);
  Hero* harold = new Hero(5,"Harold",'H',1);
  Dragon* dragon = new Dragon(timmy,harold);
  playerList.push_front(dragon);
  playerList.push_front(timmy);
  playerList.push_front(harold);
}

//----------------------------------------------------------------------------------------------------
void Control::populate(){
  display.clrBoard();      //Clear the board to ready for reentering.
  
  //Loop through all the QuestPlayers and add the chars to the display.
  list<QuestPlayer*>::iterator it;
  for(it = playerList.begin(); it != playerList.end(); ++it){
    int playerX;
    int playerY;
    char dispChar;
    if((*it)->dead){       //If the hero or gollum is dead put up their cross.
      dispChar = '+';
    }else{
      dispChar = (*it)->getDispChar();
    }
    (*it)->getCoords(playerX,playerY);
    display.setCoord(playerX,playerY,dispChar);
  }
}
//----------------------------------------------------------------------------------------------------
void Control::movePlayers(){
  list<QuestPlayer*>::iterator it;
  for(it=playerList.begin();it != playerList.end();it++){
      (*it)->move();
  }
}
//----------------------------------------------------------------------------------------------------
void Control::checkCollisions(){

  //Loop thorugh all the players.
  list<QuestPlayer*>::iterator it;
  for(it=playerList.begin();it != playerList.end();it++){
    QuestPlayer* currPlayer = *it;            //The player that is currently checking for collisions.

    if(*ring == *currPlayer){
      if(ring->found == false){
	ring->found = true;
	currPlayer->foundRing();
      }
    }
    //Loop through all the players.
    list<QuestPlayer*>::iterator it2;
    for(it2=playerList.begin();it2 != playerList.end();it2++){
        
	QuestPlayer* loopPlayer = *it2;       //The player being checked for collisions with the current player.
	if(*it == *it2){                      //If both itterators are at the same spot.
	  continue;
        }else if(*currPlayer == *loopPlayer){ //If both the players have the same coords.
	  currPlayer->collide(loopPlayer);
	}
    }
  }
}
//----------------------------------------------------------------------------------------------------
void Control::setDead(){
  list<QuestPlayer*>::iterator it;
  for(it = playerList.begin();it != playerList.end(); it++){
    if((*it)->getHealth() <= 0){
      (*it)->dead = true;
      if(typeid(**it) == typeid(Enemy)){
	it = playerList.erase(it);
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------
QuestPlayer* Control::checkGameState(){
  int deadHeros = 0;  //The number of dead heros.

  //Loop through all the heros.
  list<QuestPlayer*>::iterator it;
  for(it = playerList.begin();it != playerList.end(); it++){
    int pX,pY;
    if(typeid(**it) == typeid(Hero)){                      //If the iterator is currently on a hero.
      if((*it)->getHealth() <= 0){
	deadHeros++;
      }else{                          
	(*it)->getCoords(pX,pY);
	if(pX == (DISPLAY_MAX_X - 1) && pY > 0 && pY < 4){ //If the heros reach the cave.
	  game = false;
	  return *it;
	}
      }
    }else if(typeid(**it) == typeid(Gollum) && (*it)->isWearingRing()){
      (*it)->getCoords(pX,pY);
      if(pX == (DISPLAY_MAX_X - 1) && pY > 0 && pY < 4){
	game = false;
	return *it;
      }
    }
  }
  if(deadHeros >= 2){                                      //If both heros are dead the game is over.
    game = false;
  }
  return NULL;
}
//----------------------------------------------------------------------------------------------------
void Control::newOrc(){
  int randInt = random(100);     //Random number variable used to randomly select numbers.
  string name;                   //name of the new Orc.
  char disChar;                  //display char of the new Orc.
  int strength;                  //The strength of the new Orc.
  
  if(randInt > 60){              //Return 30% of the time.
    return;
  }

  randInt = random(3);           //Random number between 0 and 2 to pick what Orc varient to choose.
  
  if(randInt == 0){         //Dorc is created.
    name = "Dorc";
    disChar = 'd';
    randInt = random(3);
    strength = randInt + 6;
  }else if(randInt == 1){   //Porc is created.
    name = "Porc";
    disChar = 'p';
    randInt = random(2);
    strength = randInt + 4;
  }else if(randInt == 2){   //Borc is created.
    name = "Borc";
    disChar = 'b';
    randInt = random(4);
    strength = randInt + 8;
  }

  Enemy* newEn = new Enemy(name,disChar,strength); //Dynamically create the new Orc.
  playerList.push_front(newEn);
}
//----------------------------------------------------------------------------------------------------
void Control::spawnGollum(){
  QuestPlayer* qp1 = NULL;             //The first hero that Gollum can see.
  QuestPlayer* qp2 = NULL;             //The second hero that Gollum can see.

  //Loop through the player list.
  list<QuestPlayer*>::iterator it;
  for(it = playerList.begin(); it != playerList.end(); ++it){
    if(typeid(**it) == typeid(Hero)){  //If the iterator if over a hero put it in either qp1 or qp2
      if(qp1 == NULL){
	qp1 = *it;
      }else{
	qp2 = *it;
      }
    }
  }

  Gollum* gol = new Gollum(qp1,qp2);
  playerList.push_back(gol);
}
//----------------------------------------------------------------------------------------------------
void Control::fillGameStats(string arr[5]){
  int arrIndex = 0;  //The index of the next empty spot in the array.
  int qpX, qpY, h;   //Used for go get various coordinates.
  
  list<QuestPlayer*>::iterator it;
  for(it = playerList.begin(); it != playerList.end(); ++it){
    string arrString = "";
    //Adds the heros stats to the arr of stats.
    if(typeid(**it) == typeid(Hero)){
      (*it)->getCoords(qpX,qpY);
      arrString += (*it)->getName() + " is at " + to_string(qpX) + "," + to_string(qpY) + " with " + to_string((*it)->getHealth()) + "/15 health";
      arr[arrIndex] = arrString;
      ++arrIndex;
    }
    //Adds gollum to the array of stats.
    if(typeid(**it) == typeid(Gollum)){
      (*it)->getCoords(qpX,qpY);
      arrString += (*it)->getName() + " is at " + to_string(qpX) + "," + to_string(qpY) + " with " + to_string((*it)->getHealth()) + "/10 health";
      arr[arrIndex] = arrString;
      ++arrIndex;
    }
  }
  //Adds ring to the array of stats.
  if(ring->found){
    ring->getCoords(qpX,qpY);
    if(ring->getType().compare("invisibility") == 0){
      arr[arrIndex] = "Gollum is using the ring of invisibility he found at " + to_string(qpX) + "," + to_string(qpY);
    }else if(ring->getType().compare("invincibility") == 0){
      arr[arrIndex] = "The Heros are using the ring of invincibility they found at " + to_string(qpX) + "," + to_string(qpY);
    }else if(ring->getType().compare("visibility") == 0){
      arr[arrIndex] = "The Dragon is using the ring of visibility he found at " + to_string(qpX) + "," + to_string(qpY);
    }else if(ring->getType().compare("strength") == 0){
      arr[arrIndex] = "The Enemies are using the ring of strength they found at " + to_string(qpX) + "," + to_string(qpY);
    }
  }else{
    arr[arrIndex] = "No one is currently in control of the ring.";
  }
  
}
