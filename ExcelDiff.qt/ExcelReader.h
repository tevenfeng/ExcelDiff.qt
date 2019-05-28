#pragma once

#include <vector>
#include <exception>
#include "xlsxdocument.h"

class ExcelReader
{
public:
	ExcelReader();
	ExcelReader(QXlsx::Document *excelFile);
	~ExcelReader();

	std::vector<std::vector<std::vector<std::string>>>* read();

	bool readSuccessful();

private:

	// Excel file with QXlsx document pointer.
	QXlsx::Document *excelFile = nullptr;

	// Vector for storing excel data.
	// excelData[sheet][row][column]
	std::vector<std::vector<std::vector<std::string>>> *excelData;

	bool isReadSuccessful;

	bool extractData();
};

