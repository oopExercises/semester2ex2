#include "form.h"




void Form::addField(BaseField* field)
{
	 m_fields.push_back(field); 
}

void Form::addValidator(TwoBaseValidator* validator)
{
	 m_valedators.push_back(validator); 
}

void Form::fillForm() const
{
	for (auto& field : m_fields)
	{
		if (field->isFieldEmpty() || !field->isValid())
		{
			field->fillField();
			field->fieldNotEmpty();
		}
	}
}

bool Form::validateForm() const
{
	bool valid = true;
	for (auto& field : m_fields)
	{
		if (!field->isValid())
			valid = false;
	}

	if (valid)
	{
		for (auto& valedator : m_valedators)
		{
			if (!valedator->checkFormValidator())
				valid = false;
		}
	}

	return valid;
}

void Form::printFields(std::ostream& os) const
{
	for (size_t i = 0; i < m_fields.size(); i++)
	{
		std::cout << LONG_LINE << '\n';
		m_fields[i]->print(os);
		std::cout << LONG_LINE << '\n';
	}

	for (size_t i = 0; i < m_valedators.size(); i++)
		if (!m_valedators[i]->getFormValidState())
			m_valedators[i]->fixFormFields();
}


std::ostream& operator<<(std::ostream& ostr, const Form& form)
{
	form.printFields(ostr);
	return ostr;
}