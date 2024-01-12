all: build/Asteroids

CC=$(CXX)

asteroid: src/Asteroid.cpp
	g++ -c src/Asteroid.cpp -o build/Asteroid.o

bullet: src/Bullet.cpp
	g++ -c src/Bullet.cpp -o build/Bullet.o

player: src/Player.cpp
	g++ -c src/Player.cpp -o build/Player.o

utils: src/Utils.cpp
	g++ -c src/Utils.cpp -o build/Utils.o

asteroids:
	g++ -c src/Asteroids.cpp -o build/Asteroids.o

main:
	g++ -c src/Main.cpp -o build/Main.o

build/Asteroids: asteroid bullet player utils asteroids main
	g++ build/Asteroid.o build/Bullet.o build/Player.o build/Utils.o build/Asteroids.o build/Main.o -o build/Asteroids -lraylib -lm
