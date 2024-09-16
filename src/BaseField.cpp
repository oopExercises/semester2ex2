#include "BaseField.h"

bool BaseField::isFieldEmpty()const
{
	 return m_isEmpty;
}

void BaseField::fieldNotEmpty()
{
	m_isEmpty = false;
}

void BaseField::fieldEmpty()
{
	m_isEmpty = true;
}
