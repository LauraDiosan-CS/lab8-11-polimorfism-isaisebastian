#include "UI.h"
#include "RepoExc.h"
#include "ValidatorException.h"
#include <conio.h>

void UI::showMenu()
{
	cout << endl;
	cout << "** OPTIONS ** " << endl;
	cout << endl;
	cout << "* 1. Add material resource" << endl;
	cout << "* 2. Add financial resource" << endl;
	cout << "* 3. Modify resource" << endl;
	cout << "* 4. Delete resource" << endl;
	cout << "* 5. Search resource by name or date " << endl;
	cout << "* 6. Logout" << endl;
	cout << "-------------------------------" << endl;
	cout << "* 0. Exit" << endl;
}

void UI::UISearch()
{
	cout << "Give me the name or the date for resource to search: ";
	string my_string;
	cin >> my_string;
	for (EconomicResource* ec : this->s.findByNameOrDate(my_string))
		cout << ec->toString(" ") << endl;
}

void UI::UIModifyResource()
{
	cout << "Old name: ";
	string oldname;
	cin >> oldname;
	int op;
	do {
		cout << "What resource you add? 1. material 2. financial: ";
		cin >> op;
	} while (op < 1 || op > 2);
	cout << "New name: ";
	string name; 
	cin >> name;
	string date;
	cout << "Date: "; cin >> date;
	double value;
	cout << "Value: "; cin >> value;

	if (op == 1) {
		int lifetime;
		cout << "Lifetime: "; cin >> lifetime;
		int pieces;
		cout << "Pieces: "; cin >> pieces;
		try {
			this->s.updateMaterialResource(oldname, name, date, value, lifetime, pieces);
		}
		catch (ValidatorException & e) {
			cout << e.what() << endl;
		}
		catch (RepoExc & ex) {
			cout << ex.what() << endl;
		}
	}
	else {
		string currency;
		cout << "Currency: "; cin >> currency;
		try {
			this->s.updateFinancialResource(oldname, name, date, value, currency);
		}
		catch (ValidatorException & e) {
			cout << e.what() << endl;
		}
		catch (RepoExc & e) {
			cout << e.what() << endl;
		}
	}
	cout << endl;
	for (EconomicResource* ec : this->s.getAllResources())
		cout << ec->toString(" ") << endl;
}

void UI::chooseFile()
{
	int option = 0;
	cout << "Alege formatul fisierului. Scrie 1 pentru .txt sau 2 pentru .csv: ";
	cin >> option;
	while (option < 1 || option > 2) {
		cout << "Identificator gresit. Incearca din nou: ";
		cin >> option;
	}
	if (option == 1)
		this->s.setRepo(new TXTRepo("Resources.txt"));
	else
		this->s.setRepo(new CSVRepo("Resources.csv"));
}

UI::UI()
{
}

UI::UI(Service& s)
{
	this->s = s;
}

UI::~UI()
{
}

void UI::runUI()
{
	bool run = true;
	int op;
	string user;
	string pass = "";
	char ch;
	cout << "* LOGIN *" << endl;
	cout << "* Username: "; cin >> user;
	cout << "* Password: ";
	ch = _getch();
	while (ch != 13) {
		pass.push_back(ch);
		cout << "*";
		ch = _getch();
	}
	this->s.loadFromFile();
	if (this->s.login_attempt(user, pass))
	{
		cout << endl;
		this->chooseFile();
		for (EconomicResource* ec : this->s.getAllResources())
			cout << ec->toString(" ") << endl;
		while (run) {
			this->showMenu();
			cout << "Option: "; cin >> op;
			switch (op) {
			case 1: {UIAddMaterialResource(); break; }
			case 2: {UIAddFinancialResource(); break; }
			case 3: {UIModifyResource(); break; }
			case 4: {UIDeleteResource(); break; }
			case 5: {UISearch(); break; }
			case 6: {cout << "Logged out!" << endl; run = false; }
			case 0: {run = false; break; }
			}
		}
	}
	else {
		cout << endl;
		cout << "Access denied!" << endl;
		runUI();
	}
	cout << endl;
	cout << "1. Login" << endl;
	cout << "0. Exit" << endl;
	int opt;
	cout << "Option: "; cin >> opt;
	switch (opt) {
	case 1: {runUI(); }
	case 0: {break; }
	}
}


void UI::UIAddMaterialResource()
{
	cout << "Material resource name: ";
	string name;
	cin >> name;
	cout << "Date: ";
	string date;
	cin >> date;
	double value;
	cout << "Value: ";
	cin >> value;
	int lifetime;
	cout << "Lifetime: ";
	cin >> lifetime;
	int pieces;
	cout << "Pieces: ";
	cin >> pieces;
	cin.ignore();
	try {
		this->s.addMaterialResource(name, date, value, lifetime, pieces);
	}
	catch (ValidatorException & ex) {
		cout << ex.what() << endl;
	}
	catch (RepoExc & e) {
		cout << e.what() << endl;
	}

}

void UI::UIAddFinancialResource()
{
	string name;
	cout << "Financial resource name: "; cin >> name;
	string date;
	cout << "Date: "; cin >> date;
	double value;
	cout << "Value: "; cin >> value;
	string currency;
	cout << "Currency: "; cin >> currency;
	try {
		this->s.addFinancialResource(name, date, value, currency);
	}
	catch (ValidatorException & e) {
		cout << e.what() << endl;
	}
	catch (RepoExc & e) {
		cout << e.what() << endl;
	}
}

void UI::UIDeleteResource()
{
	cout << "Give me the name of the resource for delete: "; 
	string name; cin >> name;
	try {
		this->s.deleteResource(name);
	}
	catch (RepoExc & e) {
		cout << e.what() << endl;
	}
}
