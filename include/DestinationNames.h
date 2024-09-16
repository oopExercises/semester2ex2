#include <iostream>
#include <string>
#include <vector>

class DestinationNames
{
	std::vector<std::string> m_names = { "Rome", "Prague", "New York", "India", "Thailand" };
	int m_answer;
public:
	DestinationNames();
	~DestinationNames();
	std::string getAllNames()const;
	std::string getName()const;
	void printAnswer(std::ostream& os)const;
	void setAnswer(std::istream& is);
	int getNumber()const;
};

std::ostream& operator<<(std::ostream& os, const DestinationNames& val);

std::istream& operator>>(std::istream& is, DestinationNames& val);

bool operator<= (const DestinationNames& val1, const int val2);

bool operator>= (const DestinationNames& val1, const int val2);