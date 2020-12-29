#include <iostream>
using namespace std;

#include "View.h"
#include "Display.h"


void View::printBoard(Display<char> *disp, string gameStats[5]){
  cout << endl;
  cout << "|";
  for(int i=0;i<DISPLAY_MAX_X;++i){
    cout << "-";
  }
  cout << "|" << endl << "|";
  
  for(int i = 0; i<DISPLAY_MAX_Y; ++i){
    for(int j=0; j<DISPLAY_MAX_X; ++j){
      if(disp->getData(j,i) == 0){
	cout << " ";
      }else{
	cout << disp->getData(j,i);
      }
    }
    if(i >= 1 && i <=3){
      cout << "=" ;
    }else{
      cout << "| ";
    }
    if(i == 2){
      cout << "*";
    }
    if(i < 1){
      cout << "  Game Statistics:";
    }else{
      cout << "   " <<  gameStats[i - 1];
    }
    cout << endl;
    cout << "|";
  }
  for(int i=0;i<DISPLAY_MAX_X;++i){
    cout << "-";
  }
  cout << "|" << endl;
}

void View::printStr(string s){
  cout << s << endl;
}
