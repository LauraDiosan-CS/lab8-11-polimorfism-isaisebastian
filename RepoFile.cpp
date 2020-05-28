#include "RepoFile.h"
#include "RepoExc.h"
#include "ValidatorException.h"
#include <typeinfo>
#include "MaterialResource.h"
#include "FinancialResource.h"

RepoFile::RepoFile()
{
}

RepoFile::RepoFile(string filename)
{
	this->filename = filename;
}

RepoFile::~RepoFile()
{
}

int RepoFile::getSize()
{
	return this->resources.size();
}

vector<EconomicResource*> RepoFile::getAll()
{
	return this->resources;
}

EconomicResource* RepoFile::getResource(int pos) throw(RepoExc)
{
	if (pos >= 0 && pos < this->getSize())
		return this->resources[pos]->clone();
	throw RepoExc("Index invalid.");
}

void RepoFile::addResource(EconomicResource* ec) throw(ValidatorException)
{
	if (typeid(*ec) == typeid(MaterialResource))
		this->validatorMR.validate(ec);
	if (typeid(*ec) == typeid(FinancialResource))
		this->validatorFR.validate(ec);
	this->resources.push_back(ec->clone());
	this->savetofile();
}

void RepoFile::updateResource(EconomicResource* oldEc, EconomicResource* newEc) throw(ValidatorException)
{
	if (typeid(*newEc) == typeid(MaterialResource))
		this->validatorMR.validate(newEc);
	if (typeid(*newEc) == typeid(FinancialResource))
		this->validatorFR.validate(newEc);
	for(int i = 0; i < this->resources.size(); i++)
		if (this->getResource(i)->getName() == oldEc->getName())
		{
			delete this->resources[i];
			this->resources[i] = newEc->clone();
			this->savetofile();
			return;
		}
}

void RepoFile::deleteResource(EconomicResource* ec) throw(RepoExc)
{
	for (int i = 0; i < this->resources.size(); i++)
	{
		if (this->resources[i]->getName() == ec->getName()){
			delete this->resources[i];
			this->resources.erase(this->resources.begin() + i);
			this->savetofile();
			return;
		}
	}
}

void RepoFile::setfilename(string filename)
{
	this->filename = filename;
}

void RepoFile::emptyRepoFile()
{
	for (int i = 0; i < this->getSize(); i++)
		delete this->resources[i];
	this->resources.clear();
}
