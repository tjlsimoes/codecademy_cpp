#include <iostream>
#include <string>
#include <vector>

namespace Marketing
{
	class Team
	{
		private:
			std::string 				teamName;
			std::vector<std::string>	teamMembers;
			double						teamBudget;
		
		public:
			Team(std::string name, std::vector<std::string> members, int budget) : teamName(name), teamMembers(members), teamBudget(budget) {};
			
			std::string getName()
			{
				return teamName;
			};
			
			void		addMember(std::string member)
			{
				teamMembers.push_back(member);
			};

			int			getMemberCount()
			{
				return teamMembers.size();
			};

			double		getBudget()
			{
				return teamBudget;
			};

			void		setBudget(double newBudget)
			{
				teamBudget = newBudget;
			};

	};

	namespace Support
	{
		void	auditTeam(Marketing::Team &team)
		{
			std::cout << "Auditing Marketing Team: " << team.getName()  << "\n"
			<< "Number of Members: " << team.getMemberCount()  << "\n"
			<< "Team Budget: $ " << team.getBudget()  << "\n"
			<< "Audit complete!"
			<< std::endl;
		};
	}
}