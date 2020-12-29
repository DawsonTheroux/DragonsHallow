#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
using namespace std;

#define DISPLAY_MAX_X 25
#define DISPLAY_MAX_Y 5

//Purpose: Store a datatype in a 2D dynamically alocated array.
template <class T>
class Display{
 public:
  Display();                 //ctor
  ~Display();                //dtor
  void clrBoard();           //Sets the whole board to NULL.
  void setCoord(int,int,T);  //Sets the coordiante on the board to the last param.
  T getData(int,int);        //Gets the data at a certain coordinate.
 private:
  T **arr;                   //The Arr where all the data is stored.

};
//----------------------------------------------------------------------------------------------------
template <class T>
Display<T>::Display(){
  arr = new T*[DISPLAY_MAX_X];       //Create a dynamically alocated array.
  for(int i=0;i<DISPLAY_MAX_X;++i){
    arr[i] = new T[DISPLAY_MAX_Y];   //Each index now has a dynamically alocated array.
  }
}
//----------------------------------------------------------------------------------------------------
template <class T>
Display<T>::~Display(){
  for(int i=0;i<DISPLAY_MAX_X;i++){
    delete [] arr[i];
  }
  delete [] arr;
}
//----------------------------------------------------------------------------------------------------
template <class T>
void Display<T>::setCoord(int x, int y, T newItem){
  arr[x][y] = newItem;
  return;
}
//----------------------------------------------------------------------------------------------------
template <class T>
void Display<T>::clrBoard(){
  for(int i=0;i<DISPLAY_MAX_X;++i){
    for(int j=0;j<DISPLAY_MAX_Y;++j){
      arr[i][j] = 0;
    }
  }
}
//----------------------------------------------------------------------------------------------------
template <class T>
T Display<T>::getData(int x,int y){
  return arr[x][y];
}
//----------------------------------------------------------------------------------------------------

#endif
