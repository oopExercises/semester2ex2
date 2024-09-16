#include "NoDigitValidator.h"

bool NoDigitValidator::checkValidation(const std::string& name) const
{
	for (size_t i = 0; i < name.size(); i++)
		if (isdigit(name[i]))
			return false;

	return true;
}


std::string NoDigitValidator::getErrorMessage() const
{
	return "Can't contain digits";
}
