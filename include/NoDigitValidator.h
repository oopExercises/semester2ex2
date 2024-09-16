#pragma once
#include <string>
#include "OneBaseValidator.h"



class NoDigitValidator : public OneBaseValidator <std::string>
{


public:
	NoDigitValidator() {};

	virtual bool checkValidation(const std::string&) const override;
	virtual std::string getErrorMessage() const override;
};