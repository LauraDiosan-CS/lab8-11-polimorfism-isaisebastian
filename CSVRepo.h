#pragma once
#include "RepoFile.h"

class CSVRepo : public RepoFile {
public:
	CSVRepo();
	CSVRepo(string filename);
	~CSVRepo();
	void loadfromfile();
	void savetofile();
};