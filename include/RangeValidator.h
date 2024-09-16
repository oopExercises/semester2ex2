#pragma once
#include "OneBaseValidator.h"


template <class T>
class RangeValidator : public OneBaseValidator <T>
{
	int m_min;
	int m_max;

public:

	RangeValidator(int min, int max) : m_min(min), m_max(max) {};

	virtual bool checkValidation(const T&) const override;
	virtual std::string getErrorMessage() const override;
};

template<class T>
bool RangeValidator<T>::checkValidation(const T& data) const
{
	return data >= m_min && data <= m_max;
}

template<class T>
std::string RangeValidator<T>::getErrorMessage() const
{
	return "Out of range";
}
