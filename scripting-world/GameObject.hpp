#pragma once
#include <string>
#include "ScriptEngine.hpp"
#include "Position.hpp"
using namespace std;

class GameObject
{
	private:
		std::string	name;
		int			health;
		float		x;
		float		y;
		int			animationFrame;

		void	move(float dx, float dy);
		void	takeDamage(int amout);
		
	public:
		GameObject(std::string nme, int hlth, float xpos, float ypos, int frame);
		friend ostream&		operator<<(ostream& out, const GameObject& obj);
		friend	class		ScriptEngine;
		friend	bool		operator==(const GameObject &a, const GameObject &b);
		friend	std::string stringify(const GameObject & obj);
		friend bool			operator==(const Position &pos, const GameObject &obj);
};