#include <iostream>
#include <sstream>
#include "GameObject.hpp"
#include "Position.hpp"
#include "ScriptEngine.hpp"
using namespace std;

int main() {
	GameObject player1("Hero", 100, 0.0f, 0.0f, 1);
	GameObject player2("Hero", 100, 0.0f, 0.0f, 1);
	Position posCheck(0.0f, 0.0f);

	if (posCheck == player1)
		std::cout << "Position matches player1's position." << std::endl;
	else
		std::cout << "Position does NOT matches player1's position." << std::endl;

	ScriptEngine::teleport(player1, 10.0f, 5.0f);
	ScriptEngine::heal(player1, 25);
	ScriptEngine::advanceAnimation(player1);

	ScriptEngine::teleport(player2, 5.0f, 7.5f);
	ScriptEngine::heal(player2, 20);
	ScriptEngine::advanceAnimation(player2);

	
	std::cout << "Stringified player1: " << stringify(player1) << std::endl;
	std::cout << player1 << std::endl;


	return 0;
}
