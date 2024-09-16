#pragma once
#include <string>
#include "OneBaseValidator.h"

class IdValidator : public OneBaseValidator <uint32_t>
{


public:
	IdValidator() {};

	virtual bool checkValidation(const uint32_t&) const override;
	virtual std::string getErrorMessage() const override;

};