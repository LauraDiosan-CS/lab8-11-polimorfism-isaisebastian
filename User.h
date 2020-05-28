#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {
protected:
	string username;
	string password;
public:
	User();
	User(const string username, const string password);
	User(const User& u);
	~User();

	User* clone();

	string getUsername();
	string getPassword();
	void setUsername(string username);
	void setPassword(string password);

	User& operator=(const User& u);
	bool operator==(const User& u);
	friend ostream& operator<<(ostream& os, const User& u);
	friend istream& operator>>(istream& is, User& u);

	string toString(string delim);

};