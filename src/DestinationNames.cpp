#include "DestinationNames.h"



DestinationNames::DestinationNames():m_answer(0)
{
}

DestinationNames::~DestinationNames()
{
}

std::string DestinationNames::getAllNames()const
{
	return "(1 - Rome, 2 - Prague, 3 - New York, 4 - India, 5 - Thailand)";
}

std::string DestinationNames::getName() const
{
	if (m_answer < 1 || m_answer > m_names.size())
		return std::to_string(m_answer);
	return m_names[m_answer-1];
}

void DestinationNames::printAnswer(std::ostream& os) const
{
	os << getName();
}

void DestinationNames::setAnswer(std::istream& is)
{
	is >> m_answer;
}

int DestinationNames::getNumber() const
{
	return m_answer;
}

std::ostream& operator<<(std::ostream& os, const DestinationNames& val)
{
	val.printAnswer(os);
	return os;
}

std::istream& operator>>(std::istream& is, DestinationNames& val)
{
	val.setAnswer(is);
	return is;
}

bool operator<=(const DestinationNames& val1, const int val2)
{
	return val1.getNumber() <= val2;
}

bool operator>=(const DestinationNames& val1, const int val2)
{
	return val1.getNumber() >= val2;
}
