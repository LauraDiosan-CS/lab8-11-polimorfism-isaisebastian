#include "TestValidatorResource.h"
#include <cassert>
#include "ValidatorResource.h"
#include "ValidatorException.h"
#include "FinancialResource.h"
#include "MaterialResource.h"

void TestValidatorResource::testValidatorResource()
{
	ValidatorResource val;
	EconomicResource* ec1 = new EconomicResource("economic", "14.09.2021", 250.5);
	try {
		val.validate(ec1);
	}
	catch (...) {
		assert(false);
	}
	EconomicResource* ec2 = new EconomicResource("economic2", "5.10.2020", 300.2);
	try {
		val.validate(ec2);
		assert(true);
	}
	catch(ValidatorException& e){}
	catch (...) {
		assert(false);
	}
	EconomicResource* ec3 = new EconomicResource("neweconomic", "", 300.1);
	try {
		val.validate(ec3);
		assert(false);
	}
	catch(ValidatorException& e){}
	catch (...) {
		assert(false);
	}
	EconomicResource* ec4 = new EconomicResource("abc", "2", 205);
	try {
		val.validate(ec4);
	}
	catch (...)
	{
		assert(false);
	}
	delete ec1;
	delete ec2;
	delete ec3;
	delete ec4;
}

void TestValidatorResource::testValidatorFinancialResource()
{
	ValidatorResource val;
	FinancialResource* fr1 = new FinancialResource("abcc", "08.10.2020", 5.0, "ron");
	try {
		val.validate(fr1);
	}
	catch (...) {
		assert(false);
	}
	FinancialResource* fr2 = new FinancialResource("bcd", "10.07.2018", 60.5, "eur");
	try {
		val.validate(fr2);
		assert(true);
	}
	catch(ValidatorException& e){}
	catch (...) {
		assert(false);
	}
	delete fr1;
	delete fr2;
}

void TestValidatorResource::testValidatorMaterialResource()
{
	ValidatorResource val;
	MaterialResource* mr1 = new MaterialResource("sda", "2.11.2017", 700.5, 30, 20);
	try {
		val.validate(mr1);
	}
	catch (...) {
		assert(false);
	}
	MaterialResource* mr2 = new MaterialResource("info", "2.8.2020", -1, 7, 20);
	try {
		val.validate(mr2);
		assert(false);
	}
	catch(ValidatorException& e){}
	catch (...)
	{
		assert(false);
	}
	delete mr1;
	delete mr2;
}

TestValidatorResource::TestValidatorResource()
{
}

TestValidatorResource::~TestValidatorResource()
{
}

void TestValidatorResource::testAll()
{
	this->testValidatorFinancialResource();
	this->testValidatorMaterialResource();
	this->testValidatorResource();
}
