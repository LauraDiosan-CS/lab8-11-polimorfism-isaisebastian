#pragma once
#include "User.h"
#include "MaterialResource.h"
#include "FinancialResource.h"
#include "TXTRepo.h"
#include "CSVRepo.h"
#include "RepoSTL.h"
#include "RepoFile.h"

class Service {
private:
	RepoSTL<User> repo_users;
	RepoFile* repo_resources;
public:
	Service();
	Service(RepoSTL<User>& repo_users, RepoFile*);
	Service(const Service& s);
	void addUser(string username, string password);
	void addMaterialResource(string name, string date, double value, int lifetime, int pieces);
	void addFinancialResource(string name, string date, double value, string currency);
	void deleteUser(string username);
	vector<User> getAllUsers();
	void savetoFile();
	void loadFromFile();
	vector<EconomicResource*> getAllResources();
	void deleteResource(string name);
	vector<EconomicResource*> findByNameOrDate(string my_string);
	void updateMaterialResource(string oldName, string NewName, string date, double value, int lifetime, int pieces);
	void updateFinancialResource(string oldName, string newName, string date, double value, string currency);
	Service& operator=(const Service s);
	void setRepo(RepoFile* repo);
	bool login_attempt(string username, string password);
};