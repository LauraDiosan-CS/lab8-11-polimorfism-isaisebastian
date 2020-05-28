#include <iostream>
#include "EconomicResource.h"
#include "User.h"
#include "TestEconomicResource.h"
#include "TestValidatorResource.h"
#include "TestRepoFile.h"
#include "TestService.h"
#include "TestRepoSTL.h"
#include "UI.h"

using namespace std;

int main()
{
	TestValidatorResource val;
	val.testAll();
	TestRepoSTL test_repoSTL; 
	test_repoSTL.testAll();
	TestService test_service;
	test_service.testAll();
	TestEconomicResource reporesource;
	reporesource.testAll();
	TestRepoFile repofile;
	repofile.testAll();

	RepoFile* repo = new TXTRepo("Resources.txt");
	RepoSTL<User> repo_user;
	repo_user.setf_name("Users.txt");
	Service s(repo_user, repo);
	UI ui(s);
	ui.runUI();
	return 0;
}