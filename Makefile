all: Asteroids

Assets.o: src/Assets/Assets.cpp src/Assets/Assets.hpp src/Utils/Utils.hpp src/Entity/Entity.hpp
	g++ -c src/Assets/Assets.cpp -o build/Assets.o

Asteroid.o: src/Asteroid/Asteroid.cpp src/Asteroid/Asteroid.hpp src/Config/Config.hpp src/Utils/Utils.hpp src/Entity/Entity.hpp
	g++ -c src/Asteroid/Asteroid.cpp -o build/Asteroid.o

Asteroids.o: src/Asteroids/Asteroids.cpp src/Asteroids/Asteroids.hpp src/Assets/Assets.hpp src/Asteroid/Asteroid.hpp src/Bullet/Bullet.hpp src/Player/Player.hpp src/Utils/Utils.hpp
	g++ -c src/Asteroids/Asteroids.cpp -o build/Asteroids.o

Bullet.o: src/Bullet/Bullet.cpp src/Bullet/Bullet.hpp src/Entity/Entity.hpp src/Config/Config.hpp
	g++ -c src/Bullet/Bullet.cpp -o build/Bullet.o

Player.o: src/Player/Player.cpp src/Player/Player.hpp src/Config/Config.hpp src/Entity/Entity.hpp
	g++ -c src/Player/Player.cpp -o build/Player.o

Utils.o: src/Utils/Utils.cpp src/Utils/Utils.hpp
	g++ -c src/Utils/Utils.cpp -o build/Utils.o

Main.o: src/Main.cpp src/Config/Config.hpp src/Asteroids/Asteroids.hpp
	g++ -c src/Main.cpp -o build/Main.o

Asteroids: Assets.o Asteroid.o Asteroids.o Bullet.o Player.o Utils.o Main.o
	g++ -g build/Utils.o build/Bullet.o build/Player.o build/Asteroid.o build/Assets.o build/Asteroids.o build/Main.o -o build/Asteroids -lraylib

