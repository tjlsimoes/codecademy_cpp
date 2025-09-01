#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

class RobotException : public std::exception
{
	private:
		std::string	errorMessage;
	
	public:
		RobotException(const std::string & message);

		const char	*what() const noexcept override
		{
			return errorMessage.c_str();
		}
};

class BatteryLowException : public RobotException
{
	public:
		BatteryLowException(const std::string & message);
};


class MechanicalFailureException : public RobotException
{
	public:
		MechanicalFailureException(const std::string & message);
};



#endif // EXCEPTIONS_HPP