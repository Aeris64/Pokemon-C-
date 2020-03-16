#include <iostream>
#include "Player.h"

int main(int argc, char *argv[]) {
	std::cout << "Hello Easy C++ project!" << std::endl;
	Player* a = new Player(1, "Mura");
	std::cout << a->toString() << std::endl;
	int32_t myId = a->getId();
	std::cout << myId;
	delete a;
}