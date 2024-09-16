#include <iostream>
#include <string>
#include <vector>

class FlightTimes
{
	std::vector<std::string> m_names = { "Morning/Noon", "After-Noon/Evening", "Night" };
	int m_answer;
public:
	FlightTimes();
	~FlightTimes();
	std::string getAllNames()const;
	std::string getName()const;
	void printAnswer(std::ostream& os)const;
	void setAnswer(std::istream& is);
	int getNumber()const;
};

std::ostream& operator<<(std::ostream& os, const FlightTimes& val);

std::istream& operator>>(std::istream& is, FlightTimes& val);

bool operator<= (const FlightTimes& val1, const int val2);

bool operator>= (const FlightTimes& val1, const int val2);