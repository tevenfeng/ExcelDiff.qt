#pragma once

#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QListview>
#include <QLineEdit>
#include <QProgressBar>
#include <QTimer>
#include <QFileDialog>
#include <QString>
#include <QTableWidget>
#include <QFileInfo>
#include <QMessageBox>
#include <QThread>
#include "xlsxdocument.h"

#include "ui_ExcelDiff.h"

#include "ExcelCell.h"
// #include "ExcelReader.h"
#include "QExcelReader.h"


class ExcelDiff : public QMainWindow
{
	Q_OBJECT

		public slots :

	void file1BtnClicked();

	void file2BtnClicked();

	void diffBtnClicked();

	void excelOneDataRecv(QVector<QVector<QVector<ExcelCell>>> excelOneData);

	void excelTwoDataRecv(QVector<QVector<QVector<ExcelCell>>> excelTwoData);

signals:
	void startReaderThread();

public:
	ExcelDiff(QWidget *parent = Q_NULLPTR);

private:
	Ui::ExcelDiffClass ui;
	QWidget *mainWidget;
	QGridLayout *mainLayout;

	QWidget *topWidget, *bottomWidget;
	QGridLayout *topLayout, *bottomLayout;

	QLineEdit *file1, *file2;
	QPushButton *file1Btn, *file2Btn, *diffBtn;
	QProgressBar *diffProgressBar;
	QBasicTimer *diffTimer;

	QWidget *leftWidget, *rightWidget;
	QGridLayout *leftLayout, *rightLayout;

	QTableWidget *tableWidget1, *tableWidget2, *detailTableWidget;
	QPushButton *rowBtn, *colBtn, *cellBtn, *clearHighlightBtn;

	QVector<QVector<QVector<ExcelCell>>> excelOneData, excelTwoData;

	QExcelReader *readerOne, *readerTwo;
	QThread *readerThread;

	void loadExcelFilesWithSeparateThread();

	void makeTop();
	void makeBottom();
	void makeLeft();
};
