#pragma once
#include "Service.h"

class UI {
private:
	Service s;
public:
	UI();
	UI(Service& s);
	~UI();
	void UIAddMaterialResource();
	void UIAddFinancialResource();
	void UIDeleteResource();
	void showMenu();
	void UISearch();
	void UIModifyResource();
	void chooseFile();
	void runUI();
};