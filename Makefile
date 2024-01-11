all: build/Breakout

CC=$(CXX)

asteroid: src/Asteroid.cpp
	g++ -c src/Asteroid.cpp -o build/Asteroid.o

bullet: src/Bullet.cpp
	g++ -c src/Bullet.cpp -o build/Bullet.o

player: src/Player.cpp
	g++ -c src/Player.cpp -o build/Player.o

utils: src/Utils.cpp
	g++ -c src/Utils.cpp -o build/Utils.o

breakout:
	g++ -c src/Breakout.cpp -o build/Breakout.o

main:
	g++ -c src/Main.cpp -o build/Main.o

build/Breakout: asteroid bullet player utils breakout main
	g++ build/Asteroid.o build/Bullet.o build/Player.o build/Utils.o build/Breakout.o build/Main.o -o build/Breakout -lraylib -lm
