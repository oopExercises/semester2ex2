#pragma once
#include <iostream>
#include <vector>

template<class T>
class ValuesToNames
{
	T m_value;

public:
	std::string valuesAndNames();
	void printAnswer(std::ostream& os)const;
	void setAnswer(std::istream& is);
	T  getValue()const;
};

template<class T>
inline std::string ValuesToNames<T>::valuesAndNames()
{
	return m_value.getAllNames();
}

template <class T>
void ValuesToNames<T>::printAnswer(std::ostream& os) const
{
	os << m_value;
}

template <class T>
void ValuesToNames<T>::setAnswer(std::istream& is)
{
	is >> m_value;
}

template <class T>
T  ValuesToNames<T>::getValue() const
{
	return m_value;
}


template <class T>
std::ostream& operator<<(std::ostream& os, const ValuesToNames<T>& val)
{
	val.printAnswer(os);
	return os;
}

template <class T>
std::istream& operator>>(std::istream& is, ValuesToNames<T>& val)
{
	val.setAnswer(is);
	return is;
}

template <class T>
bool operator<=(const ValuesToNames<T>& val1, const int val2)
{
	return val1.getValue() <= val2;
}

template <class T>
bool operator>=(const ValuesToNames<T>& val1, const int val2)
{
	return val1.getValue() >= val2;
}