#include "Service.h"
#include "ValidatorException.h"

Service::Service()
{
}

Service::Service(RepoSTL<User>& repo_users, RepoFile* repo_resources)
{
	this->repo_users = repo_users;
	this->repo_resources = repo_resources;
}

Service::Service(const Service& s)
{
	this->repo_users = s.repo_users;
	this->repo_resources = s.repo_resources;
}

void Service::addUser(string username, string password)
{
	this->repo_users.addElem(User(username, password));
}

void Service::addMaterialResource(string name, string date, double value, int lifetime, int pieces) throw(ValidatorException)
{
	MaterialResource* mr = new MaterialResource(name, date, value, lifetime, pieces);
	this->repo_resources->addResource(mr);
}

void Service::addFinancialResource(string name, string date, double value, string currency) throw(ValidatorException)
{
	FinancialResource* fr = new FinancialResource(name, date, value, currency);
	this->repo_resources->addResource(fr);
}

void Service::deleteUser(string username)
{
	for (int i = 0; i < this->repo_users.getSize(); i++)
	{
		if (this->repo_users.getAll()[i].getUsername() == username)
		{
			User user(username, this->repo_users.getAll()[i].getPassword());
			this->repo_users.delElem(user);
			return;
		}
	}
}

vector<User> Service::getAllUsers()
{
	return this->repo_users.getAll();
}

void Service::savetoFile()
{
	this->repo_users.savetofile();
}

void Service::loadFromFile()
{
	this->repo_users.loadfromfile();
}

vector<EconomicResource*> Service::getAllResources()
{
	return this->repo_resources->getAll();
}

void Service::deleteResource(string name)
{
	EconomicResource* ec = new EconomicResource(name, "date", 0);
	this->repo_resources->deleteResource(ec);
}

vector<EconomicResource*> Service::findByNameOrDate(string my_string)
{
	vector<EconomicResource*> resources = this->repo_resources->getAll();
	vector<EconomicResource*> resource_found;
	for (EconomicResource* ec : resources)
	{
		if (ec->getName() == my_string || ec->getDate() == my_string)
			resource_found.push_back(ec);
	}
	return resource_found;
}

void Service::updateMaterialResource(string oldName, string NewName, string date, double value, int lifetime, int pieces) throw(ValidatorException)
{
	MaterialResource* newEc = new MaterialResource(NewName, date, value, lifetime, pieces);
	EconomicResource* oldEc = new EconomicResource(oldName, "string", 0);
	this->repo_resources->updateResource(oldEc, newEc);

}

void Service::updateFinancialResource(string oldName, string newName, string date, double value, string currency) throw(ValidatorException)
{
	EconomicResource* oldEc = new EconomicResource(oldName, "string", 0);
	FinancialResource* newEc = new FinancialResource(newName, date, value, currency);
	this->repo_resources->updateResource(oldEc, newEc);
}


Service& Service::operator=(const Service s)
{
	this->repo_users = s.repo_users;
	return *this;
}

void Service::setRepo(RepoFile* repo)
{
	this->repo_resources = repo;
}

bool Service::login_attempt(string username, string password)
{
	for (int i = 0; i < this->repo_users.getSize(); i++)
	{
		if (this->repo_users.getAll()[i].getUsername() == username && this->repo_users.getAll()[i].getPassword() == password)
		{
			return true;
		}
	}
	return false;
}
