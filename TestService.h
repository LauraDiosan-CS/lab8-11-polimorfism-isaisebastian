#pragma once
#include "Service.h"
#include "RepoSTL.h"
#include <vector>
#include "User.h"

class TestService {
private:
	Service s;
	void test_getAll();
	void test_addMaterialResource();
	void test_addFinancialResource();
	void test_updateMaterialResource();
	void test_updateFinancialResource();
	void test_findByNameOrDate();
	void test_deleteResource();
	void test_addUser();
	void test_deleteUser();
	void test_login();
public:
	TestService();
	void testAll();
};