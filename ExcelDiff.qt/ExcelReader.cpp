#include "ExcelReader.h"



ExcelReader::ExcelReader()
{
}

ExcelReader::ExcelReader(QString filePath)
{
	this->excelFile = new QXlsx::Document(filePath);
	extractData();
}

ExcelReader::~ExcelReader()
{
	delete this->excelFile;
}

QVector<QVector<QVector<ExcelCell>>> ExcelReader::read() const
{
	return this->isReadSuccessful ? std::move(this->excelData) : QVector<QVector<QVector<ExcelCell>>>();
}

bool ExcelReader::readSuccessful()
{
	return this->isReadSuccessful;
}

bool ExcelReader::extractData()
{
	// Assuming there's no problem with the excel file
	// Just read it.

	// Multiple sheets
	// excelData[sheet][row][column]
	this->excelData = QVector<QVector<QVector<ExcelCell>>>();

	try {
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
			for (int i = 0; i < clList.size(); ++i)
            {
                if (currentRow < clList[i].row)
                {
                    sheetData.push_back(rowData);
                    currentRow++;
                    currentCol = 0;
                    rowData = QVector<ExcelCell>();
                }

                ExcelCell tmp = ExcelCell(clList[i].row,
                                          clList[i].col,
                                          clList[i].cell.data()->value().toString().toStdU16String());
                rowData.push_back(tmp);
            }
			// Finishing iterating a single sheet
			sheetData.push_back(rowData);

			this->excelData.push_back(sheetData);
		}

		this->isReadSuccessful = true;
		return true;
	}
	catch (std::exception& e)
	{
		this->isReadSuccessful = false;
		return false;
	}
}
