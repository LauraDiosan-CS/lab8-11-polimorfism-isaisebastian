#include "TestRepoFile.h"
#include "TXTRepo.h"
#include "CSVRepo.h"
#include "FinancialResource.h"
#include "RepoExc.h"
#include "MaterialResource.h"
#include <assert.h>

void TestRepoFile::testAddResource() 
{
	RepoFile* repofile = new TXTRepo();
	MaterialResource* mr = new MaterialResource("name", "date", 5.0, 20, 200);
	try {
		repofile->addResource(mr);
	}
	catch (...) {
		assert(false);
	}
	assert(*repofile->getResource(0) == *mr);
	FinancialResource* fr = new FinancialResource("Resursa", "14.10.2020", 5.0, "euro");
	try {
		repofile->addResource(fr);
		assert(true);
	}
	catch (RepoExc & ex) {}
	catch (...)
	{
		assert(false);
	}
	assert(repofile->getSize() == 2); 
	assert(*repofile->getResource(0) == *mr);
}

void TestRepoFile::testDeleteResource()
{
	RepoFile* repofile = new TXTRepo();
	FinancialResource* ec1 = new FinancialResource("resursafinanciara", "20.05.2020", 60.5, "ron");
	repofile->addResource(ec1);
	FinancialResource* ec2 = new FinancialResource("resursafinanciara2", "25.06.2021", 100.5, "eur");
	assert(repofile->getSize() == 1);
	assert(*repofile->getResource(0) == *ec1->clone());
	repofile->deleteResource(ec1);
	assert(repofile->getSize() == 0);
}

void TestRepoFile::testUpdateResource()
{
	RepoFile* repofile = new TXTRepo();
	MaterialResource* mr1 = new MaterialResource("name", "14.09.2020", 2.0, 2, 200);
	repofile->addResource(mr1);
	MaterialResource* mr2 = new MaterialResource("abc", "date", 5.0, 20, 400);
	try {
		repofile->updateResource(mr2, mr1);
		assert(true);
	}
	catch(RepoExc & ex){}
	catch (...)
	{
		assert(false);
	}
	assert(*repofile->getResource(0) == *mr1);
	try {
		repofile->updateResource(mr1, mr2);
	}
	catch (...) {
		assert(false);
	}
	assert(*repofile->getResource(0) == *mr2);
}

void TestRepoFile::testGetResource()
{ 
	RepoFile* repofile = new TXTRepo();
	FinancialResource* ec2 = new FinancialResource("resursafinanciara2", "25.06.2021", 100.5, "eur");
	repofile->addResource(ec2);
	assert(*repofile->getResource(0) == *ec2->clone());
}

void TestRepoFile::testGetAll()
{
	RepoFile* repofile = new TXTRepo();
	MaterialResource* ec = new MaterialResource("Carbuni", "2.02.2019", 500.5, 5, 100);
	FinancialResource* ec1 = new FinancialResource("resursafinanciara", "20.05.2020", 60.5, "ron");
	repofile->addResource(ec);
	repofile->addResource(ec1);
	vector<EconomicResource*> resources = repofile->getAll();
	assert(*resources[0] == *ec->clone());
	assert(*resources[1] == *ec1->clone());
}

void TestRepoFile::testGetSize()
{
	RepoFile* repofile = new TXTRepo();
	assert(repofile->getSize() == 0);
	repofile->addResource(new EconomicResource());
	assert(repofile->getSize() == 1);
}

void TestRepoFile::testLoadFromFileTxt()
{
	RepoFile* repofile = new TXTRepo(this->filenameInTxt);
	repofile->loadfromfile();
	assert(repofile->getSize() == this->resourcesIn.size());
	assert(*repofile->getResource(0) == *this->resourcesIn[0]);
}

void TestRepoFile::testLoadFromFileCSV()
{
	RepoFile* repofile = new CSVRepo(this->filenameInCSV);
	repofile->loadfromfile();
	assert(repofile->getSize() == this->resourcesIn.size());
	assert(*repofile->getResource(0) == *this->resourcesIn[0]);
}

void TestRepoFile::testSaveToFileTxt()
{
	RepoFile* repofile = new TXTRepo(this->filenameInTxt);
	repofile->loadfromfile();
	repofile->setfilename(this->filenameOutTxt);
	MaterialResource* ec = new MaterialResource("Carbuni", "2.02.2019", 500.5, 5, 100);
	repofile->addResource(ec);
	repofile->savetofile();
	repofile->loadfromfile();
	assert(repofile->getSize() == this->resourcesIn.size() + 1);
	vector<EconomicResource*> resources = repofile->getAll();
	for (int i = 0; i < repofile->getSize()- 1; i++)
		assert(*resources[i] == *this->resourcesIn[i]);
	assert(*resources[resources.size() - 1] == *ec);
}

void TestRepoFile::testSaveToFileCSV()
{
	RepoFile* repofile = new CSVRepo(this->filenameInCSV);
	repofile->loadfromfile();
	repofile->setfilename(this->filenameOutCSV);
	MaterialResource* ec = new MaterialResource("Carbuni2", "2.02.2019", 500.5, 5, 100);
	repofile->addResource(ec);
	repofile->savetofile();
	repofile->loadfromfile();
	assert(repofile->getSize() == this->resourcesIn.size() + 1);
	vector<EconomicResource*> resources = repofile->getAll();
	for (int i = 0; i < repofile->getSize() - 1; i++)
	{
		assert(*resources[i] == *this->resourcesIn[i]);
	}
	assert(*resources[resources.size() - 1] == *ec);
}

TestRepoFile::TestRepoFile()
{
	MaterialResource* ec = new MaterialResource("Carbuni", "2.02.2019", 500.5, 5, 100);
	FinancialResource* ec1 = new FinancialResource("resursafinanciara", "20.05.2020", 60.5, "ron");
	FinancialResource* ec2 = new FinancialResource("resursafinanciara2", "25.06.2021", 100.5, "eur");
	this->resourcesIn.push_back(ec);
	this->resourcesIn.push_back(ec1);
	this->resourcesIn.push_back(ec2);
}

TestRepoFile::~TestRepoFile()
{
}

void TestRepoFile::testAll()
{
	this->testGetSize();
	this->testUpdateResource();
	this->testDeleteResource();
	this->testGetAll();
	this->testGetResource();
	this->testLoadFromFileCSV();
	this->testLoadFromFileTxt();
	this->testAddResource();
	this->testSaveToFileTxt();
	//this->testSaveToFileCSV();
}
