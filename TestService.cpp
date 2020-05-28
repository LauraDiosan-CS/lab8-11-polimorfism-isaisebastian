#include "TestService.h"
#include <cassert>
#include "RepoExc.h"

void TestService::test_getAll()
{
	Service s;
	RepoFile* repo = new TXTRepo();
	s.setRepo(repo);
	MaterialResource* mr1 = new MaterialResource("name", "date", 2.0, 20, 100);
	MaterialResource* mr2 = new MaterialResource("name2", "date2", 3.0, 40, 400);
	s.addMaterialResource(mr1->getName(), mr1->getDate(), mr1->getValue(), mr1->getLifeTime(), mr1->getPieces());
	s.addMaterialResource(mr2->getName(), mr2->getDate(), mr2->getValue(), mr2->getLifeTime(), mr2->getPieces());
	vector<EconomicResource*> resources = s.getAllResources();
	assert(*resources[0] == *mr1);
	assert(*resources[1] == *mr2);
}

void TestService::test_addMaterialResource()
{
	Service s;
	RepoFile* repo = new TXTRepo();
	s.setRepo(repo);
	MaterialResource* mr1 = new MaterialResource("name", "date", 5.0, 20, 20);
	try {
		s.addMaterialResource(mr1->getName(), mr1->getDate(), mr1->getValue(), mr1->getLifeTime(), mr1->getPieces());
	}
	catch (...)
	{
		assert(false);
	}
	assert(*s.getAllResources()[0] == *mr1);
}

void TestService::test_addFinancialResource()
{
	Service s;
	RepoFile* repo = new TXTRepo();
	s.setRepo(repo);
	FinancialResource* fr1 = new FinancialResource("name", "date", 5.0, "ron");
	try {
		s.addFinancialResource(fr1->getName(), fr1->getDate(), fr1->getValue(), fr1->getCurrency());
	}
	catch (...) {
		assert(false);
	}
	assert(*s.getAllResources()[0] == *fr1);
}

void TestService::test_addUser()
{
	Service s(RepoSTL<User> repousers);

	User u1("Sebastian", "hgfder");
	User u2("Ionut", "gguiO01");
	User u3("Andrei", "AcvYu5");

	this->s.addUser("Sebastian", "hgfder");
	this->s.addUser("Ionut", "gguiO01");
	this->s.addUser("Andrei", "AcvYu5");

	assert(this->s.getAllUsers()[0] == u1);
	assert(this->s.getAllUsers()[1] == u2);
	assert(this->s.getAllUsers()[2] == u3);
}

void TestService::test_deleteUser()
{

	User u1("Sebastian", "hgfder");
	User u2("Ionut", "gguiO01");
	User u3("Andrei", "AcvYu5");

	this->s.addUser("Sebastian", "hgfder");
	this->s.addUser("Ionut", "gguiO01");
	this->s.addUser("Andrei", "AcvYu5");
	this->s.deleteUser("Sebastian");

	assert(!(this->s.getAllUsers()[0] == u1));
}

void TestService::test_login()
{
 	this->s.addUser("Sebastian", "hgfder");
	this->s.addUser("Ionut", "gguiO01");
	this->s.addUser("Andrei", "AcvYu5");
	assert(this->s.login_attempt("Ionut", "wrongpass") == false);
	assert(this->s.login_attempt("Ionut", "gguiO01") == true);
}

TestService::TestService()
{
}

void TestService::testAll()
{
	this->test_addFinancialResource();
	this->test_addMaterialResource();
	this->test_getAll();
	this->test_addUser();
	this->test_deleteUser();
	this->test_login();
}
