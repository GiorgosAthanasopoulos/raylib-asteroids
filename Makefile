all: Asteroids-Debug

DEBUG_FLAGS = -DDEBUG -g -Wall -Wextra -pedantic -std=c++11
RELEASE_FLAGS = -DNDEBUG -O3 -s -Wall -Wextra -pedantic -std=c++11  

Assets.o-Debug: src/Assets/Assets.cpp src/Assets/Assets.hpp src/Utils/Utils.hpp src/Entity/Entity.hpp
	g++ $(DEBUG_FLAGS) -c src/Assets/Assets.cpp -o build/Assets.o

Assets.o-Release: src/Assets/Assets.cpp src/Assets/Assets.hpp src/Utils/Utils.hpp src/Entity/Entity.hpp
	g++ $(RELEASE_FLAGS) -c src/Assets/Assets.cpp -o build/Assets.o

Asteroid.o-Debug: src/Asteroid/Asteroid.cpp src/Asteroid/Asteroid.hpp src/Config/Config.hpp src/Utils/Utils.hpp src/Entity/Entity.hpp
	g++ $(DEBUG_FLAGS) -c src/Asteroid/Asteroid.cpp -o build/Asteroid.o

Asteroid.o-Release: src/Asteroid/Asteroid.cpp src/Asteroid/Asteroid.hpp src/Config/Config.hpp src/Utils/Utils.hpp src/Entity/Entity.hpp
	g++ $(RELEASE_FLAGS) -c src/Asteroid/Asteroid.cpp -o build/Asteroid.o

Asteroids.o-Debug: src/Asteroids/Asteroids.cpp src/Asteroids/Asteroids.hpp src/Assets/Assets.hpp src/Asteroid/Asteroid.hpp src/Bullet/Bullet.hpp src/Player/Player.hpp src/Utils/Utils.hpp
	g++ $(DEBUG_FLAGS) -c src/Asteroids/Asteroids.cpp -o build/Asteroids.o

Asteroids.o-Release: src/Asteroids/Asteroids.cpp src/Asteroids/Asteroids.hpp src/Assets/Assets.hpp src/Asteroid/Asteroid.hpp src/Bullet/Bullet.hpp src/Player/Player.hpp src/Utils/Utils.hpp
	g++ $(RELEASE_FLAGS) -c src/Asteroids/Asteroids.cpp -o build/Asteroids.o

Bullet.o-Debug: src/Bullet/Bullet.cpp src/Bullet/Bullet.hpp src/Entity/Entity.hpp src/Config/Config.hpp
	g++ $(DEBUG_FLAGS) -c src/Bullet/Bullet.cpp -o build/Bullet.o

Bullet.o-Release: src/Bullet/Bullet.cpp src/Bullet/Bullet.hpp src/Entity/Entity.hpp src/Config/Config.hpp
	g++ $(RELEASE_FLAGS) -c src/Bullet/Bullet.cpp -o build/Bullet.o

Player.o-Debug: src/Player/Player.cpp src/Player/Player.hpp src/Config/Config.hpp src/Entity/Entity.hpp
	g++ $(DEBUG_FLAGS) -c src/Player/Player.cpp -o build/Player.o

Player.o-Release: src/Player/Player.cpp src/Player/Player.hpp src/Config/Config.hpp src/Entity/Entity.hpp
	g++ $(RELEASE_FLAGS) -c src/Player/Player.cpp -o build/Player.o

Utils.o-Debug: src/Utils/Utils.cpp src/Utils/Utils.hpp
	g++ $(DEBUG_FLAGS) -c src/Utils/Utils.cpp -o build/Utils.o

Utils.o-Release: src/Utils/Utils.cpp src/Utils/Utils.hpp
	g++ $(RELEASE_FLAGS) -c src/Utils/Utils.cpp -o build/Utils.o

Main.o-Debug: src/Main.cpp src/Config/Config.hpp src/Asteroids/Asteroids.hpp
	g++ $(DEBUG_FLAGS) -c src/Main.cpp -o build/Main.o

Main.o-Release: src/Main.cpp src/Config/Config.hpp src/Asteroids/Asteroids.hpp
	g++ $(RELEASE_FLAGS) -c src/Main.cpp -o build/Main.o

Asteroids-Debug: Assets.o-Debug Asteroid.o-Debug Asteroids.o-Debug Bullet.o-Debug Player.o-Debug Utils.o-Debug Main.o-Debug
	g++ $(DEBUG_FLAGS) build/Utils.o build/Bullet.o build/Player.o build/Asteroid.o build/Assets.o build/Asteroids.o build/Main.o -o build/Asteroids -lraylib

Asteroids-Release: Assets.o-Release Asteroid.o-Release Asteroids.o-Release Bullet.o-Release Player.o-Release Utils.o-Release Main.o-Release
	g++ $(RELEASE_FLAGS) build/Utils.o build/Bullet.o build/Player.o build/Asteroid.o build/Assets.o build/Asteroids.o build/Main.o -o build/Asteroids -lraylib

TestUtils: test/Utils.cpp Utils.o-Debug
	g++ $(DEBUG_FLAGS) -c test/Utils.cpp -o build/test/Utils.o
	g++ $(DEBUG_FLAGS) build/Utils.o  build/test/Utils.o -o build/test/Utils -lraylib

run-tests: TestUtils
	./build/test/Utils

run-debug: Asteroids-Debug
	./build/Asteroids

run-release: Asteroids-Release
	./build/Asteroids
