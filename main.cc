#include <iostream>
using namespace std;

#include <cstdlib>
#include <time.h>
#include "Display.h"
#include "Control.h"

int random(int);

int main(){
  srand((unsigned)time(NULL));
  Control control;
  control.launch();
  return 0;
}


int random(int max)
{
	double r = ( (double)rand() / ((double)(RAND_MAX)+(double)(1)) ); 
	return (int)(r * max);
}
