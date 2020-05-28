#pragma once
#include <exception>
#include <string.h>
using namespace std;

class ValidatorException : public exception {
private:
	char* message;
public:
	ValidatorException(const char* message)
	{
		this->message = new char[strlen(message) + 1];
		strcpy_s(this->message, 1 + strlen(message), message);

	}
	~ValidatorException()
	{
		if (this->message != NULL)
			delete[] this->message;
	}
	virtual const char* what() {
		return message;
	}
};