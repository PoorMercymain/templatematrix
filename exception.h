#pragma once

#include <stdexcept>

class exception : public std::exception
{
private:
	std::string errorMessage;	
public:
	
	
	
	exception(std::string message);

	
	const char* what() const noexcept override;
};
