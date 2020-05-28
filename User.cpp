 #include "User.h"

User::User()
{
	this->username = "";
	this->password = "";
}

User::User(string username, string password)
{
	this->username = username;
	this->password = password;
}

User::User(const User& u)
{
	this->username = u.username;
	this->password = u.password;
}

User::~User()
{
}

User* User::clone()
{
	return new User(this->username, this->password);
}

string User::getUsername()
{
	return this->username;
}

string User::getPassword()
{
	return this->password;
}

void User::setUsername(string username)
{
	this->username = username;
}

void User::setPassword(string password)
{
	this->password = password;
}

User& User::operator=(const User& u)
{
	this->username = u.username;
	this->password = u.password;
	return *this;
}

bool User::operator==(const User& u)
{
	return this->username == u.username && this->password == u.password;
}

string User::toString(string delim)
{
	return this->username + delim + this->password;
}

ostream& operator<<(ostream& os, const User& u)
{
	os << u.username << " " << u.password << endl;
	return os;
}

istream& operator>>(istream& is, User& u)
{
	is >> u.username >> u.password;
	return is;
}
