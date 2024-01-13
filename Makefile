all: build

assets: src/Assets/Assets.cpp
	g++ -c src/Assets/Assets.cpp -o build/Assets.o

asteroid: src/Asteroid/Asteroid.cpp
	g++ -c src/Asteroid/Asteroid.cpp -o build/Asteroid.o

asteroids: src/Asteroids/Asteroids.cpp
	g++ -c src/Asteroids/Asteroids.cpp -o build/Asteroids.o

bullet: src/Bullet/Bullet.cpp
	g++ -c src/Bullet/Bullet.cpp -o build/Bullet.o

player: src/Player/Player.cpp
	g++ -c src/Player/Player.cpp -o build/Player.o

utils: src/Utils/Utils.cpp
	g++ -c src/Utils/Utils.cpp -o build/Utils.o

main: src/Main.cpp
	g++ -c src/Main.cpp -o build/Main.o

build: assets asteroid asteroids bullet player utils main
	g++ build/Utils.o build/Bullet.o build/Player.o build/Asteroid.o build/Assets.o build/Asteroids.o build/Main.o -o build/Asteroids -lraylib 

