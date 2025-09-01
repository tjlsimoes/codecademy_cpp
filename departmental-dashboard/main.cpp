#include <iostream>
#include "Marketing.hpp"
#include "Sales.hpp"


namespace audit = Marketing::Support;

int main() {
	std::vector<std::string>	marketingMembers;
	std::vector<std::string>	salesMembers;

	Marketing::Team	marketingTeam("Stellar Corp", marketingMembers, 500000);
	marketingTeam.addMember("Scott");
	marketingTeam.addMember("Nicole");
	marketingTeam.addMember("Artem");

	Sales::Team salesTeam("Stellar Corp", salesMembers, "London");
	salesTeam.addMember("Pratik");
	salesTeam.addMember("Emily");
	salesTeam.addMember("Clive");

	salesTeam.printTeamDetails();

	std::cout << "---------------------------" << std::endl;
	std::cout << "---------------------------" << std::endl;

	std::string newLocation = "New York";
	salesTeam.setLocation(newLocation);

	salesTeam.printTeamDetails();
	std::cout << "---------------------------" << std::endl;
	std::cout << "---------------------------" << std::endl;

	audit::auditTeam(marketingTeam);

	return 0;
}
