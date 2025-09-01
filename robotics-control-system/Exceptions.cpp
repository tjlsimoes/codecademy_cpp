#include "Exceptions.hpp"

RobotException::RobotException(const std::string & message)
{
	errorMessage = message;
}

BatteryLowException::BatteryLowException(const std::string & message) : RobotException(message) 
{}


MechanicalFailureException::MechanicalFailureException(const std::string & message) : RobotException(message) 
{}




