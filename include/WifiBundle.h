#include <iostream>
#include <string>
#include <vector>

class WifiBundle
{
	std::vector<std::string> m_names = { "None", "Basic", "Extended" };
	int m_answer;
public:
	WifiBundle();
	~WifiBundle();
	std::string getAllNames()const;
	std::string getName()const;
	void printAnswer(std::ostream& os)const;
	void setAnswer(std::istream& is);
	int getNumber()const;
};

std::ostream& operator<<(std::ostream& os, const WifiBundle& val);

std::istream& operator>>(std::istream& is, WifiBundle& val);

bool operator<= (const WifiBundle& val1, const int val2);

bool operator>= (const WifiBundle& val1, const int val2);