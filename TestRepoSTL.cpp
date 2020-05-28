#include "TestRepoSTL.h"
#include <cassert>

void TestRepoSTL::test_repoSTL_addElem()
{
	this->repo.setf_name("TestUsers.txt");
	this->repo.loadfromfile();
	this->repo.clear();
	User u5("Ioana", "mypassword");
	User u6("Raluca", "pass");
	this->repo.addElem(u5);
	this->repo.addElem(u6);

	assert(this->repo.getSize() == 2);
	assert(this->repo.getAtPosition(0) == u5);
}

void TestRepoSTL::test_repoSTL_delElem()
{
	this->repo.setf_name("TestUsers.txt");
	this->repo.loadfromfile();
	this->repo.clear();
	User u1("Ioana", "mypassword2");
	User u2("Raluca", "pass2");

	this->repo.addElem(u1);
	this->repo.addElem(u2);
	this->repo.delElem(u2);

	assert(this->repo.getSize() == 1);
	assert(this->repo.getAtPosition(0) == u1);
}

void TestRepoSTL::test_repoSTL_getAll()
{
	this->repo.setf_name("TestUsers.txt");
	this->repo.loadfromfile();
	this->repo.clear();

	User u8("Andreas", "asdfgh");
	User u9("Ion", "qwerty");

	this->repo.addElem(u8);
	this->repo.addElem(u9);

	assert(this->repo.getAll()[0] == u8);
	assert(this->repo.getAll()[1] == u9);
}

TestRepoSTL::TestRepoSTL()
{
	User u1("Sebastian", "password");
	User u2("Ionut", "password2");
	User u3("Andrei", "password3");
	User u4("Dragos", "password4");
	this->users.push_back(u1);
	this->users.push_back(u2);
	this->users.push_back(u3);
	this->users.push_back(u4);
}

void TestRepoSTL::testAll()
{
	this->test_repoSTL_addElem();
	this->test_repoSTL_delElem();
	this->test_repoSTL_getAll();
}
