#pragma once
#include <string>
#include <exception>
using namespace std;

class RepoExc : public exception {
private:
	string message;
public:
	RepoExc(const string message) {
		this->message = message;
	}
	~RepoExc()
	{}
	virtual const string what() {
		return message;
	}
};