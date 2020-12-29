#ifndef QUESTPLAYER_H
#define QUESTPLAYER_H

//Purpose: Be a base class for all the kinds of QuestPlayers.
class QuestPlayer{
 public:
  QuestPlayer(string,char,int,int);      //ctro with string = name, char = display char, int = strength, int = health. 
  virtual string getName();              //Gets the name of the QuestPlayer.
  virtual int getStrength();             //Gets the strength of the Questplayer.
  void getCoords(int&,int&);             //Gets the coords using the params. int = x, int = y.
  char getDispChar();                    //Gets the display char of the QuestPlayer.
  virtual void move() = 0;               //Moves the Questplayer.
  virtual void collide(QuestPlayer*) = 0;//Handles the collision of two QuestPlayers.
  virtual void foundRing() = 0;          //Returns true if they found the ring.
  virtual bool isWearingRing() = 0;      //Returns true if they are weather the ring.
  int getHealth();                       //Gets the health of the QuestHero.
  bool operator==(QuestPlayer&);         //returns true if two questplayers have the same coordinates.
  bool dead;                             //is true if the player is dead.
 protected:
  int x;                                 //Is the x coord for the QuestPlayer.
  int y;                                 //Is the y coord for the QuestPlayer.
  int health;                            //The QuestPlayers health.
  int strength;                          //The QuestPlayers strength.
 private:
  char dispChar;                         //The QuestPlayers display character.
  string name;                           //The QuestPlayers Name.

};




#endif

