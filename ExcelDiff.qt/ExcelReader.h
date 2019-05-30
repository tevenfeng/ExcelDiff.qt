#pragma once

#include <QVector>
#include <exception>
#include "xlsxdocument.h"
#include "ExcelCell.h"

class ExcelReader
{
public:
	ExcelReader();
	ExcelReader(QXlsx::Document *excelFile);
	~ExcelReader();

	QVector<QVector<QVector<ExcelCell>>>* read();

	bool readSuccessful();

private:

	// Excel file with QXlsx document pointer.
	QXlsx::Document *excelFile = nullptr;

	// Vector for storing excel data.
	// excelData[sheet][row][column]
	QVector<QVector<QVector<ExcelCell>>>* excelData;

	bool isReadSuccessful;

	bool extractData();
};

