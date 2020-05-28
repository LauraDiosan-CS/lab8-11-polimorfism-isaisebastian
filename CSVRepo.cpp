#include "CSVRepo.h"
#include "MaterialResource.h"
#include "FinancialResource.h"
#include <fstream>

CSVRepo::CSVRepo()
{
}

CSVRepo::CSVRepo(string filename) : RepoFile(filename)
{
}

CSVRepo::~CSVRepo()
{
}

void CSVRepo::loadfromfile()
{
	ifstream f(this->filename);
	string line;
	string delim = ",";
	if (f.is_open())
	{
		while (getline(f, line))
		{
			if (line.substr(0, 2) == "FR")
			{
				line = line.erase(0, 3);

				int pos = line.find(delim);
				string name = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				string date = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				double value = stod(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				string currency = line.substr(0, pos);

				FinancialResource* fr = new FinancialResource(name, date, value, currency);
				this->resources.push_back(fr);
			}
			else if (line.substr(0, 2) == "MR")
			{
				line = line.erase(0, 3);

				int pos = line.find(delim);
				string name = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				string date = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				double value = stod(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				int lifetime = stoi(line.substr(0, pos));
				line = line.erase(0, pos + 1);

				pos = line.find(delim);
				int pieces = stoi(line.substr(0, pos));

				MaterialResource* mr = new MaterialResource(name, date, value, lifetime, pieces);
				this->resources.push_back(mr);
			}
		}
		f.close();
	}
}

void CSVRepo::savetofile()
{
	ofstream f(this->filename);
	if (f.is_open())
		for (EconomicResource* ec : this->resources)
			f << ec->toString(",") << endl;
}
