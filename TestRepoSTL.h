#pragma once
#include "User.h"
#include "RepoSTL.h"

class TestRepoSTL {
private:
	RepoSTL<User> repo;
	vector<User> users;
	void test_repoSTL_addElem();
	void test_repoSTL_delElem();
	void test_repoSTL_getAll();
public:
	TestRepoSTL();
	void testAll();
};