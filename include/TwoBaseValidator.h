#pragma once
#include <string>



class TwoBaseValidator
{
private:
	bool m_valid;

public:

	TwoBaseValidator() = default;

	virtual bool checkFormValidator() = 0;
	virtual void fixFormFields() const = 0;
	virtual std::string getErrorMessage() const = 0;

	bool getFormValidState() const { return m_valid; };
	void setValidState(bool state) { m_valid = state; };
};

