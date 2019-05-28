#include "ExcelReader.h"



ExcelReader::ExcelReader()
{
}

ExcelReader::ExcelReader(QXlsx::Document * excelFile)
{
	this->excelFile = excelFile;
	extractData();
}

ExcelReader::~ExcelReader()
{
	delete this->excelData;
	delete this->excelFile;
}

std::vector<std::vector<std::vector<std::string>>>* ExcelReader::read()
{
	return this->isReadSuccessful ? this->excelData : NULL;
}

bool ExcelReader::readSuccessful()
{
	return this->isReadSuccessful;
}

bool ExcelReader::extractData()
{
	// Assuming there's no problem with the excel file
	// Just read it.

	this->excelData = new std::vector<std::vector<std::vector<std::string>>>();

	try {
		QStringList sheetNames = this->excelFile->sheetNames();
		for (int i = 0; i < sheetNames.size(); ++i)
		{
			this->excelFile->selectSheet(sheetNames[i]);
			this->excelFile->cellAt(1, 1);
		}

		this->isReadSuccessful = true;
	}
	catch (std::exception& e)
	{
		this->isReadSuccessful = false;
	}

	return this->isReadSuccessful;
}
