#pragma once

#include <QVector>
#include <exception>
#include "xlsxdocument.h"
#include "ExcelCell.h"

class ExcelReader
{
public:
	ExcelReader();
	ExcelReader(QString filePath);
	~ExcelReader();

	QVector<QVector<QVector<ExcelCell>>> read() const;

	bool readSuccessful();

private:

	// Excel file with QXlsx document.
	QXlsx::Document *excelFile;

	// Vector for storing excel data.
	// excelData[sheet][row][column]
	// MAYBE SHOULD be replaced by object, using std::move() to pass out?
	QVector<QVector<QVector<ExcelCell>>> excelData;

	bool isReadSuccessful;

	bool extractData();
};

