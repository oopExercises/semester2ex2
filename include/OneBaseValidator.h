#pragma once
#include <string>
template <class T>
class OneBaseValidator
{

public:
	OneBaseValidator() = default;

	virtual bool checkValidation(const T&) const = 0;
	virtual std::string getErrorMessage() const = 0;
};