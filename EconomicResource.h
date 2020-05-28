#pragma once
#include <string>
#include <iostream>
using namespace std;

class EconomicResource {
protected:
	string name;
	string date;
	double value;
public:
	EconomicResource();
	EconomicResource(string name, string date, double value);
	EconomicResource(const EconomicResource& ec);
	~EconomicResource();

	string getName();
	string getDate();
	double getValue();
	
	void setName(string name);
	void setDate(string date);
	void setValue(double value);

	EconomicResource& operator=(const EconomicResource& ec);
	bool operator==(const EconomicResource& ec);

	virtual EconomicResource* clone();
	virtual string toString(string delim);
};