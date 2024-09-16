#pragma once
#include "TwoBaseValidator.h"


template < class T1, class T2>
class DestinationToWifiBundleValidator : public TwoBaseValidator
{
	T1* m_destination;
	T2* m_wifiBundle;

public:
	DestinationToWifiBundleValidator(T1* destination, T2* wifiBundle) : m_destination(destination), m_wifiBundle(wifiBundle) {};

	virtual bool checkFormValidator() override;
	virtual void fixFormFields() const override;
	virtual std::string getErrorMessage() const override;
};

//......................................................................
template <typename T1, typename T2>
bool DestinationToWifiBundleValidator<T1, T2>::checkFormValidator()
{
	setValidState(false);
	int destination = m_destination->getField().getValue().getNumber();
	int wifiBundle = m_wifiBundle->getField().getValue().getNumber();

	if ((destination < 1 || destination > 5 || wifiBundle < 1 || wifiBundle > 3)
		|| (destination == 3 && wifiBundle == 2)
		|| ((destination == 4 || destination == 5) && wifiBundle == 3))
		;
	else
		setValidState(true);
	return getFormValidState();

}

template <typename T1, typename T2>
void DestinationToWifiBundleValidator<T1, T2>::fixFormFields() const
{
	std::cout << getErrorMessage();
	m_destination->fieldEmpty();
	m_wifiBundle->fieldEmpty();
}

template <typename T1, typename T2>
std::string DestinationToWifiBundleValidator<T1, T2>::getErrorMessage() const
{
	return "\nDestination and WIFI Bundle don't match\n";
}