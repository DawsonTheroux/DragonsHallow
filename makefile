DragonsHallow:  main.o View.o Ring.o Control.o QuestPlayer.o Gollum.o Hero.o Enemy.o Dragon.o Display.h
	g++ -o DragonsHallow View.o QuestPlayer.o Gollum.o main.o Control.o Ring.o Hero.o Enemy.o Dragon.o

main.o: main.cc Control.cc QuestPlayer.cc random.cc
	g++ -c main.cc

View.o: View.cc View.h
	g++ -c View.cc

Ring.o: Ring.cc Ring.h QuestPlayer.h
	g++ -c Ring.cc

Control.o: Control.cc Control.h 
	g++ -c Control.cc

QuestPlayer.o: QuestPlayer.cc QuestPlayer.h Hero.h Enemy.h Dragon.h
	g++ -c QuestPlayer.cc

Gollum.o: Gollum.cc Gollum.h QuestPlayer.h
	g++ -c Gollum.cc

Hero.o: Hero.cc Hero.h
	g++ -c Hero.cc

Enemy.o: Enemy.cc Enemy.h
	g++ -c Enemy.cc

Dragon.o: Dragon.cc Dragon.h Enemy.cc Enemy.h
	g++ -c Dragon.cc

clean:
	rm -f *.o
