#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <BaseField.h>
#include "OneBaseValidator.h"
#include "ValuesToNames.h"

const int N_LENTH = 70;


template <typename T>
class Field : public BaseField
{
	T m_answer = {};
	std::string m_question;
	std::string m_errorMessage;
	std::vector<OneBaseValidator<T>*> m_validators = {};

public:

	Field() = default;
	Field(std::string question) ;

	void addValidator(OneBaseValidator <T>* val) ;
	T getAnswer()const;
	T getField()const;
	virtual void print(std::ostream& os) const override;
	virtual void fillField() override;
	virtual bool isValid() override;
};

template<typename T>
inline Field<T>::Field(std::string question) : m_question(question)
{
}

template<typename T>
inline void Field<T>::addValidator(OneBaseValidator<T>* val)
{
	 m_validators.push_back(val); 
}

template <class T>
T Field<T>::getAnswer()const
{
	return m_answer;
}

template <class T>
T  Field<T>::getField()const
{
	return m_answer;
}

template<typename T>
void Field<T>::print(std::ostream& os) const
{
	os << m_question << " = " << m_answer << "          " <<  m_errorMessage << "\n";
}

template<typename T>
void Field<T>::fillField()
{
	std::cout << std::endl << m_question << std::endl;
	std::cin >> m_answer;
}

template<typename T>
bool Field<T>::isValid()
{
	for (auto& validator : m_validators)
	{

		if (!validator->checkValidation(m_answer))
		{
			m_errorMessage = validator->getErrorMessage();
			return false;
		}
		m_errorMessage = "";
	}
	return true;
}