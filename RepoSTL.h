#pragma once
#include <vector>
#include <fstream>
#include <cstddef>
using namespace std;

template <class T>
class RepoSTL {
protected:
	vector<T> comp;
	char* f_name;
public:
	RepoSTL() {
		this->f_name = NULL;
	}
	RepoSTL(const char* f_name)
	{
		this->f_name = new char[strlen(f_name) + 1];
		strcpy_s(this->f_name, strlen(f_name) + 1, f_name);
		this->loadfromfile();
	}
	RepoSTL(const RepoSTL& repostl)
	{
		this->f_name = new char[strlen(repostl.f_name) + 1];
		strcpy_s(this->f_name, 1 + strlen(repostl.f_name), repostl.f_name);
		this->loadfromfile();

	}
	void addElem(T e) {
		this->comp.push_back(e);
	}

	void delElem(T e) {
		typename vector<T>::iterator it;
		it = find(this->comp.begin(), this->comp.end(), e);
		if (it != comp.end())
			this->comp.erase(it);
	}

	void clear()
	{
		this->comp.clear();
	}

	void updateElem(T& oldE, T& newE)
	{
		typename vector<T>::iterator it;
		for (it = this->comp.begin(); it != this->comp.end(); it++)
		{
			if (*it == oldE)
				*it = newE;
		}
	}

	vector<T> getAll() {
		return this->comp;
	}

	int getSize() {
		return this->comp.size();
	}

	T getAtPosition(int pos)
	{
		return this->comp[pos];
	}
	void setf_name(const char* f_name) {
		if (this->f_name != NULL)
			delete[]this->f_name;
		if (f_name != NULL)
		{
			this->f_name = new char[strlen(f_name) + 1];
			strcpy_s(this->f_name, strlen(f_name) + 1, f_name);
		}
		else this->f_name = NULL;
	}
	void loadfromfile()
	{
		if (this->f_name != NULL) {
			this->comp.clear();
			ifstream f(this->f_name);
			T elem;
			while (f >> elem)
				addElem(elem);
			f.close();
		}
	}
	void savetofile()
	{
		if (this->f_name != NULL)
		{
			ofstream f(this->f_name);
			int len = this->comp.size();
			for (size_t i = 0; i < len; i++)
				f << getAtPosition(i) << endl;
			f.close();
		}
	}
	~RepoSTL()
	{
		this->comp.clear();
	}
};