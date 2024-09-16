#pragma once
#include "TwoBaseValidator.h"
#include <iostream>

template < class T1, class T2>
class DestinationToFlightTimeValidator : public TwoBaseValidator
{
	T1* m_destination;
	T2* m_flightTime;

public:
	DestinationToFlightTimeValidator(T1* destination, T2* flightTime) : m_destination(destination), m_flightTime(flightTime) {};

	virtual bool checkFormValidator() override;
	virtual void fixFormFields() const override;
	virtual std::string getErrorMessage() const override;
};

template <typename T1, typename T2>
bool DestinationToFlightTimeValidator<T1, T2>::checkFormValidator()
{
	setValidState(false);
	int destination = m_destination->getField().getValue().getNumber();
	int flightTime = m_flightTime->getField().getValue().getNumber();

	if (destination < 1 || destination > 5 || flightTime < 1 || flightTime > 3)
		return getFormValidState();

	else if ((destination == 1 || destination == 2) && (flightTime == 1 || flightTime == 2))
		setValidState(true);

	else if (destination == 3)
		setValidState(true);

	else if ((destination == 4 || destination == 5) && (flightTime == 2 || flightTime == 3))
		setValidState(true);

	return getFormValidState();

}

template <typename T1, typename T2>
void DestinationToFlightTimeValidator<T1, T2>::fixFormFields() const
{
	std::cout << getErrorMessage() ;
	m_destination->fieldEmpty();
	m_flightTime->fieldEmpty();
}

template <typename T1, typename T2>
std::string DestinationToFlightTimeValidator<T1, T2>::getErrorMessage() const
{
	return "\nDestination and flight time don't match\n";
}