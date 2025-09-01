#include "ScriptEngine.hpp"
#include <iostream>
using namespace std;

void ScriptEngine::teleport(GameObject& obj, float newX, float newY)
{
	obj.x = newX;
	obj.y = newY;
	std::cout
	<< "[ScriptEngine] Teleported " << obj.name
	<< " to (" << newX << ", " << newY << ")"
	<< std::endl;
}

void ScriptEngine::heal(GameObject& obj, int amount)
{
	obj.health += amount;
	std::cout
	<< "[ScriptEngine] Healed by " << amount
	<< "Health now: " << obj.health
	<< std::endl;
}

void ScriptEngine::advanceAnimation(GameObject& obj)
{
	obj.animationFrame++;
	std::cout
	<< "[ScriptEngine] Animation frame advanced to " << obj.animationFrame
	<< std::endl;
}
