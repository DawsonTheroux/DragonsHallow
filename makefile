#CXX = g++
CXX = em++
DragonsHallow: main.o View.o Ring.o Control.o QuestPlayer.o Gollum.o Hero.o Enemy.o Dragon.o Display.h
	$(CXX) -o DragonsHallow.html  View.o QuestPlayer.o Gollum.o main.o Control.o Ring.o Hero.o Enemy.o Dragon.o

#DragonsHallow:  main.o View.o Ring.o Control.o QuestPlayer.o Gollum.o Hero.o Enemy.o Dragon.o Display.h
#	$(CXX) -o DragonsHallow View.o QuestPlayer.o Gollum.o main.o Control.o Ring.o Hero.o Enemy.o Dragon.o

main.o: main.cc Control.cc QuestPlayer.cc random.cc
	$(CXX) -c main.cc

View.o: View.cc View.h
	$(CXX) -c View.cc

Ring.o: Ring.cc Ring.h QuestPlayer.h
	$(CXX) -c Ring.cc

Control.o: Control.cc Control.h 
	$(CXX) -c Control.cc

QuestPlayer.o: QuestPlayer.cc QuestPlayer.h Hero.h Enemy.h Dragon.h
	$(CXX) -c QuestPlayer.cc

Gollum.o: Gollum.cc Gollum.h QuestPlayer.h
	$(CXX) -c Gollum.cc

Hero.o: Hero.cc Hero.h
	$(CXX) -c Hero.cc

Enemy.o: Enemy.cc Enemy.h
	$(CXX) -c Enemy.cc

Dragon.o: Dragon.cc Dragon.h Enemy.cc Enemy.h
	$(CXX) -c Dragon.cc

clean:
	rm -f *.o

