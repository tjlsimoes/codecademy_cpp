#include "GameObject.hpp"
#include <iostream>
using namespace std;


GameObject::GameObject(std::string nme, int hlth, float xpos, float ypos, int frame) : name(nme), health(hlth), x(xpos), y(ypos), animationFrame(frame)
{}

void	GameObject::move(float dx, float dy)
{
	x += dx;
	y += dy;
}

void	GameObject::takeDamage(int amount)
{
	if (health >= amount)
		health -= health;
	else
		health = 0;
	std::cout
	<< name
	<< " took "
	<< amount
	<< " damage. Health now: "
	<< health
	<< std::endl;
}


ostream& operator<<(ostream& out, const GameObject& obj) {
  out << "GameObject[name=" << obj.name
      << ", health=" << obj.health
      << ", pos=(" << obj.x << "," << obj.y << ")"
      << ", animationFrame=" << obj.animationFrame << "]";
  return out;
}

bool	operator==(const GameObject &a, const GameObject &b)
{
	if (a.x == b.x && a.y == b.y)
		return true;
	return false;
}

std::string	stringify(const GameObject & obj)
{
	return (obj.name + "#" + obj.name + "#"
			+ std::to_string(obj.x) + "#"
			+ std::to_string(obj.y) + "#"
			+ std::to_string(obj.animationFrame));
}
bool		operator==(const Position &pos, const GameObject &obj)
{
	if (pos.x == obj.x && pos.y == obj.y)
		return true;
	return false;
}
