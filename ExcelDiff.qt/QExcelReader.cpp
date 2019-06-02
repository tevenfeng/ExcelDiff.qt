#include "QExcelReader.h"

QExcelReader::QExcelReader(QObject *parent)
	: QObject(parent)
{
}

QExcelReader::QExcelReader(QString filePath, QObject *parent)
	: QObject(parent)
{
	this->filePath = filePath;
}

QExcelReader::~QExcelReader()
{
	delete this->excelFile;
}

void QExcelReader::extractData()
{
	this->excelFile = new QXlsx::Document(filePath);

	// Assuming there's no problem with the excel file
	// Just read it.

	// Multiple sheets
	// excelData[sheet][row][column]
	this->excelData = QVector<QVector<QVector<ExcelCell>>>();

	// Get all sheets for iterating
	QStringList sheetNames = this->excelFile->sheetNames();

	// Iterating all sheets
	for (int i = 0; i < sheetNames.size(); ++i)
	{
		// Data from a single sheet
		QVector<QVector<ExcelCell>> sheetData = QVector<QVector<ExcelCell>>();

		// Read all cells in the sheet.
		this->excelFile->selectSheet(sheetNames[i]);
		QXlsx::Worksheet* wsheet = this->excelFile->currentWorksheet();
		int maxRow = -1;
		int maxCol = -1;
		QVector<QXlsx::CellLocation> clList = wsheet->getFullCells(&maxRow, &maxCol);

		// Iterating rows and columns
		int currentRow = 0; int currentCol = 0;
		QVector<ExcelCell> rowData = QVector<ExcelCell>();
		for each (QXlsx::CellLocation cellVar in clList)
		{
			if (currentRow < cellVar.row)
			{
				sheetData.push_back(rowData);
				currentRow++;
				currentCol = 0;
				rowData = QVector<ExcelCell>();
			}

			ExcelCell tmp = ExcelCell(cellVar.row,
				cellVar.col,
				cellVar.cell.data()->value().toString().toStdU16String());
			rowData.push_back(tmp);
		}
		// Finishing iterating a single sheet
		sheetData.push_back(rowData);

		this->excelData.push_back(sheetData);
	}

	emit dataLoaded(std::move(this->excelData));
}
