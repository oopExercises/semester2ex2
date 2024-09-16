#include "FlightTimes.h"



FlightTimes::FlightTimes() :m_answer(0)
{
}

FlightTimes::~FlightTimes()
{
}

std::string FlightTimes::getAllNames()const
{
	return "(1 - Morning / Noon, 2 - After - Noon / Evening, 3 - Night)";
}

std::string FlightTimes::getName() const
{
	if (m_answer < 1 || m_answer > m_names.size())
		return std::to_string(m_answer);
	return m_names[m_answer - 1];
}


void FlightTimes::printAnswer(std::ostream& os) const
{
	os << getName();
}

void FlightTimes::setAnswer(std::istream& is)
{
	is >> m_answer;
}

int FlightTimes::getNumber() const
{
	return m_answer;
}

std::ostream& operator<<(std::ostream& os, const FlightTimes& val)
{
	val.printAnswer(os);
	return os;
}

std::istream& operator>>(std::istream& is, FlightTimes& val)
{
	val.setAnswer(is);
	return is;
}

bool operator<=(const FlightTimes& val1, const int val2)
{
	return val1.getNumber() <= val2;
}

bool operator>=(const FlightTimes& val1, const int val2)
{
	return val1.getNumber() >= val2;
}
