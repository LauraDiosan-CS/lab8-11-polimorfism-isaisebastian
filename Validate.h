#pragma once
#include <string.h>
#include <exception>
using namespace std;

class Validate : public exception {
private:
	char* message;
public:
	Validate(const char* message)
	{
		this->message = new char[strlen(message) + 1];
		strcpy_s(this->message, strlen(message) + 1, message);
	}
	~Validate() {
		if (this->message != NULL) {
			delete[] this->message;
		}
	}
	virtual const char* what() {
		return this->message;
	}
};