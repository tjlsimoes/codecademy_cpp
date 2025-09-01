#include <iostream>
#include <string>
#include <vector>


namespace Sales
{
	class Team
	{
		private:
			std::string					teamName;
			std::vector<std::string>	teamMembers;
			std::string					teamLocation;
		
		public:
			Team(std::string name, std::vector<std::string> members, std::string location) : teamName(name), teamMembers(members), teamLocation(location) {};

			std::string	getTeamName()
			{
				return teamName;
			};

			std::vector<std::string>	getMembers()
			{
				return teamMembers;
			};

			void						addMember(std::string member)
			{
				teamMembers.push_back(member);
			};

			std::string					getLocation()
			{
				return teamLocation;
			};

			void						setLocation(std::string & newLocation)
			{
				teamLocation = newLocation;
			};

			void						printTeamDetails()
			{
				std::cout
				<< "Sales Team Name: " << getTeamName() << "\n"
				<< "Location: " << getLocation() << "\n"
				<< "Members: ";
				for (std::string member : getMembers())
					std::cout << member << " ";
				std::cout << std::endl;
			}
	};
}