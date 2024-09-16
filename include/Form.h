#pragma once
#include "Field.h"
#include "TwoBaseValidator.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>

const int N_LONG = 100;
const std::string LONG_LINE = std::string(N_LONG, '-') + '\n';

class Form
{
	std::vector<BaseField*> m_fields;
	std::vector<TwoBaseValidator*> m_valedators;

public:
	Form() {};

	void addField(BaseField* field);
	void addValidator(TwoBaseValidator* validator);

	void fillForm() const;
	bool validateForm() const;
	void printFields(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& ostr, const Form& form);