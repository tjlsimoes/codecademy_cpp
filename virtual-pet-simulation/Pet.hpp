#ifndef PET_HPP
#define PET_HPP

#include <string>
using namespace std;

class Pet
{
	private:
		std::string name;
		int			age;
	
	public:
		virtual ~Pet();
		std::string	getName();
		int			getAge();
		void		setName(std::string newName);
		void		setAge(int newAge);
		void		eat();
		virtual void	makeSound() = 0;
};

#endif
