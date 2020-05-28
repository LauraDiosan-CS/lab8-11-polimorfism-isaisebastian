#pragma once
#include <vector>
#include "EconomicResource.h"
#include "ValidatorFinancialResource.h"
#include "ValidatorMaterialResource.h"
using namespace std;

class RepoFile {
protected:
	vector<EconomicResource*> resources;
	string filename;
	ValidatorFinancialResource validatorFR;
	ValidatorMaterialResource validatorMR;
public:
	RepoFile();
	RepoFile(string filename);
	~RepoFile();

	int getSize();
	vector<EconomicResource*> getAll();
	EconomicResource* getResource(int pos);
	void addResource(EconomicResource* ec);
	void updateResource(EconomicResource* oldEc, EconomicResource* newEc);
	void deleteResource(EconomicResource* ec);

	void setfilename(string filename);

	virtual void loadfromfile() = 0;
	virtual void savetofile() = 0;

	void emptyRepoFile();
};