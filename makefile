battle: main.o Tournament.o Lineup.o Losers.o Game.o Creature.o Barbarian.o BlueMen.o HarryPotter.o Medusa.o Vampire.o
	g++ main.o Tournament.o Lineup.o Losers.o Game.o Creature.o Barbarian.o BlueMen.o HarryPotter.o Medusa.o Vampire.o -o game

main.o: main.cpp Tournament.hpp Lineup.hpp Losers.hpp Game.hpp Creature.hpp Barbarian.hpp BlueMen.hpp HarryPotter.hpp Medusa.hpp Vampire.hpp
	g++ -c main.cpp

Tournament.o: Tournament.cpp Tournament.hpp Lineup.hpp Losers.hpp Game.hpp Creature.hpp Barbarian.hpp BlueMen.hpp HarryPotter.hpp Medusa.hpp Vampire.hpp
	g++ -c Tournament.cpp

Lineup.o: Lineup.cpp Lineup.hpp Losers.hpp Game.hpp Creature.hpp Barbarian.hpp BlueMen.hpp HarryPotter.hpp Medusa.hpp Vampire.hpp
	g++ -c Lineup.cpp

Losers.o: Losers.cpp Losers.hpp Lineup.hpp Game.hpp Creature.hpp Barbarian.hpp BlueMen.hpp HarryPotter.hpp Medusa.hpp Vampire.hpp
	g++ -c Losers.cpp

Game.o: Game.cpp Game.hpp Lineup.hpp Losers.hpp Creature.hpp Barbarian.hpp BlueMen.hpp HarryPotter.hpp Medusa.hpp Vampire.hpp
	g++ -c Game.cpp

Creature.o: Creature.cpp Creature.hpp
	g++ -c Creature.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp Creature.hpp
	g++ -c Barbarian.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp Creature.hpp
	g++ -c BlueMen.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp Creature.hpp
	g++ -c HarryPotter.cpp

Medusa.o: Medusa.cpp Medusa.hpp Creature.hpp
	g++ -c Medusa.cpp

Vampire.o: Vampire.cpp Vampire.hpp Creature.hpp
	g++ -c Vampire.cpp

clean:
	rm *.o game
