#pragma once
#include <exception>
#include <string>
namespace Arkanoid 
{
	///Defines a exception thrown when stage cannot be found
	struct StageNotFoundException : public std::exception
	{
		const std::string Message() const throw() {
			return "Stage not found! Check if stage file is in proper folder";
		}
	};
}