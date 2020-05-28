#include "TestEconomicResource.h"
#include "EconomicResource.h"
#include "Utilities.h"
#include <assert.h>

void TestEconomicResource::testGetters()
{
	EconomicResource ec("economicresource", "02.02.2021", 50.5);
	assert(ec.getName() == "economicresource");
	assert(ec.getDate() == "02.02.2021");
	assert(ec.getValue() == 50.5);
}

void TestEconomicResource::testSetters()
{
	EconomicResource ec;
	ec.setName("resursa");
	ec.setDate("08.08.2020");
	ec.setValue(60.0);
	assert(ec.getDate() == "08.08.2020");
	assert(ec.getName() == "resursa");
	assert(ec.getValue() == 60.0);
}

void TestEconomicResource::testToString()
{
	EconomicResource ec("economicresource", "02.02.2021", 50.5);
	assert(ec.toString(" ") == "economicresource 02.02.2021 50.5");
	assert(ec.toString(",") == "economicresource,02.02.2021,50.5");
}

void TestEconomicResource::testClone()
{
	EconomicResource ec("economicresource", "02.02.2021", 50.1);
	EconomicResource* ecClone = ec.clone();
	assert(ec == *ecClone);
	assert(&ec != ecClone);
}

void TestEconomicResource::testAll()
{
	this->testGetters();
	this->testSetters();
	this->testToString();
	this->testClone();

}
