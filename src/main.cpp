#include <iostream>
#include "Player.h"

int main(int argc, char *argv[]) {
	std::cout << "Hello Easy C++ project!" << std::endl;
	Player* a = new Player("Mura");
	std::cout << a->toString();
	delete a;
}