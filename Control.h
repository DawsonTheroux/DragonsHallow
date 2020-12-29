#ifndef CONTROL_H
#define CONTROL_H

#include <list>
#include "QuestPlayer.h"
#include "Display.h"
#include "View.h"
#include "Hero.h"
#include "Ring.h"

//Purpose: Handle the control flow of the program.
class Control{
  public:						
  Control();                       //ctor
  ~Control();                      //dtor
  void launch();                   //Controls the general flow of the program.
 
  private:
  Display<char> display = Display<char>(); //The display of the game.
  list <QuestPlayer*> playerList;          //The list of Questplayers in the game.
  View view;                               //The view of the game to output to users.
  bool game;                               //bool to determine if the game should be running.
  Ring* ring;                              //The one special ring in the game.
  void initPlayers();                      //Initializes all the begining players. 
  void populate();                         //Populates the display with the players.
  void movePlayers();                      //Moves all the players in the game.
  QuestPlayer* checkGameState();           //Checks the gamestate to see if it has ended.
  void checkCollisions();                  //Checks for colliding Quest Players.
  void setDead();                          //Removes dead orcs and sets heros to dead.
  void newOrc();                           //60% chance of spawning an orc.
  void spawnGollum();                      //Spawns gollum.
  void fillGameStats(string gameStats[5]); //Fills the gameStats array with various stats.
};

#endif
