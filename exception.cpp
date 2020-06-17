#include "exception.h"

exception::exception(std::string message)
{
	errorMessage = message;
}

const char* exception::what() const noexcept
{
	return errorMessage.c_str();
}