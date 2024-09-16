#include "WifiBundle.h"



WifiBundle::WifiBundle() :m_answer(0)
{
}

WifiBundle::~WifiBundle()
{
}

std::string WifiBundle::getAllNames()const
{
	return "(1 - None, 2 - Basic, 3 - Extended)";
}


std::string WifiBundle::getName() const
{
	if (m_answer < 1 || m_answer > m_names.size())
		return std::to_string(m_answer);
	return m_names[m_answer - 1];
}

void WifiBundle::printAnswer(std::ostream& os) const
{
	os << getName();
}

void WifiBundle::setAnswer(std::istream& is)
{
	is >> m_answer;
}

int WifiBundle::getNumber() const
{
	return m_answer;
}

std::ostream& operator<<(std::ostream& os, const WifiBundle& val)
{
	val.printAnswer(os);
	return os;
}

std::istream& operator>>(std::istream& is, WifiBundle& val)
{
	val.setAnswer(is);
	return is;
}

bool operator<=(const WifiBundle& val1, const int val2)
{
	return val1.getNumber() <= val2;
}

bool operator>=(const WifiBundle& val1, const int val2)
{
	return val1.getNumber() >= val2;
}
