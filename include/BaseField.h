#pragma once
#include <iostream>



class BaseField
{
	bool m_isEmpty = true;

public:

	BaseField() = default;
	virtual ~BaseField() = default;

	bool isFieldEmpty()const;
	void fieldNotEmpty();
	void fieldEmpty();

	virtual void print(std::ostream& os) const = 0;
	virtual void fillField() = 0;
	virtual bool isValid() = 0;
};