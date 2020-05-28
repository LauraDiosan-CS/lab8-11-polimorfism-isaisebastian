#pragma once
#include "RepoFile.h"

class TXTRepo : public RepoFile {
public:
	TXTRepo();
	TXTRepo(string filename);
	~TXTRepo();
	void loadfromfile();
	void savetofile();
};