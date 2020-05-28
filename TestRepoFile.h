#pragma once
#include "RepoFile.h"

class TestRepoFile {
private:
	vector<EconomicResource*> resourcesIn;

	string filenameInTxt = "TestEconomicResourcesIn.txt";
	string filenameOutTxt = "TestEconomicResourcesOut.txt";
	string filenameInCSV = "TestEconomicResourcesIn.csv";
	string filenameOutCSV = "TestEconomicResourcesOut.csv";

	void testAddResource();
	void testDeleteResource();
	void testUpdateResource();
	void testGetResource();
	void testGetAll();
	void testGetSize();
	void testLoadFromFileTxt();
	void testLoadFromFileCSV();
	void testSaveToFileTxt();
	void testSaveToFileCSV();

public:
	TestRepoFile();
	~TestRepoFile();
	void testAll();
};