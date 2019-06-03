#pragma once

#include <QObject>
#include <QVector>
#include <QString>
#include "xlsxdocument.h"
#include "ExcelCell.h"

class QExcelReader : public QObject
{
	Q_OBJECT

		QString filePath;

		// Excel file with QXlsx document.
		QXlsx::Document *excelFile;

	// Vector for storing excel data.
	// excelData[sheet][row][column]
	// MAYBE SHOULD be replaced by object, using std::move() to pass out?
	QVector<QVector<QVector<ExcelCell>>> excelData;

	public slots:

	void extractDataOne();

	void extractDataTwo();

signals:
	// extractDataOne() will emit this signal
	// to inform that excel has been loaded
	void dataOneLoaded(QVector<QVector<QVector<ExcelCell>>>);

	// extractDataTwo() will emit this signal
	// to inform that excel has been loaded
	void dataTwoLoaded(QVector<QVector<QVector<ExcelCell>>>);

public:
	QExcelReader(QObject *parent);
	QExcelReader(QString filePath, QObject *parent);
	~QExcelReader();
};
